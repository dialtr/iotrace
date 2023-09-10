cmake_minimum_required(VERSION 3.25)
project(iotrace)

set(CMAKE_CXX_STANDARD 17)

add_library(iotrace SHARED src/iohooks.cc include/iohooks.h)

target_include_directories(iotrace PRIVATE include)
target_link_libraries(iotrace dl)