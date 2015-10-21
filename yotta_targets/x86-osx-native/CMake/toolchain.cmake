# Copyright (C) 2014 ARM Limited. All rights reserved. 

cmake_minimum_required(VERSION 2.8)

# native toolchain
set(CMAKE_OBJC_FLAGS "-fobjc-arc")

# check that we are actually running on OSX, if we're not then we may pull in
# incorrect dependencies.
if(NOT (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Darwin"))
    message(FATAL_ERROR "This OS X native target will not work on non-OS X platforms, use `yotta target` to set the target.")
endif()

