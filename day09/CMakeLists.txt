cmake_minimum_required(VERSION 3.16)
project(day09)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(day09 main.cpp)