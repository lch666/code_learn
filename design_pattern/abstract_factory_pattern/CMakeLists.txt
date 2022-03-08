project(demo)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR})

set(SRC_FILE  ${PROJECT_SOURCE_DIR}/demo.cc
              ${PROJECT_SOURCE_DIR}/product.cc
              ${PROJECT_SOURCE_DIR}/factory.cc)

add_executable(demo ${SRC_FILE})