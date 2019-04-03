cmake_minimum_required (VERSION 3.0)

project (Animal_binary_tree)

set(HEADER_FILES bintree.h useful.h bt_class.h)
add_library(useful useful.cxx ${HEADER_FILES}) 
add_executable(animal animal.cxx ${HEADER_FILES})
add_executable(main main.cxx ${HEADER_FILES})
target_link_libraries(animal useful)
target_compile_options(animal PRIVATE -std=c++0x -g -Wall)
target_compile_options(main PRIVATE -std=c++0x -g -Wall)