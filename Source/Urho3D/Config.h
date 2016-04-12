// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// Check LICENSE for more informations.

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
