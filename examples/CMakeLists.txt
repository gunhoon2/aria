# Copyright (c) 2017, Gunhoon Lee (gunhoon@gmail.com)

######################################################################
# simple_example executable target
######################################################################

set(SIMPLE_TARGET simple_example)

add_executable(${SIMPLE_TARGET} simple_example.cc)

target_link_libraries(${SIMPLE_TARGET} aria)
