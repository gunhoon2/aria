// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_THREAD_PLATFORM_H_
#define ARIA_BASE_THREAD_PLATFORM_H_

#include "aria/base/platform.h"

#if defined(OS_POSIX)
#define ARIA_THREAD_PLATFORM_POSIX
#elif defined(OS_WIN)
#define ARIA_THREAD_PLATFORM_WIN
#else
#define ARIA_THREAD_PLATFORM_STD
#endif

#if defined(ARIA_THREAD_PLATFORM_POSIX)
#include <pthread.h>
#elif defined(ARIA_THREAD_PLATFORM_WIN)
#include <windows.h>
#elif defined(ARIA_THREAD_PLATFORM_STD)
#endif

namespace aria {

#if defined(ARIA_THREAD_PLATFORM_POSIX)
typedef pthread_t ThreadHandle;
#elif defined(ARIA_THREAD_PLATFORM_WIN)
typedef HANDLE ThreadHandle;
#elif defined(ARIA_THREAD_PLATFORM_STD)
#endif

}  // namespace aria

#endif  // ARIA_BASE_THREAD_PLATFORM_H_
