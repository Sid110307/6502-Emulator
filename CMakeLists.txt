cmake_minimum_required(VERSION 3.2)
project(6502)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(6502
        ${PROJECT_SOURCE_DIR}/main.cpp
        ${PROJECT_SOURCE_DIR}/cpu.cpp
        ${PROJECT_SOURCE_DIR}/memory.cpp
        ${PROJECT_SOURCE_DIR}/include/cpu.h
        ${PROJECT_SOURCE_DIR}/include/memory.h
        ${PROJECT_SOURCE_DIR}/include/utils.h)

target_compile_definitions(6502 PRIVATE -DPLATFORM_BIG_ENDIAN=${PLATFORM_BIG_ENDIAN})
