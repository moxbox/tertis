cmake_minimum_required(VERSION 3.1)

project(tertis)

###############################################################################
# Build settings 
###############################################################################

# Ensure that Release builds include debug info.
set(CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo")
set_property(GLOBAL PROPERTY CMAKE_CXX_STANDARD 17)

set(SOURCES src/main.cpp)

add_executable(tertis ${SOURCES})