project(sort_library)
cmake_minimum_required(VERSION 3.16)

# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR})

set(SRC_FILE ${PROJECT_SOURCE_DIR}/quick_sort.cc
             ${PROJECT_SOURCE_DIR}/merge_sort.cc
             ${PROJECT_SOURCE_DIR}/heap_sort.cc)

add_library(shared_sort SHARED ${SRC_FILE})
add_library(static_sort STATIC ${SRC_FILE})