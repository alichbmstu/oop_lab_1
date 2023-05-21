cmake_minimum_required(VERSION 3.5)

project(oop_lab_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(oop_lab_1 main.cpp)

install(TARGETS oop_lab_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
