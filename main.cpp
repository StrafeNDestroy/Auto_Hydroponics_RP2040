// main loops
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#define I2C0_SCL_PIN 1
#define I2C0_SDA_PIN 0
#define BUAD_RATE 100000







int main()
{
    // Enable UART to terminal so we can print status output to serial terminal or UART Pins
    stdio_init_all();

}