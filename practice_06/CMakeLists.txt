cmake_minimum_required(VERSION 3.20)
project(practice_06)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)


include_directories(include)

set(SOURCE_FILES src/DynArray.cpp src/Queue.cpp src/VecND.cpp src/Mat2D.cpp src/SLAE.cpp)
set(HEADER_FILES include/DynArray.hpp include/Queue.hpp include/VecND.hpp include/Mat2D.hpp include/SLAE.hpp)

add_executable(practice_06 main.cpp ${SOURCE_FILES} ${HEADER_FILES})
