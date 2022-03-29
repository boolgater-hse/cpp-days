cmake_minimum_required(VERSION 3.21)
project(cat)

set(CMAKE_CXX_STANDARD 17)

add_executable(cat main.cpp)
target_link_libraries(cat boost_program_options-mt) # MSYS MinGW
