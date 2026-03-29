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

set(UCRT64_ROOT "C:\\Program Files\\MSYS2\\ucrt64")

add_library(Vulkan::Vulkan UNKNOWN IMPORTED)
set_target_properties(Vulkan::Vulkan PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${UCRT64_ROOT}/include"
    IMPORTED_LOCATION "${UCRT64_ROOT}/lib/libvulkan-1.dll.a"
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/external/glm)

# set include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include
                    ${UCRT64_ROOT}/include
)

#find all source files
file(GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

# generate executables
add_executable(OVGE ${SRC_FILES})

target_link_libraries(OVGE PRIVATE glfw
                                   glm
                                   Vulkan::Vulkan)
