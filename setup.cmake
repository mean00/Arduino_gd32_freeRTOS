include_directories(${ARDUINO_GD32_FREERTOS}/)
include_directories(${ARDUINO_GD32_FREERTOS}/include)
include_directories(${ARDUINO_GD32_FREERTOS}/freeRTOS_extension)
include_directories(${ARDUINO_GD32_FREERTOS}/FreeRTOS)
include_directories(${ARDUINO_GD32_FREERTOS}/FreeRTOS/include)
#include_directories(${ARDUINO_GD32_FREERTOS}/FreeRTOS/portable/GCC/RISC-V)
include_directories(${ARDUINO_GD32_FREERTOS}/freeRTOS_extension/N200)
include_directories(${ARDUINO_GD32_FREERTOS}/Longduino_cmake/cores/arduino/)
include_directories(${ARDUINO_VARIANT})
include_directories(${ARDUINO_GD32_FREERTOS}/Longduino_cmake/cores/arduino/GD32VF103_Firmware_Library/GD32VF103_standard_peripheral)
include_directories(${ARDUINO_GD32_FREERTOS}/Longduino_cmake/cores/arduino/GD32VF103_Firmware_Library/GD32VF103_standard_peripheral/Include)
include_directories(${ARDUINO_GD32_FREERTOS}/Longduino_cmake/cores/arduino/GD32VF103_Firmware_Library/RISCV/drivers)


include( ${ARDUINO_GD32_FREERTOS}/cmake/lnCmake.cmake)
