cmake_minimum_required(VERSION 3.17)
project(canvaPaintServer)

set(CMAKE_CXX_STANDARD 20)
set(CONAN_CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

configure_file(tester.html ${CMAKE_CURRENT_BINARY_DIR}/bin/www/tester.html COPYONLY)

add_executable(canvaPaintServer src/main.cpp)
target_link_libraries(canvaPaintServer ${CONAN_LIBS})
