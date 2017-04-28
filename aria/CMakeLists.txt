# Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

######################################################################
# Source list
######################################################################

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
