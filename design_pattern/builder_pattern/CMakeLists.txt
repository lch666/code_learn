project(builder_pattern)
cmake_minimum_required(VERSION 3.16)

set(CMAKE_BUILD_TYPE Release)

include_directories(${PROJECT_SOURCE_DIR})

set(SRC_FILE  ${PROJECT_SOURCE_DIR}/builder.cc
              ${PROJECT_SOURCE_DIR}/computer.cc
              ${PROJECT_SOURCE_DIR}/director.cc
              ${PROJECT_SOURCE_DIR}/main.cc)

add_executable(test_builder_demo ${SRC_FILE})