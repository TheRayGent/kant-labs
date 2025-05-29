cmake_minimum_required(VERSION 3.15)
project(test)

set(path_to_sfml "C:/sfml2")

set(SFML_DIR "${path_to_sfml}/lib/cmake/SFML")

add_executable(test test.cpp)



#for sfml 2.6.2
find_package(SFML COMPONENTS network graphics window audio system CONFIG REQUIRED)

include_directories("C:/sfml2/include") 
target_link_libraries(test 
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
    )
