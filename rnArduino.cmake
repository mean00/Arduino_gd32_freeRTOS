IF(NOT DEFINED CORROSION_SET)
  SET(Rust_CARGO_TARGET "thumbv7m-none-eabi")
  find_package(Corrosion REQUIRED)
  SET(CORROSION_SET True CACHE INTERNAL "")
ENDIF(NOT DEFINED CORROSION_SET)
