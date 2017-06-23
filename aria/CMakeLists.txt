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


# base/thread sources
set(ARIA_BASE_THREAD_SOURCES
    base/thread/platform.h
    base/thread/thread.h
    base/thread/thread_posix.cc
    base/thread/thread_win.cc
    )
source_group(base\\\\thread FILES ${ARIA_BASE_THREAD_SOURCES})

set(ARIA_BASE_THREAD_TESTS
    base/thread/thread_test.cc
    )
source_group(base\\\\thread FILES ${ARIA_BASE_THREAD_TESTS})


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
    ${ARIA_BASE_THREAD_SOURCES}
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
    ${ARIA_BASE_THREAD_TESTS}
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
