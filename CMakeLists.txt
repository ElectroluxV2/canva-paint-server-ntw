cmake_minimum_required(VERSION 3.17)
project(canvaPaintServer)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 20)

configure_file(tester.html ${CMAKE_CURRENT_BINARY_DIR}/bin/www/tester.html COPYONLY)

add_executable(canvaPaintServer src/main.cpp src/server.cpp src/headers/server.h src/webSocketHandler.cpp src/headers/webSocketHandler.h src/asioService.cpp src/headers/asioService.h)
target_link_libraries(canvaPaintServer ${CONAN_LIBS})