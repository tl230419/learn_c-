cmake_minimum_required(VERSION 3.16)
project(day10)

set(CMAKE_CXX_STANDARD 11)
set(AGE 18)

CONFIGURE_FILE(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_SOURCE_DIR}/config.h"
)

message(WARNING " 这是警告信息")
message(STATUS "这是正常输出")

set(AGE ${AGE} 19)
message(STATUS ${AGE})

add_definitions(-DALLEN)

include_directories("test")

#if (CMAKE_HOST_WIN32)
#    set(WINDOWS 1)
#elseif(CMAKE_HOST_APPLE)
#    set(MACOS 1)
#elseif(CMAKE_HOST_UNIX)
#    set(LINUX 1)
#endif()

#if (WINDOWS)
#    link_directories(${PROJECT_SOURCE_DIR}/lib)
#elseif(LINUX)
#    link_directories(${PROJECT_SOURCE_DIR}/lib)
#elseif(MACOS)
#    link_directories(${PROJECT_SOURCE_DIR}/lib)
##endif()

add_subdirectory(test)

#set(TEST_LIB ${PROJECT_SOURCE_DIR}/lib/libtest.dll)
find_library(TEST_LIB libtest HINTS ${PROJECT_SOURCE_DIR}/lib)

add_executable(day10 main.cpp)
#target_link_libraries(day10 test)
target_link_libraries(day10 ${TEST_LIB})