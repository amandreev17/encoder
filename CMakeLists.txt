cmake_minimum_required(VERSION 3.4)
project(encoder)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(GLOB SRC_SRC "sources/encoder.cpp")

add_executable(encoder sources/encoder.cpp)