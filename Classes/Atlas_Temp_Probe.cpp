#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "../Headers/Atlas_Temp_Probe.h"

#define I2C0_SCL_PIN 1
#define I2C0_SDA_PIN 0
#define BUAD_RATE 100000 
#define RZO_ADDRESS static_cast<uint8_t>(0x66)
#define i2c0   (&i2c0_inst)



void ATLAS_TEMP_PROBE::Get_Current_Temp_Scale()
{

    int reponse_time_ms = 300;
    const uint8_t command[4] = {"S,?"};
    size_t data_size = 5; // Response BYTE + ?S,f
    size_t command_size_byte = sizeof(command)/sizeof(command[0]);


    i2c_write_blocking(i2c0,RZO_ADDRESS,command,command_size_byte,false);
    sleep_ms(600);
    i2c_read_blocking(i2c0,RZO_ADDRESS,rx_data_buff,data_size,false);


  // Checking EZO_RTD Response Codes
    switch (rx_data_buff[0])
    {
    case 1:
        printf("-------------------------\n");
        printf("Response Code: Succecssful Request!\n");
        break;
    case 2:
        printf("-------------------------\n");
        printf("Response Code: Syntax Error!\n");
    case 254:
        printf("-------------------------\n");
        printf("Response Code: Still processing,not ready!\n");
        break;
    case 255:
        printf("-------------------------\n");
        printf("Response Code: No data to send!\n");
        break;
    default:
        break;
    }

        printf("Current temperatrue scale is: %c\n",rx_data_buff[4]);
        current_temperature = rx_data_buff[4];
        
}



void ATLAS_TEMP_PROBE::Get_Temperature_Reading()
{
    char temp_reading[7];
    int reponse_time_ms = 600;
    const uint8_t command[2] = {"r"};
    size_t data_size = 7; // Response BYTE + 25.656
    size_t command_size_byte = sizeof(command)/sizeof(command[0]);

    i2c_write_blocking(i2c0,RZO_ADDRESS,command,command_size_byte,false);
    sleep_ms(600);
    i2c_read_blocking(i2c0,RZO_ADDRESS,rx_data_buff,data_size,false);

    // Checking EZO_RTD Response Codes
    switch (rx_data_buff[0])
    {
    case 1:
        printf("-------------------------\n");
        printf("Response Code: Succecssful Request!\n");
        break;
    case 2:
        printf("-------------------------\n");
        printf("Response Code: Syntax Error!\n");
    case 254:
        printf("-------------------------\n");
        printf("Response Code: Still processing,not ready!\n");
        break;
    case 255:
        printf("-------------------------\n");
        printf("Response Code: No data to send!\n");
        break;
    default:
        break;
    }

    // Converting data from rx_data_buff[1-6] to temp string
    for(int i = 0; i < 6; ++i) 
    {
        temp_reading[i] = rx_data_buff[i + 1]; 
    }
    temp_reading[6] = '\0'; // Added null terminator

    printf("Current Temperature: %s \u00B0%c\n",temp_reading,current_temperature);
    printf("-------------------------\n");
    

}

       


