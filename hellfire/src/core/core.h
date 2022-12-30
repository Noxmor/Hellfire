#ifndef HF_CORE_H
#define HF_CORE_H

#include "core/log.h"

typedef float f32;
typedef double f64;

typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef unsigned char b8;
typedef unsigned int b32;

#define HF_TRUE 1
#define HF_FALSE 0

#if defined(__clang__) || defined(__GNUC__)
#define HF_STATIC_ASSERT(condition, message) _Static_assert(condition, message)
#else
#define HF_STATIC_ASSERT(condition, message) static_assert(condition, message)
#endif

#ifdef HF_ENABLE_ASSERTS
#ifdef _MSC_VER
#include <intrin.h>
#define HF_DEBUGBREAK() __debugbreak()
#else
#define HF_DEBUGBREAK() __builtin_trap()
#endif
#define HF_CORE_ASSERT(x) if(!(x)) { HF_CORE_FATAL("Assertion failed at %s:%d: \"%s\"", __FILE__, __LINE__, #x); HF_DEBUGBREAK(); }
#define HF_ASSERT(x) if(!(x)) { HF_FATAL("Assertion failed at %s:%d: \"%s\"", __FILE__, __LINE__, #x); HF_DEBUGBREAK(); }
#else
#define HF_ASSERT(x)
#endif

HF_STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to have a size of 4 bytes!");
HF_STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to have a size of 8 bytes!");

HF_STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to have a size of 1 byte!");
HF_STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to have a size of 2 bytes!");
HF_STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to have a size of 4 bytes!");
HF_STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to have a size of 8 bytes!");

HF_STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to have a size of 1 byte!");
HF_STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to have a size of 2 bytes!");
HF_STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to have a size of 4 bytes!");
HF_STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to have a size of 8 bytes!");

HF_STATIC_ASSERT(sizeof(b8) == 1, "Expected f32 to have a size of 1 byte!");
HF_STATIC_ASSERT(sizeof(b32) == 4, "Expected f64 to have a size of 4 bytes!");

#endif