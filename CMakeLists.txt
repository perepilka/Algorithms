cmake_minimum_required(VERSION 3.30)
project(Algorithms)

set(CMAKE_CXX_STANDARD 20)

include_directories(src/headers)

add_executable(Algorithms src/implementations/main.cpp
)
