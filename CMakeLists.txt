cmake_minimum_required(VERSION 3.1)

project(tertis)

###############################################################################
# Build settings 
###############################################################################

# Ensure that Release builds include debug info.
set(CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo")
set_property(GLOBAL PROPERTY CMAKE_CXX_STANDARD 17)

set(SOURCES src/main.cpp
            src/Tertis.cpp
            src/Tertis.h
            src/VideoDisplay.h
            src/VideoDisplay.cpp
            src/GameState.h
            src/GameState.cpp)

add_executable(tertis ${SOURCES})
target_link_libraries(tertis optimized "${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv/lib/opencv_world411.lib")
target_link_libraries(tertis debug "${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv/lib/opencv_world411d.lib")
target_include_directories(tertis PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/deps/opencv/include")