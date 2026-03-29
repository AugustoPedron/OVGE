# set required version
cmake_minimum_required(VERSION 3.30)

# set compiler
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
# set project name
project(OVGE VERSION 0.0.0.1)

# set build options
# set(CMAKE_CXX_FLAGS "-g")# debug mode
set(CMAKE_CXX_FLAGS "-O2 -march=native -std=c++26 -Wall")# release mode

# set include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#find all source files
file(GLOB SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# generate executables
add_executable(OVGE ${SRC_FILES})