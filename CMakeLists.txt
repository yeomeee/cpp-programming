cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0167 OLD)

project(cpp_programming)

add_definitions(-D_WIN32_WINNT=0x0A00)

set(CMAKE_CXX_STANDARD 20)
set(SHARED_H "${CMAKE_SOURCE_DIR}/include/shared")

find_package(Boost REQUIRED COMPONENTS process)

include_directories(${Boost_INCLUDE_DIR} include)

add_subdirectory(src/exercises)
add_subdirectory(src/project)

add_executable(cpp_programming src/main.cpp)

target_link_libraries(cpp_programming PRIVATE Boost::process exercises project)
