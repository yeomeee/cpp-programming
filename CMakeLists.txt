cmake_minimum_required(VERSION 3.12)
project(cpp_programming)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES "src/*.cpp")
include_directories(include)

add_executable(cpp_programming ${SOURCES})
