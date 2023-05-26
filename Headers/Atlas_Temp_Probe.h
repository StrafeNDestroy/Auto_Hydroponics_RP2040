#ifndef ATLASTEMPPROBE
#define ATLASTEMPPROBE
#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define I2C0_SCL_PIN 1
#define I2C0_SDA_PIN 0
#define BUAD_RATE 100000 
#define RZO_ADDRESS static_cast<u_int8_t>(0x66)


class ATLAS_TEMP_PROBE
{

    // Attributes 
    private: 
        char current_temperature;
        double farenheight;
        double celcius;
        uint8_t rx_data_buff[1+40];//1 for response code, 40 for largest string size 
        

    public:

        void Get_Current_Temp_Scale();
        void Get_Temperature_Reading();
};

#endif