#include <iostream>
#include <iomanip>
#include <fcntl.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <cstdint>

#define I2C_BUS "/dev/i2c-1"  // I2C bus on Raspberry Pi
#define INA219_ADDRESS 0x41   // INA219 I2C address

#define REG_BUS_VOLTAGE 0x02  // Bus Voltage Register
#define REG_CURRENT 0x04      // Current Register
#define REG_POWER 0x03        // Power Register

#define BATTERY_MAX 12.6
#define BATTERY_MIN 9

int i2c_file;

uint16_t read_register_2bytes(int file, uint8_t address, uint8_t reg) {
    uint8_t buf[2];

    if (ioctl(file, I2C_SLAVE, address) < 0) {
        std::cerr << "Failed to acquire bus access and/or talk to slave." << std::endl;
        return -1;
    }

    // Write register address to read from
    if (write(file, &reg, 1) != 1) {
        std::cerr << "Failed to write to the I2C bus." << std::endl;
        return -1;
    }

    // Read 2 bytes of data
    if (read(file, buf, 2) != 2) {
        std::cerr << "Failed to read from the I2C bus." << std::endl;
        return -1;
    }

    // Combine the 2 bytes into a 16-bit value (swapped endianness)
    return (buf[0] << 8) | buf[1];
}

float read_voltage() {
    uint16_t raw_voltage = read_register_2bytes(i2c_file, INA219_ADDRESS, REG_BUS_VOLTAGE);
    if (raw_voltage != (uint16_t)-1) {
        // Voltage is measured in 4mV units
        return ((raw_voltage >> 3) * 0.004);  // 4mV LSB
    }
    return -1;
}

float read_current() {
    uint16_t raw_current = read_register_2bytes(i2c_file, INA219_ADDRESS, REG_CURRENT);
    if (raw_current != (uint16_t)-1) {
        // Current conversion factor is device-dependent, example uses 1mA LSB
        return (raw_current * 0.001);  // 1mA LSB
    }
    return -1;
}

float read_power() {
    uint16_t raw_power = read_register_2bytes(i2c_file, INA219_ADDRESS, REG_POWER);
    if (raw_power != (uint16_t)-1) {
        return (raw_power * 0.02);  // Power in 20mW units
    }
    return -1;
}

float battery_percentage(float voltage){
    voltage = (voltage >= BATTERY_MAX) ? BATTERY_MAX : voltage;
    voltage = (voltage <= BATTERY_MIN) ? BATTERY_MIN : voltage;

    return (voltage - BATTERY_MIN) / (BATTERY_MAX - BATTERY_MIN);
}

void print_battery_data() {
    float voltage = read_voltage();

    if (voltage != -1) {
        std::cout << "Battery Voltage: " << std::fixed << std::setprecision(3) << battery_percentage(read_voltage()) << " V" << std::endl;
    } else {
        std::cout << "Failed to read voltage." << std::endl;
    }
}

int main() {
    // Open the I2C bus
    i2c_file = open(I2C_BUS, O_RDWR);
    if (i2c_file < 0) {
        std::cerr << "Failed to open the I2C bus." << std::endl;
        return 1;
    }

    try {
        while (true) {
            print_battery_data();
            sleep(1);  // Delay 1 second
        }
    } catch (...) {
        std::cerr << "Program interrupted." << std::endl;
    }

    close(i2c_file);
    return 0;
}