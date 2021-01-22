cmake_minimum_required(VERSION 3.17)
project(canvaPaintServer)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 20)

add_executable(canvaPaintServer main.cpp)
target_link_libraries(canvaPaintServer ${CONAN_LIBS})