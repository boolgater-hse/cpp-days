cmake_minimum_required(VERSION 3.21)
project(practice_15)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCE_FILES src/Shape.cpp src/Rectangle.cpp src/Circle.cpp src/Triangle.cpp)
set(HEADER_FILES include/Shape.hpp include/Rectangle.hpp include/Circle.hpp include/Triangle.hpp)

add_executable(practice_15 main.cpp ${SOURCE_FILES} ${HEADER_FILES})
