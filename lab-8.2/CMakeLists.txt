cmake_minimum_required(VERSION 3.15)
project(test)

add_executable(test main.cpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_CURRENT_BINARY_DIR}/Debug COPYONLY)