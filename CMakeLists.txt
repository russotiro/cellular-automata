cmake_minimum_required(VERSION 3.17)
project(cellular_automata)

set(CMAKE_CXX_STANDARD 20)

add_executable(cellular_automata main.cpp Elementary_CA.cpp Elementary_CA.h Color_CA.cpp Color_CA.h)