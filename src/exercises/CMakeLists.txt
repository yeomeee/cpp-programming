file(GLOB EXERCISES_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(exercises STATIC ${EXERCISES_SRC})

target_include_directories(exercises PUBLIC ${CMAKE_SOURCE_DIR}/include/exercises ${SHARED_H})
