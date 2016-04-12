// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#pragma once

/// Clockwork Engine version
#define CW_VERSION_MAJOR 0
#define CW_VERSION_MINOR 1
#define CW_VERSION_PATCH 0
#define CW_VERSION       (CW_VERSION_MAJOR * 10000 + CW_VERSION_MINOR * 100 + CW_VERSION_PATCH)

/// Detect current compiler
#if defined(__clang__)
#   define CW_COMPILER_STR "Clang"
#   define CW_COMPILER_CLANG (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#elif defined(_MSC_VER)
#   define CW_COMPILER_STR "Microsoft Visual C++"
#   define CW_COMPILER_MSVC _MSC_VER
#elif defined(__GNUC__)
#   define CW_COMPILER_STR "GNU GCC"
#   define CW_COMPILER_GCC (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
#else
#   error Unknown compiler
#endif

/// Detect current architecture
#if defined(__x86_64__) || defined(_M_X64)
#   define CW_ARCH_STR "AMD64"
#   define CW_ARCH_AMD64 1
#   define CW_ARCH_64BIT 1
#elif defined(__aarch64__)
#   define CW_ARCH_STR "ARM64"
#   define CW_ARCH_ARM64 1
#   define CW_ARCH_64BIT 1
#elif defined(__i386) || defined(_M_IX86)
#   define CW_ARCH_STR "x86"
#   define CW_ARCH_X86 1
#   define CW_ARCH_32BIT 1
#elif defined(__arm__) || defined(_M_ARM)
#   define CW_ARCH_STR "ARM"
#   define CW_ARCH_ARM 1
#   define CW_ARCH_32BIT 1
#else
#   error Unknown architecture
#endif

/// Detect current platform
#if defined(_XBOX_ONE) && defined(_TITLE)
#   define CW_PLATFORM_STR "Xbox One"
#   define CW_PLATFORM_DURANGO 1
#elif defined(__ORBIS__) || defined(__PS4__)
#   define CW_PLATFORM_STR "PlayStation 4"
#   define CW_PLATFORM_ORBIS 1
#elif defined(__ANDROID__)
#   define CW_PLATFORM_STR "Android"
#   define CW_PLATFORM_ANDROID 1
#elif defined(__APPLE__) && defined(__MACH__)
#   if defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__) || defined(__IPHONE_OS_VERSION_MIN_REQUIRED)
#       define CW_PLATFORM_STR "iOS"
#       define CW_PLATFORM_IOS 1
#   else
#       define CW_PLATFORM_STR "Mac OS X"
#       define CW_PLATFORM_MACOSX 1
#   endif
#elif defined(_WIN32) && !defined(_XBOX) && !defined(_XBOX_VER) && !defined(__ANDROID__)
#   include <sdkddkver.h>
#   if defined(WINAPI_FAMILY)
#       include <winapifamily.h>
#       if WINAPI_FAMILY == WINAPI_PARTITION_APP || WINAPI_FAMILY == WINAPI_FAMILY_PC_APP || WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#           define CW_PLATFORM_STR "WinRT"
#           define CW_PLATFORM_WINRT 1
#       else
#           define CW_PLATFORM_STR "Win32"
#           define CW_PLATFORM_WIN32 1
#       endif
#   else
#       define CW_PLATFORM_STR "Win32"
#       define CW_PLATFORM_WIN32 1
#   endif
#elif defined(__linux__)
#   define CW_PLATFORM_STR "Linux"
#   define CW_PLATFORM_LINUX 1
#else
#   error Unknown platform
#endif
