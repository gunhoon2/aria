# Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

# The minimum required version of cmake for a project.
cmake_minimum_required(VERSION 3.0.2)

# The project name.
project(aria)

# Include config.cmake for common configurations
include("cmake/config.cmake")
# Include cmake module to download and configure Google Test.
include("cmake/googletest.cmake")

# Enable testing for current directory and below
# to be run by 'make test' or 'ctest'.
enable_testing()

# Add subdirectories to the build.
add_subdirectory(aria)
add_subdirectory(examples)

# Display configuration settings.
message(STATUS "***** CONFIGURATION INFOMATION *****")
message(STATUS "Platform:            ${CMAKE_SYSTEM}")
message(STATUS "Generator:           ${CMAKE_GENERATOR}")
message(STATUS "Build Type:          ${CMAKE_BUILD_TYPE}")
