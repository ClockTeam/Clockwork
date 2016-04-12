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
