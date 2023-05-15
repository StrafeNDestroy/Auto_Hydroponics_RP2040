 #include "hardware/i2c.h
 #include "pico/stdlib.h"
 
 void I2C_Init()
        {
            i2c_init(i2c_default, 100 * 1000);
            gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
            gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
            gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
            gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
        }

void I2C_Bus_Scan()
    {

    }