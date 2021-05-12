
SET(LONGDUINO ${ARDUINO_GD32_FREERTOS}/legacy/ CACHE INTERNAL "")


# Generate runtime libraries
SET(GD32_ROOT_SRC ${LONGDUINO}/GD32VF103_Firmware_Library)

SET(GD32_RISC ${GD32_ROOT_SRC}/RISCV)
include_directories( ${GD32_RISC}/drivers)
SET(RISC_SRC ${GD32_RISC}/drivers/n200_func.c)


SET(GD32_STD ${GD32_ROOT_SRC}/GD32VF103_standard_peripheral)
include_directories( ${GD32_STD})
include_directories( ${GD32_STD}/Include)

foreach(periph gd32vf103_adc.c   gd32vf103_can.c   gd32vf103_dac.c  
               #gd32vf103_dma.c   gd32vf103_spi.c   gd32vf103_usart.c  
               gd32vf103_exmc.c  gd32vf103_fmc.c   gd32vf103_gpio.c  
               gd32vf103_pmu.c   gd32vf103_rtc.c   gd32vf103_timer.c  gd32vf103_wwdgt.c gd32vf103_bkp.c  gd32vf103_crc.c  gd32vf103_dbg.c  
               gd32vf103_eclic.c gd32vf103_exti.c  gd32vf103_fwdgt.c  gd32vf103_i2c.c   gd32vf103_rcu.c                
            )
    LIST(APPEND GD32_MAIN ${GD32_STD}/Source/${periph})
endforeach()
#MESSAGE(STATUS "Peripherals : ${p}")
    
foreach(sys system_gd32vf103.c)   
     LIST(APPEND GD32_MAIN ${GD32_STD}/${sys})
endforeach(sys system_gd32vf103.c)   

ADD_LIBRARY(gd32 STATIC  ${GD32_MAIN} ${GD32_STUBS} ${RISC_SRC}  entry.S start.S)


