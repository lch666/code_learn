project(sort)
cmake_minimum_required(VERSION 3.16)

# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE Debug)
add_definitions(-DLCH_TEST)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(quick_sort)

set(SRC_FILE  ${PROJECT_SOURCE_DIR}/test_sort.cc)

add_executable(test_sort ${SRC_FILE})
target_link_libraries(test_sort quicksort)