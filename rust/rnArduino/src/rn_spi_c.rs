#![allow(dead_code)]
/* automatically generated by rust-bindgen 0.64.0 */

pub const __bool_true_false_are_defined: u32 = 1;
pub const _NEWLIB_VERSION_H__: u32 = 1;
pub const _NEWLIB_VERSION: &[u8; 6usize] = b"4.3.0\0";
pub const __NEWLIB__: u32 = 4;
pub const __NEWLIB_MINOR__: u32 = 3;
pub const __NEWLIB_PATCHLEVEL__: u32 = 0;
pub const _ATFILE_SOURCE: u32 = 1;
pub const _DEFAULT_SOURCE: u32 = 1;
pub const _ISOC99_SOURCE: u32 = 1;
pub const _ISOC11_SOURCE: u32 = 1;
pub const _POSIX_SOURCE: u32 = 1;
pub const _POSIX_C_SOURCE: u32 = 200809;
pub const _XOPEN_SOURCE: u32 = 700;
pub const _XOPEN_SOURCE_EXTENDED: u32 = 1;
pub const __ATFILE_VISIBLE: u32 = 1;
pub const __BSD_VISIBLE: u32 = 1;
pub const __GNU_VISIBLE: u32 = 1;
pub const __ISO_C_VISIBLE: u32 = 2011;
pub const __LARGEFILE_VISIBLE: u32 = 1;
pub const __MISC_VISIBLE: u32 = 1;
pub const __POSIX_VISIBLE: u32 = 200809;
pub const __SVID_VISIBLE: u32 = 1;
pub const __XSI_VISIBLE: u32 = 700;
pub const __SSP_FORTIFY_LEVEL: u32 = 0;
pub const __have_longlong64: u32 = 1;
pub const __have_long32: u32 = 1;
pub const ___int8_t_defined: u32 = 1;
pub const ___int16_t_defined: u32 = 1;
pub const ___int32_t_defined: u32 = 1;
pub const ___int64_t_defined: u32 = 1;
pub const ___int_least8_t_defined: u32 = 1;
pub const ___int_least16_t_defined: u32 = 1;
pub const ___int_least32_t_defined: u32 = 1;
pub const ___int_least64_t_defined: u32 = 1;
pub const __int20: u32 = 2;
pub const __int20__: u32 = 2;
pub const __INT8: &[u8; 3usize] = b"hh\0";
pub const __INT16: &[u8; 2usize] = b"h\0";
pub const __INT64: &[u8; 3usize] = b"ll\0";
pub const __FAST8: &[u8; 3usize] = b"hh\0";
pub const __FAST16: &[u8; 2usize] = b"h\0";
pub const __FAST64: &[u8; 3usize] = b"ll\0";
pub const __LEAST8: &[u8; 3usize] = b"hh\0";
pub const __LEAST16: &[u8; 2usize] = b"h\0";
pub const __LEAST64: &[u8; 3usize] = b"ll\0";
pub const __int8_t_defined: u32 = 1;
pub const __int16_t_defined: u32 = 1;
pub const __int32_t_defined: u32 = 1;
pub const __int64_t_defined: u32 = 1;
pub const __int_least8_t_defined: u32 = 1;
pub const __int_least16_t_defined: u32 = 1;
pub const __int_least32_t_defined: u32 = 1;
pub const __int_least64_t_defined: u32 = 1;
pub const __int_fast8_t_defined: u32 = 1;
pub const __int_fast16_t_defined: u32 = 1;
pub const __int_fast32_t_defined: u32 = 1;
pub const __int_fast64_t_defined: u32 = 1;
pub const WINT_MIN: u32 = 0;
pub const spiDataMode_SPI_MODE0: spiDataMode = 0;
pub const spiDataMode_SPI_MODE1: spiDataMode = 1;
pub const spiDataMode_SPI_MODE2: spiDataMode = 2;
pub const spiDataMode_SPI_MODE3: spiDataMode = 3;
pub type spiDataMode = cty::c_uint;
pub const spiBitOrder_SPI_LSBFIRST: spiBitOrder = 0;
pub const spiBitOrder_SPI_MSBFIRST: spiBitOrder = 1;
pub type spiBitOrder = cty::c_uint;
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct lnSPISettings {
    pub pinCS: cty::c_int,
    pub speed: cty::c_uint,
    pub bOrder: spiBitOrder,
    pub dMode: spiDataMode,
}
pub type lnSpiCallback = ::core::option::Option<unsafe extern "C" fn(cookie: *mut cty::c_void)>;
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct ln_spi_c {
    pub dummy: *mut cty::c_void,
}
extern "C" {
    #[link_name = "\u{1}_Z12lnspi_createii"]
    pub fn lnspi_create(instance: cty::c_int, pinCs: cty::c_int) -> *mut ln_spi_c;
}
extern "C" {
    #[link_name = "\u{1}_Z12lnspi_deleteP8ln_spi_c"]
    pub fn lnspi_delete(i2c: *mut ln_spi_c);
}
extern "C" {
    #[link_name = "\u{1}_Z11lnspi_beginP8ln_spi_cj"]
    pub fn lnspi_begin(instance: *mut ln_spi_c, dataSize: cty::c_uint);
}
extern "C" {
    #[link_name = "\u{1}_Z9lnspi_endP8ln_spi_c"]
    pub fn lnspi_end(instance: *mut ln_spi_c);
}
extern "C" {
    #[link_name = "\u{1}_Z19lnspi_set_bit_orderP8ln_spi_c11spiBitOrder"]
    pub fn lnspi_set_bit_order(instance: *mut ln_spi_c, order: spiBitOrder);
}
extern "C" {
    #[link_name = "\u{1}_Z19lnspi_set_data_modeP8ln_spi_c11spiDataMode"]
    pub fn lnspi_set_data_mode(instance: *mut ln_spi_c, datamode: spiDataMode);
}
extern "C" {
    #[link_name = "\u{1}_Z15lnspi_set_speedP8ln_spi_cj"]
    pub fn lnspi_set_speed(instance: *mut ln_spi_c, speed: cty::c_uint);
}
extern "C" {
    #[link_name = "\u{1}_Z14lnspi_set_sselP8ln_spi_ci"]
    pub fn lnspi_set_ssel(instance: *mut ln_spi_c, ssel: cty::c_int);
}
extern "C" {
    #[link_name = "\u{1}_Z9lnspi_setP8ln_spi_cRK13lnSPISettings"]
    pub fn lnspi_set(instance: *mut ln_spi_c, st: *const lnSPISettings);
}
extern "C" {
    #[link_name = "\u{1}_Z12lnspi_write8P8ln_spi_ch"]
    pub fn lnspi_write8(instance: *mut ln_spi_c, data: u8) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z13lnspi_write16P8ln_spi_ct"]
    pub fn lnspi_write16(instance: *mut ln_spi_c, data: u16) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z25lnspi_wait_for_completionP8ln_spi_ct"]
    pub fn lnspi_wait_for_completion(instance: *mut ln_spi_c, data: u16) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z26lnspi_block_write16_repeatP8ln_spi_cjt"]
    pub fn lnspi_block_write16_repeat(
        instance: *mut ln_spi_c,
        nbWord: cty::c_uint,
        data: u16,
    ) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z25lnspi_block_write8_repeatP8ln_spi_cjh"]
    pub fn lnspi_block_write8_repeat(
        instance: *mut ln_spi_c,
        nbByte: cty::c_uint,
        data: u8,
    ) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z19lnspi_block_write16P8ln_spi_cjPKt"]
    pub fn lnspi_block_write16(
        instance: *mut ln_spi_c,
        nbWord: cty::c_uint,
        data: *const u16,
    ) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z18lnspi_block_write8P8ln_spi_cjPKh"]
    pub fn lnspi_block_write8(
        instance: *mut ln_spi_c,
        nbByte: cty::c_uint,
        data: *const u8,
    ) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z17lnspi_asyncWrite8P8ln_spi_ciPKhPFvPvES3_b"]
    pub fn lnspi_asyncWrite8(
        instance: *mut ln_spi_c,
        nbBytes: cty::c_int,
        data: *const u8,
        cb: lnSpiCallback,
        cookie: *mut cty::c_void,
        repeat: bool,
    ) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z16lnspi_nextWrite8P8ln_spi_ciPKhPFvPvES3_b"]
    pub fn lnspi_nextWrite8(
        instance: *mut ln_spi_c,
        nbBytes: cty::c_int,
        data: *const u8,
        cb: lnSpiCallback,
        cookie: *mut cty::c_void,
        repeat: bool,
    ) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z18lnspi_asyncWrite16P8ln_spi_ciPKtPFvPvES3_b"]
    pub fn lnspi_asyncWrite16(
        instance: *mut ln_spi_c,
        nbWords: cty::c_int,
        data: *const u16,
        cb: lnSpiCallback,
        cookie: *mut cty::c_void,
        repeat: bool,
    ) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z17lnspi_nextWrite16P8ln_spi_ciPKtPFvPvES3_b"]
    pub fn lnspi_nextWrite16(
        instance: *mut ln_spi_c,
        nbWords: cty::c_int,
        data: *const u16,
        cb: lnSpiCallback,
        cookie: *mut cty::c_void,
        repeat: bool,
    ) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z20lnspi_finishAsyncDmaP8ln_spi_c"]
    pub fn lnspi_finishAsyncDma(instance: *mut ln_spi_c) -> bool;
}
extern "C" {
    #[link_name = "\u{1}_Z18lnspi_waitForAsyncP8ln_spi_c"]
    pub fn lnspi_waitForAsync(instance: *mut ln_spi_c) -> bool;
}
pub type __uint8_t = cty::c_uchar;
pub type __uint16_t = cty::c_ushort;
