If(NOT Rust_CARGO_TARGET)
    IF(LN_ARCH STREQUAL "RISCV") 
        IF(USE_HW_FPU)
                SET(Rust_CARGO_TARGET "${ARDUINO_GD32_FREERTOS}/mcus/riscv_ch32v3x/riscv32imacf-unknown-none-elf.json" CACHE INTERNAL "")
                SET(LN_RUST_BUILD_FLAGS  -Z build-std=core,alloc CACHE INTERNAL "")
                MESSAGE(STATUS "Disabling rust-lto for riscv32-imacf, expect big binaries")
                SET(LN_LTO_RUST_FLAGS "" CACHE INTERNAL "")
        ELSE()
                SET(Rust_CARGO_TARGET "riscv32imac-unknown-none-elf" CACHE INTERNAL "")
        ENDIF()
    ELSE()
       IF(LN_ARCH STREQUAL "ARM") 
            IF( "${LN_MCU}" STREQUAL "M4")
                    #SET(Rust_CARGO_TARGET "${ARDUINO_GD32_FREERTOS}/arm_gd32fx/thumbv7em-none-eabihf.json" CACHE INTERNAL "")
                #SET(LN_RUST_BUILD_FLAGS  -Z build-std=core,alloc CACHE INTERNAL "")
                SET(Rust_CARGO_TARGET "thumbv7em-none-eabihf" CACHE INTERNAL "")
            ELSEIF( "${LN_MCU}" STREQUAL "M3")
                    #SET(Rust_CARGO_TARGET "${ARDUINO_GD32_FREERTOS}/arm_gd32fx/thumbv7m-none-eabi.json" CACHE INTERNAL "")
                    #SET(LN_RUST_BUILD_FLAGS  -Z build-std=core,alloc CACHE INTERNAL "")
                    SET(Rust_CARGO_TARGET "thumbv7m-none-eabi" CACHE INTERNAL "")
            ELSEIF( "${LN_MCU}" STREQUAL "RP2040")
                    #SET(Rust_CARGO_TARGET "${ARDUINO_GD32_FREERTOS}/arm_gd32fx/thumbv7m-none-eabi.json" CACHE INTERNAL "")
                    #SET(LN_RUST_BUILD_FLAGS  -Z build-std=core,alloc CACHE INTERNAL "")
                    SET(Rust_CARGO_TARGET "thumbv6m-none-eabi" CACHE INTERNAL "")
            ENDIF()
       ELSE(LN_ARCH STREQUAL "ARM") 
                    SET(Rust_CARGO_TARGET "x86_64-unknown-linux-gnu"  CACHE INTERNAL "")
       ENDIF(LN_ARCH STREQUAL "ARM") 
    ENDIF()
    
    
ENDIF(NOT Rust_CARGO_TARGET)
#
MESSAGE(STATUS " Rust cargo target : ${Rust_CARGO_TARGET} (ARCH = ${LN_ARCH})")
#
ADD_SUBDIRECTORY(${ARDUINO_GD32_FREERTOS}/rust/corrosion corrosion)
#
#
MACRO(RUST_ADD tgt MANIFEST)
    corrosion_import_crate(MANIFEST_PATH ${MANIFEST} FLAGS "${LN_RUST_BUILD_FLAGS}")
    corrosion_add_target_rustflags(${tgt} "${LN_LTO_RUST_FLAGS}")
ENDMACRO(RUST_ADD MANIFEST)    
