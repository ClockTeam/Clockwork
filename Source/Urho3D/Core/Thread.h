// Copyright (c) 2016 Clockwork Engine. All Rights Reserved.
// See License.txt in the project root for license information.

#pragma once

#include "../Config.h"

#if defined(CW_PLATFORM_WIN32) || defined(CW_PLATFORM_WINRT)
#	include "Win32/Win32Condition.h"
#	include "Win32/Win32Mutex.h"
#	include "Win32/Win32Thread.h"
#elif defined(CW_PLATFORM_ANDROID) || defined(CW_PLATFORM_IOS) || defined(CW_PLATFORM_MACOSX) || defined(CW_PLATFORM_LINUX)
#	include "POSIX/POSIXCondition.h"
#	include "POSIX/POSIXMutex.h"
#	include "POSIX/POSIXThread.h"
#else
#	error "Not implemented"
#endif
