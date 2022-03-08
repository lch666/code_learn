project(demo)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR})

set(SRC_FILE  ${PROJECT_SOURCE_DIR}/demo.cc)
set(SRC_FILE_TEST  ${PROJECT_SOURCE_DIR}/observer.cc
                   ${PROJECT_SOURCE_DIR}/main.cc)

add_executable(demo ${SRC_FILE})
add_executable(test ${SRC_FILE_TEST})