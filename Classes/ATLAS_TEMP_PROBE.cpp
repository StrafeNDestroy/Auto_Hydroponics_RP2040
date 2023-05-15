// Why use VOLATILE: 
    //By declaring a pointer as volatile, you inform the compiler that the memory location accessed through that pointer can change unexpectedly 
    //and should not be optimized or optimized in a specific way


#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
class ATLAS_TEMP_PROBE
{

    // Attributes 
    private: 
        double temperature;
        double farenheight;
        double celcius ;

    public:     
   



};