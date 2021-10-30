cmake_minimum_required(VERSION 3.20)
project(practice_06)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

add_executable(practice_06 main.cpp include/DynArray.hpp src/DynArray.cpp include/Queue.hpp src/Queue.cpp include/VecND.hpp src/VecND.cpp include/Mat2D.hpp src/Mat2D.cpp
        include/SLAE.hpp src/SLAE.cpp)
