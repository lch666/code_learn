project(singleton)
cmake_minimum_required(VERSION 3.16)

include_directories(${PROJECT_SOURCE_DIR})

set(SRC_SINGLETON ${PROJECT_SOURCE_DIR}/singleton.cc)
set(SRC_SINGLETON_EASY ${PROJECT_SOURCE_DIR}/singleton_easy.cc)
set(SRC_SINGLETON_SAFE ${PROJECT_SOURCE_DIR}/singleton_safe.cc)

add_executable(test_singleton_demo ${SRC_SINGLETON})
add_executable(test_singleton_easy ${SRC_SINGLETON_EASY})
add_executable(test_singleton_safe ${SRC_SINGLETON_SAFE})

target_link_libraries(test_singleton_demo pthread)
target_link_libraries(test_singleton_easy pthread)
target_link_libraries(test_singleton_safe pthread)