cmake_minimum_required(VERSION 3.12)
project(cpp_programming)

set(CMAKE_CXX_STANDARD 20)
set(SHARED_H "${CMAKE_SOURCE_DIR}/include/shared")

include_directories(include)

add_subdirectory(src/exercises)
add_subdirectory(src/project)

add_executable(cpp_programming src/main.cpp)

target_link_libraries(cpp_programming PRIVATE exercises project)
