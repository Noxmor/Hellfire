#ifndef HF_PLATFORM_DETECTION_H
#define HF_PLATFORM_DETECTION_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define HF_PLATFORM_WINDOWS
#ifndef _WIN64
#error "Hellfire only supports 64-bit on Windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
#define HF_PLATFORM_LINUX
#if defined(__ANDROID__)
#define HF_PLATFORM_ANDROID
#endif
#elif defined(__unix__)
#define HF_PLATFORM_UNIX
#elif defined(_POSIX_VERSION)
#define HF_PLATFORM_POSIX
#elif __APPLE__
#define HF_PLATFORM_APPLE
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
#define HF_PLATFORM_IOS
#define HF_PLATFORM_IOS_SIMULATOR
#elif TARGET_OS_IPHONE
#define HF_PLATFORM_IOS
#elif TARGET_OS_MAC
#define HF_PLATFORM_MAC_OS
#else
#error "Unknown Apple platform!"
#endif
#else
#error "Unknown platform!"
#endif
#endif