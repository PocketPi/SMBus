#include "smbus.h"
#include <stddef.h>
#include <string.h>

// Global buffer for data read on the SMBUS
static uint8_t rx_data[SMBUS_MAX_READ_SIZE];

uint16_t smbus_read_word(uint8_t i2c_addr, uint8_t command_code) {
    uint8_t tx_data[] = {command_code};
    memset(rx_data, 0, SMBUS_MAX_READ_SIZE);

    i2c_transmit(i2c_addr, tx_data, sizeof(tx_data));
    i2c_recieve(i2c_addr, rx_data, 2);

    return (uint16_t)(rx_data[0] << 8 | rx_data[1]);
}

void smbus_write_word(uint8_t i2c_addr, uint8_t command_code, uint16_t data) {
    uint8_t tx_data[3] = {command_code, (uint8_t)(data >> 8), (uint8_t)(data & 0xff)};

    i2c_transmit(i2c_addr, tx_data, sizeof(tx_data));
}

void smbus_block_read(uint8_t i2c_addr, uint8_t command_code) {
    uint8_t tx_data[1] = {command_code};
    memset(rx_data, 0, SMBUS_MAX_READ_SIZE);

    i2c_transmit(i2c_addr, tx_data, sizeof(tx_data));
    i2c_recieve(i2c_addr, rx_data, SMBUS_MAX_READ_SIZE);
}

void smbus_block_write(uint8_t i2c_addr, uint8_t command_code, uint8_t *data, uint8_t count) {
    uint8_t tx_data[256] = {command_code, count};
    if (count < 256 - 2) {
        memcpy(&tx_data[2], data, count);
    } else {
        // Make sure we do not write out of bounce on the array
        return;
    }

    // Transmit count bytes + 2 for `command_code` and `count`
    i2c_transmit(i2c_addr, tx_data, count + 2);
}

uint8_t *get_rx_data() {
    return rx_data;
}