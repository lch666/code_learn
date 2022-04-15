project(quick_sort)
cmake_minimum_required(VERSION 3.16)

# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR})

set(SRC_FILE  ${PROJECT_SOURCE_DIR}/quick_sort.cc)

add_library(quicksort SHARED ${SRC_FILE})
add_library(quick STATIC ${SRC_FILE})