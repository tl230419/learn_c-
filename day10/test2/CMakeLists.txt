cmake_minimum_required(VERSION 3.16)

project(test2)

set(CMAKE_CXX_STANDARD 11)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../lib)

add_library(test2 SHARED test2.cpp)

