#include <iostream>
#include <chrono>
#include <random>
#include "MyLinkedList.hpp"
#include "MyLinkedListTest.hpp"

void MyLinkedList_TestSuite()
{
#define MLL_SIZE 100000

    std::cout << "MyLinkedList tests with MLL_SIZE = " << MLL_SIZE << std::endl;
    MyLinkedList_Test1();
    MyLinkedList_Test2();
    MyLinkedList_Test3();
}

void MyLinkedList_Test1()
{
    MyLinkedList <int> temp(1);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < MLL_SIZE - 1; ++i)
    {
        temp.pushFront(i);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double, std::milli> result = finish - start;
    std::cout << "pushFront test completed in " << result.count() << "ms";
    std::cout << std::endl;
}

void MyLinkedList_Test2()
{
    MyLinkedList <int> temp(1);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < MLL_SIZE - 1; ++i)
    {
        temp.pushBack(i);
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double, std::milli> result = finish - start;
    std::cout << "pushBack test completed in " << result.count() << "ms";
    std::cout << std::endl;
}

void MyLinkedList_Test3()
{
    MyLinkedList <int> temp;
    for (int i = 0; i < MLL_SIZE; ++i)
    {
        temp.pushFront(i);
    }
    std::mt19937 engine(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution <int> distance(0, MLL_SIZE);
    auto start = std::chrono::high_resolution_clock::now();
    temp.insert(distance(engine), 42);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration <double, std::milli> result = finish - start;
    std::cout << "insert on random test completed in " << result.count() << "ms";
    std::cout << std::endl;
}
