#ifndef SMBUS_H
#define SMBUS_H

#include <stdint.h>

#define SMBUS_MAX_READ_SIZE 32

/**
 * @brief Transmit function that sends data via the i2c bus
 *
 * @attention This function needs to be implemented by the user.
 *
 * @param i2c_addr I2C Address of the SMBus device
 * @param tx_data Pointer to array containing data to send
 * @param count Number of bytes to send
 */
void i2c_transmit(uint8_t i2c_addr, uint8_t *tx_data, uint8_t count);

/**
 * @brief Function needs to be implemented by the use. Transmit function that sends data via the i2c bus
 *
 * @attention This function needs to be implemented by the user.
 *
 * @param i2c_addr I2C Address of the SMBus device
 * @param tx_data Pointer to array containing data to send
 * @param count Number of bytes to send
 */
void i2c_recieve(uint8_t i2c_addr, uint8_t *rx_data, uint8_t count);

/**
 * @brief Read a SMBus word
 *
 * @param i2c_addr I2C Address of the SMBus device
 * @param command_code Command code or addres of the register to read from
 * @return uint16_t Data read from device
 */
uint16_t smbus_read_word(uint8_t i2c_addr, uint8_t command_code);

/**
 * @brief Write a SMBus word
 *
 * @param i2c_addr I2C Address of the SMBus device
 * @param command_code Command code or addres of the register to write to
 * @param data Data to send to device
 */
void smbus_write_word(uint8_t i2c_addr, uint8_t command_code, uint16_t data);

/**
 * @brief Read a block of SMBus data, data read to an internal buffer that can be accessed via 'get_rx_data();'
 *
 * @param i2c_addr I2C Address of the SMBus device
 * @param command_code Command code or addres of the register to read from
 */
void smbus_block_read(uint8_t i2c_addr, uint8_t command_code);

/**
 * @brief Write a block of SMBus data
 *
 * @param i2c_addr I2C Address of the SMBus device
 * @param command_code Command code or addres of the register to write to
 * @param data Data to send to device
 * @param count Number of bytes to send
 */
void smbus_block_write(uint8_t i2c_addr, uint8_t command_code, uint8_t *data, uint8_t count);

/**
 * @brief Get the rx data object populated when calling 'smbus_block_read()'
 *
 * @return uint8_t* Pointer to data array, max size = 'SMBUS_MAX_READ_SIZE'
 */
uint8_t *get_rx_data(void);

#endif