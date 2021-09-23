cmake_minimum_required(VERSION 3.20)
project(practice_03)

set(CMAKE_CXX_STANDARD 17)

add_executable(practice_03 main.cpp MyStack.cpp MyStack.hpp DynArray.cpp DynArray.hpp)
