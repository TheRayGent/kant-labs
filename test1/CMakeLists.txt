cmake_minimum_required(VERSION 3.15)
project(test)

set(SFML_DIR "C:/sfml2/lib/cmake/SFML")

add_executable(test test.cpp)

find_package(SFML COMPONENTS network graphics window audio system CONFIG REQUIRED)

include_directories("C:/sfml2/include") 
target_link_libraries(test 
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
    )
