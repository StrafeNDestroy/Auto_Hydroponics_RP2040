// main loopss
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "Headers/Atlas_Temp_Probe.h"
#include "pico/cyw43_arch.h" // part of netowkring library


#define I2C0_SCL_PIN 1
#define I2C0_SDA_PIN 0
#define BUAD_RATE 100000


int main()
{
    // Enable UART to terminal so we can print status output to serial terminal or UART Pins
    if(stdio_init_all())
    {
        printf("Stdio init failed!")
        return -1;
    }

    if (cyw43_arch_init()) 
    {
        printf("Wi-Fi init failed!");
        return -1;
    }

    // Initialize  I2C  HW Block 0(i2c0)
    i2c_init(i2c_default, BUAD_RATE);

    // Set Pin I2C Function
    gpio_set_function(I2C0_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C0_SCL_PIN, GPIO_FUNC_I2C);
    
    while(1)
    {
        
        ATLAS_TEMP_PROBE Atlas_Probe;
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(250);
        Atlas_Probe.Get_Current_Temp_Scale();
        Atlas_Probe.Get_Temperature_Reading();
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(250);
    }

    return 0;
}