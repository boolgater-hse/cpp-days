#include <iostream>
#include "VectorTest.hpp"
#include "MyLinkedListTest.hpp"
// TODO: Galton board

int main()
{
    Vector_TestSuite();
    std::cout << std::endl;
    MyLinkedList_TestSuite();

    return 0;
}
