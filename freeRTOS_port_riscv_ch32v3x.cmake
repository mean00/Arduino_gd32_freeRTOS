SET(FOS ${ARDUINO_GD32_FREERTOS}/FreeRTOS)
# Enable saving fpu regs ?
IF(USE_HW_FPU)
    ADD_DEFINITIONS("-DARCH_FPU=1")
else()
    ADD_DEFINITIONS("-DARCH_FPU=0")
ENDIF()
# WCH version
SET(LN_FREERTOS_PORT ${ARDUINO_GD32_FREERTOS}/riscv_ch32v3x/freeRTOS_extension/ CACHE INTERNAL "")
include_directories( ${LN_FREERTOS_PORT}/ )
include_directories( ${LN_FREERTOS_PORT}/chip_specific_extensions/RV32I_PFIC_no_extensions )
SET(LN_FREERTOS_PORT_SOURCES  ${LN_FREERTOS_PORT}/port.c ${LN_FREERTOS_PORT}/portASM.S   )


