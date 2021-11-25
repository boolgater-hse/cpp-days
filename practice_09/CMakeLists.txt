cmake_minimum_required(VERSION 3.20)
project(practice_09)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

set(SOURCE_FILES src/VectorTest.cpp src/MyLinkedList.cpp src/MyLinkedListTest.cpp)
set(HEADER_FILES include/VectorTest.hpp include/MyLinkedList.hpp include/MyLinkedListTest.hpp)

add_executable(practice_09 main.cpp ${SOURCE_FILES} ${HEADER_FILES})
