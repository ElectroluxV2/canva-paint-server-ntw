cmake_minimum_required(VERSION 3.17)
project(canvaPaintServer)

set(CMAKE_CXX_STANDARD 20)

configure_file(tester.html ${CMAKE_CURRENT_BINARY_DIR}/bin/www/tester.html COPYONLY)

add_executable(canvaPaintServer src/main.cpp)