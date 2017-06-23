# Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

# The name of the OS that CMake is building for.
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
  set(OS_LINUX 1)
  set(OS_POSIX 1)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Darwin")
  set(OS_MACOSX 1)
  set(OS_POSIX 1)
elseif("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
  set(OS_WINDOWS 1)
endif()


# Specifies build types.
if(CMAKE_CONFIGURATION_TYPES)
  # the available build types on multi-config generators.
  set(CMAKE_CONFIGURATION_TYPES Debug Release)
else()
  # the build type on single-config generators.
  if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    message(STATUS "The default build is selected as ${CMAKE_BUILD_TYPE}")
  endif()
endif()


# Determine the target output directory.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>")


# Platform-specific compile/link options.
if(OS_LINUX)
  list(APPEND COMMON_COMPILE_OPTIONS
      -std=c++11                      # Use the C++11 language standard
      -Wall                           # Enable all warnings
      -Werror                         # Treat warnings as errors
      -pthread                        # Use the pthread library
      )
  list(APPEND COMMON_COMPILE_OPTIONS_DEBUG
      -O0                             # Disable optimizations
      -g                              # Generate debug information
      )
  list(APPEND COMMON_COMPILE_OPTIONS_RELEASE
      -O2                             # Optimize for maximum speed
      )
elseif(OS_MACOSX)
  list(APPEND COMMON_COMPILE_OPTIONS
      -std=c++11                      # Use the C++11 language standard
      -Wall                           # Enable all warnings
      -Werror                         # Treat warnings as errors
      -pthread                        # Use the pthread library
      )
  list(APPEND COMMON_COMPILE_OPTIONS_DEBUG
      -O0                             # Disable optimizations
      -g                              # Generate debug information
      )
  list(APPEND COMMON_COMPILE_OPTIONS_RELEASE
      -O2                             # Optimize for maximum speed
      )
elseif(OS_WINDOWS)
  list(APPEND COMMON_COMPILE_OPTIONS
      /W4                             # Warning level 4
      /WX                             # Treat warnings as errors
      )
  list(APPEND COMMON_COMPILE_OPTIONS_DEBUG
      /Od                             # Disable optimizations
      )
  list(APPEND COMMON_COMPILE_OPTIONS_RELEASE
      /O2                             # Optimize for maximum speed
      )
endif()

# Set compile/link options depending on configuration.
list(APPEND COMMON_COMPILE_OPTIONS
    $<$<CONFIG:Debug>:${COMMON_COMPILE_OPTIONS_DEBUG}>
    $<$<CONFIG:Release>:${COMMON_COMPILE_OPTIONS_RELEASE}>
    )
