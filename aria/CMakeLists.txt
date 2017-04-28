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
