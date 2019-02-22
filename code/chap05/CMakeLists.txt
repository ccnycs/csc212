cmake_minimum_required (VERSION 3.0)

project (Homework_Hello_World)

set(HEADER_FILES node1.h)
add_library(node node1.cxx ${HEADER_FILES}) 
add_executable(main main.cpp ${HEADER_FILES})
target_link_libraries(main node)
target_compile_options(main PRIVATE -std=c++0x -g -Wall)
