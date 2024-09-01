cmake_minimum_required(VERSION 3.2)

enable_language(CXX)

project(CLIENT)
add_executable(CLIENT run_client.cpp  client.cpp client.hpp)

project(SERVER)
add_executable(SERVER run_server.cpp server.cpp server.hpp)