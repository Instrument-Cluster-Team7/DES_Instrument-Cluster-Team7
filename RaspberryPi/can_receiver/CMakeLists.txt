cmake_minimum_required(VERSION 3.10)

project(can_receiver)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(can_receiver can_receiver.cpp)
