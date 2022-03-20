project(proxy)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR})

set(SRC_FILE  ${PROJECT_SOURCE_DIR}/proxy.cc)

add_executable(proxy ${SRC_FILE})