cmake_minimum_required(VERSION 3.20)
project(6502)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")

add_executable(6502 src/main.cpp src/cpu.cpp src/memory.cpp)
