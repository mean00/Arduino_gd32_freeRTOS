#![allow(dead_code)]
/* automatically generated by rust-bindgen 0.64.0 */

pub const _NEWLIB_VERSION_H__: u32 = 1;
pub const _NEWLIB_VERSION: &[u8; 6usize] = b"4.3.0\0";
pub const __NEWLIB__: u32 = 4;
pub const __NEWLIB_MINOR__: u32 = 3;
pub const __NEWLIB_PATCHLEVEL__: u32 = 0;
pub const _DEFAULT_SOURCE: u32 = 1;
pub const _POSIX_SOURCE: u32 = 1;
pub const _POSIX_C_SOURCE: u32 = 200809;
pub const _ATFILE_SOURCE: u32 = 1;
pub const __ATFILE_VISIBLE: u32 = 1;
pub const __BSD_VISIBLE: u32 = 1;
pub const __GNU_VISIBLE: u32 = 0;
pub const __ISO_C_VISIBLE: u32 = 2011;
pub const __LARGEFILE_VISIBLE: u32 = 0;
pub const __MISC_VISIBLE: u32 = 1;
pub const __POSIX_VISIBLE: u32 = 200809;
pub const __SVID_VISIBLE: u32 = 1;
pub const __XSI_VISIBLE: u32 = 0;
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
pub type __int8_t = core::ffi::c_schar;
pub type __uint8_t = core::ffi::c_uchar;
pub type __int16_t = core::ffi::c_short;
pub type __uint16_t = core::ffi::c_ushort;
pub type __int32_t = core::ffi::c_int;
pub type __uint32_t = core::ffi::c_uint;
pub type __int64_t = core::ffi::c_longlong;
pub type __uint64_t = core::ffi::c_ulonglong;
pub type __int_least8_t = core::ffi::c_schar;
pub type __uint_least8_t = core::ffi::c_uchar;
pub type __int_least16_t = core::ffi::c_short;
pub type __uint_least16_t = core::ffi::c_ushort;
pub type __int_least32_t = core::ffi::c_int;
pub type __uint_least32_t = core::ffi::c_uint;
pub type __int_least64_t = core::ffi::c_longlong;
pub type __uint_least64_t = core::ffi::c_ulonglong;
pub type __intmax_t = core::ffi::c_longlong;
pub type __uintmax_t = core::ffi::c_ulonglong;
pub type __intptr_t = core::ffi::c_int;
pub type __uintptr_t = core::ffi::c_uint;
pub type intmax_t = __intmax_t;
pub type uintmax_t = __uintmax_t;
pub type int_least8_t = __int_least8_t;
pub type uint_least8_t = __uint_least8_t;
pub type int_least16_t = __int_least16_t;
pub type uint_least16_t = __uint_least16_t;
pub type int_least32_t = __int_least32_t;
pub type uint_least32_t = __uint_least32_t;
pub type int_least64_t = __int_least64_t;
pub type uint_least64_t = __uint_least64_t;
pub type int_fast8_t = core::ffi::c_schar;
pub type uint_fast8_t = core::ffi::c_uchar;
pub type int_fast16_t = core::ffi::c_short;
pub type uint_fast16_t = core::ffi::c_ushort;
pub type int_fast32_t = core::ffi::c_int;
pub type uint_fast32_t = core::ffi::c_uint;
pub type int_fast64_t = core::ffi::c_longlong;
pub type uint_fast64_t = core::ffi::c_ulonglong;
#[repr(C)]
#[derive(Debug, Copy, Clone)]
pub struct lncdc_c {
    pub dummy: *mut core::ffi::c_void,
}
pub type cdc_event_handler = ::core::option::Option<
    unsafe extern "C" fn(
        cookie: *mut core::ffi::c_void,
        interface: core::ffi::c_int,
        event: core::ffi::c_int,
        payload: core::ffi::c_uint,
    ),
>;
extern "C" {
    pub fn lncdc_create(instance: core::ffi::c_uint) -> *mut lncdc_c;
}
extern "C" {
    pub fn lncdc_delete(arg1: *mut lncdc_c);
}
extern "C" {
    pub fn lncdc_read(
        arg1: *mut lncdc_c,
        buffer: *mut u8,
        maxSize: core::ffi::c_int,
    ) -> core::ffi::c_int;
}
extern "C" {
    pub fn lncdc_write(
        arg1: *mut lncdc_c,
        buffer: *const u8,
        maxSize: core::ffi::c_int,
    ) -> core::ffi::c_int;
}
extern "C" {
    pub fn lncdc_flush(arg1: *mut lncdc_c);
}
extern "C" {
    pub fn lncdc_clear_input_buffers(arg1: *mut lncdc_c);
}
extern "C" {
    pub fn lncdc_set_event_handler(
        arg1: *mut lncdc_c,
        h: cdc_event_handler,
        cookie: *mut core::ffi::c_void,
    );
}
