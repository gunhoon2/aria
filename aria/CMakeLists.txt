# Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

######################################################################
# Source list
######################################################################

# base sources
set(ARIA_BASE_SOURCES
    base/logging.cc
    base/logging.h
    base/platform.h
    )
source_group(base FILES ${ARIA_BASE_SOURCES})

set(ARIA_BASE_TESTS
    base/logging_test.cc
    )
source_group(base FILES ${ARIA_BASE_TESTS})


# thread sources
set(ARIA_THREAD_SOURCES
    thread/condition_variable.h
    thread/condition_variable_posix.cc
    thread/condition_variable_win.cc
    thread/event.cc
    thread/event.h
    thread/event_win.cc
    thread/lock.h
    thread/mutex.h
    thread/mutex_posix.cc
    thread/mutex_win.cc
    thread/platform.h
    thread/recursive_mutex.h
    thread/recursive_mutex_posix.cc
    thread/recursive_mutex_win.cc
    thread/thread.h
    thread/thread_posix.cc
    thread/thread_win.cc
    )
source_group(thread FILES ${ARIA_THREAD_SOURCES})

set(ARIA_THREAD_TESTS
    thread/thread_test.cc
    )
source_group(thread FILES ${ARIA_THREAD_TESTS})


# time sources
set(ARIA_TIME_SOURCES
    time/steady_clock.cc
    time/steady_clock.h
    time/system_clock.cc
    time/system_clock.h
    time/time.h
    time/time_delta.h
    )
source_group(time FILES ${ARIA_TIME_SOURCES})


# examples sources
set(ARIA_EXAMPLES_SOURCES
    examples/bar.cc
    examples/bar.h
    examples/foo.cc
    examples/foo.h
    )
source_group(examples FILES ${ARIA_EXAMPLES_SOURCES})

set(ARIA_EXAMPLES_TESTS
    examples/foo_test.cc
    )
source_group(examples FILES ${ARIA_EXAMPLES_TESTS})


######################################################################
# Configuration
######################################################################

# all sources
set(ARIA_SOURCES
    ${ARIA_BASE_SOURCES}
    ${ARIA_THREAD_SOURCES}
    ${ARIA_TIME_SOURCES}
    ${ARIA_EXAMPLES_SOURCES}
    )

# target names
set(ARIA_TARGET aria)

# static library target
add_library(${ARIA_TARGET} STATIC ${ARIA_SOURCES})

# include directories
target_include_directories(${ARIA_TARGET} PUBLIC ${PROJECT_SOURCE_DIR})

# compile options
target_compile_options(${ARIA_TARGET} PRIVATE ${COMMON_COMPILE_OPTIONS})


######################################################################
# Configuration for unit tests
######################################################################

# all sources
set(TESTS_SOURCES
    ${ARIA_BASE_TESTS}
    ${ARIA_THREAD_TESTS}
    ${ARIA_EXAMPLES_TESTS}
    tests/test_main.cc
    )

# target names
set(TESTS_TARGET unittests)

# unittests executable target
add_executable(${TESTS_TARGET} ${TESTS_SOURCES})

# Add a test to the project to be run by ctest.
add_test(NAME ${TESTS_TARGET} COMMAND ${TESTS_TARGET})

# link libraries
target_link_libraries(${TESTS_TARGET} ${ARIA_TARGET})
target_link_libraries(${TESTS_TARGET} gtest gmock)

# compile options
target_compile_options(${TESTS_TARGET} PRIVATE ${COMMON_COMPILE_OPTIONS})
