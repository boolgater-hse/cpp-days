cmake_minimum_required(VERSION 3.20)
project(practice_12)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCE_FILES main.cpp src/Graph.cpp)
set(HEADER_FILES include/Graph.hpp)

add_executable(practice_12 ${SOURCE_FILES} ${HEADER_FILES})
