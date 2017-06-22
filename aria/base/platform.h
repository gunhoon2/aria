// Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

#ifndef ARIA_BASE_PLATFORM_H_
#define ARIA_BASE_PLATFORM_H_

#if defined(__linux__)
#define OS_LINUX
#elif defined(__APPLE__)
#define OS_MACOS
#elif defined(_WIN32)
#define OS_WIN
#else
#error This platform is NOT supported in base/platform.h
#endif

#if defined(OS_LINUX) || defined(OS_MACOS)
#define OS_POSIX
#endif

#endif  // ARIA_BASE_PLATFORM_H_
