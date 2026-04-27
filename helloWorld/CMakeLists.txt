cmake_minimum_required(VERSION 3.2)

enable_language(CXX)

project(HelloWorld)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

add_executable(HelloWorld main.cpp add.cpp)