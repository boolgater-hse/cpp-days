#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include "VectorTest.hpp"

void Vector_TestSuite()
{
#define VEC_SIZE 100000

    std::cout << "Vector tests with VEC_SIZE = " << VEC_SIZE << std::endl;
    Vector_Test1();
    Vector_Test2();
    Vector_Test3();
}

void Vector_Test1()
{
    std::vector <int> temp;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < VEC_SIZE; ++i)
    {
        temp.push_back(i);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double, std::milli> result = finish - start;
    std::cout << "push_back test completed in " << result.count() << "ms";
    std::cout << std::endl;
}

void Vector_Test2()
{
    std::vector <int> temp;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < VEC_SIZE; ++i)
    {
        temp.insert(temp.begin(), i);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double, std::milli> result = finish - start;
    std::cout << "insert test completed in " << result.count() << "ms";
    std::cout << std::endl;
}

void Vector_Test3()
{
    std::vector <int> temp;
    temp.reserve(VEC_SIZE + 1);
    for (int i = 0; i < VEC_SIZE; ++i)
    {
        temp.push_back(i);
    }
    std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution <int> distance(0, VEC_SIZE);
    auto start = std::chrono::high_resolution_clock::now();
    temp.insert(temp.begin() + distance(engine), 42);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double, std::milli> result = finish - start;
    std::cout << "insert on random test completed in " << result.count() << "ms";
    std::cout << std::endl;
}
