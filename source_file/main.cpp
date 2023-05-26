#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "Headers/Atlas_Temp_Probe.h"
#include "pico/cyw43_arch.h" 


#define I2C0_SCL_PIN 1
#define I2C0_SDA_PIN 0
#define BUAD_RATE 100000


int main()
{
// ######################## Enabling Pico Architecture ######################## 
    
    // Enable UART to terminal so we can print status output to serial terminal or UART Pins
    if(!stdio_init_all())
    {
        printf("stdio init failed!");
        return -1;
    }

    // Initialize  I2C  HW Block 0(i2c0)
    i2c_init(i2c_default, BUAD_RATE);
    
    // Initializ pico Wifi Chip
    if (cyw43_arch_init()) 
    {
        printf("cyw43 init failed!");
        return -1;
    }
    // Enable Chip to make connections to other Wi-Fi Access Points
    int enter;
    printf("Would you like to start enter 13:\n");
    scanf("%d",&enter);
    if(enter = 13)
    {
        printf("Starting\n");
    }

    cyw43_arch_enable_sta_mode();
    printf("Connecting to Wi-Fi...\n");

     if (cyw43_arch_wifi_connect_async(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK)) {
        printf("failed to connect.\n");
        return -1;
    } else {
        printf("Connected.\n");
    }
    


// ############################################################################

    // Set Pin I2C Function
    gpio_set_function(I2C0_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(I2C0_SCL_PIN, GPIO_FUNC_I2C);
    
    while(1)
    {    
        ATLAS_TEMP_PROBE Atlas_Probe;
        Atlas_Probe.Get_Temperature_Reading();      
    }

    return 0;
}