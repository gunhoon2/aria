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

#endif  // ARIA_BASE_THREAD_PLATFORM_H_