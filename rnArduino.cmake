IF(NOT DEFINED CORROSION_SET)
  IF(LN_ARCH STREQUAL "ARM")
    IF( "${LN_MCU}" STREQUAL "M4")
        SET(Rust_CARGO_TARGET "thumbv7em-none-eabihf")
    ELSE()
        SET(Rust_CARGO_TARGET "thumbv7m-none-eabi")
    ENDIF()
  ELSEIF(LN_ARCH STREQUAL "RISCV")
    SET(Rust_CARGO_TARGET "riscv32")
  ENDIF()
  find_package(Corrosion REQUIRED)
  SET(CORROSION_SET True CACHE INTERNAL "")
ENDIF(NOT DEFINED CORROSION_SET)
