cmake_minimum_required(VERSION 3.20)
project(practice_08)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCE_FILES src/VectorTask.cpp src/MyLinkedList.cpp)
set(HEADER_FILES include/VectorTask.hpp include/MyLinkedList.hpp)

add_executable(practice_08 main.cpp ${SOURCE_FILES} ${HEADER_FILES})
