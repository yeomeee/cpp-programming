file(GLOB PROJECT_SRC "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library(project STATIC ${PROJECT_SRC})

target_include_directories(project PUBLIC ${CMAKE_SOURCE_DIR}/include/project ${SHARED_H})