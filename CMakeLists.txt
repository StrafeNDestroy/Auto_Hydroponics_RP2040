cmake_minimum_required(VERSION 3.22.1)

# Include Build Functions from Pico SDK
include( ${CMAKE_CURRENT_LIST_DIR}/CMakefiles/pico_sdk_import.cmake)





project(Auto_Hydroponics)

# Creates a pico-sdk subdirectory in Project for Libraries
pico_sdk_init()

set(SOURCES
source_file/main.cpp
Classes/Atlas_Temp_Probe.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_compile_definitions(${PROJECT_NAME} PRIVATE
WIFI_SSID=\"${WIFI_SSID}\"
WIFI_PASSWORD=\"${WIFI_PASSWORD}\"
)

# Create map/bin/hex/uf2 files
pico_add_extra_outputs(${PROJECT_NAME})


target_include_directories(${PROJECT_NAME} PRIVATE 
${CMAKE_CURRENT_LIST_DIR}
${CMAKE_CURRENT_LIST_DIR}/Headers
)

# Link Library Dependecies
target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_i2c
    pico_cyw43_arch_lwip_threadsafe_background
)

# Enable USB Output
pico_enable_stdio_usb(${PROJECT_NAME} 1)

# Enable UART for Pico Debugger
pico_enable_stdio_uart(${PROJECT_NAME} 0)