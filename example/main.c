#include "smbus.h"
#include <stdint.h>
#include <stdio.h>

#define ADDR 0x12

void i2c_transmit(uint8_t i2c_addr, uint8_t *tx_data, uint8_t count) {
    printf("tx_data: ");
    for (size_t i = 0; i < count; i++) {
        printf("0x%02x ", tx_data[i]);
    }
    printf("\n\r");
};
void i2c_recieve(uint8_t i2c_addr, uint8_t *rx_data, uint8_t count) {
    for (size_t i = 0; i < count; i++) {
        rx_data[i] = i;
    }
};

int main(void) {
    uint16_t value = smbus_read_word(ADDR, 0x0D);
    printf("data: 0x%04x\n\r", value);

    smbus_write_word(ADDR, 0xFF, 0xABCD);
}