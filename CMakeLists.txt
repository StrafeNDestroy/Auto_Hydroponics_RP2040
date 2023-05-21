cmake_minimum_required(VERSION 3.22.1)

# Include Build Functions from Pico SDK
include(pico_sdk_import.cmake)




project(Auto_Hydroponics)

# Creates a pico-sdk subdirectory in Project for Libraries
pico_sdk_init()

add_executable(${PROJECT_NAME} main.cpp Classes/Atlas_Temp_Probe.cpp)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})

# Link Library Dependecies
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_i2c
    pico_cyw43_arch
)

# Enable USB Output
pico_enable_stdio_usb(${PROJECT_NAME} 1)

# Enable UART for Pico Debugger
pico_enable_stdio_uart(${PROJECT_NAME} 0)


