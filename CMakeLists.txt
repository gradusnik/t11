cmake_minimum_required(VERSION 3.24)
project(TestTask11)

set(CMAKE_CXX_STANDARD 17)

add_executable(TestTask11 main.cpp points.h curves.h points.cpp curves.cpp)
