#include <iostream>
#include <string>
#include <vector>
#include "VectorTask.hpp"
#include "MyLinkedList.hpp"

void VectorTask_TestSuite();

void MyLinkedList_TestSuite();

int main()
{
    VectorTask_TestSuite();
    MyLinkedList_TestSuite();

    return 0;
}

void VectorTask_TestSuite()
{
    std::vector <int> a;

    srand(time(nullptr));
    for (int i = 0; i < 10; ++i)
    {
        a.push_back(rand() % 10);
    }

    std::cout << "Init vector:\n";
    printVector(a);
    std::cout << "Vector size: " << a.size() << '\n';
    std::cout << "Vector capacity: " << a.capacity() << "\n\n";
    std::cout << "Removed zeroes:\n";
    removeZeroes(a);
    printVector(a);
    std::cout << "Vector size: " << a.size() << '\n';
    std::cout << "Vector capacity: " << a.capacity() << "\n\n";
    std::cout << "Vector:\n";
    printVector(a);
    std::cout << "Equalize size and capacity:\n";
    equalizeSizeAndCapacity(a);
    std::cout << "Vector size: " << a.size() << '\n';
    std::cout << "Vector capacity: " << a.capacity() << "\n";
    std::cout << "Done\n\n";
}

void MyLinkedList_TestSuite()
{
    std::cout << "Default ctor creates one element -> ";
    MyLinkedList <int> llist_one;
    for (auto& it: llist_one)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    std::cout << "Defined number of elements ctor -> ";
    MyLinkedList <int> llist(5);
    for (auto& it: llist)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    std::cout << "Defined number of elements and value ctor -> ";
    MyLinkedList <int> llist_custom_value(5, 10);
    for (auto& it: llist_custom_value)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';

    std::cout << "std::string initialization -> ";
    std::string txt = "looks_like_a_std::string_initialization";
    MyLinkedList <char> llist_string = txt;
    for (auto& it: llist_string)
    {
        std::cout << it;
    }
    std::cout << '\n';

    std::cout << "std::string equating -> ";
    std::string txt2 = "yet_another_std::string";
    llist_string = txt2;
    for (auto& it: llist_string)
    {
        std::cout << it;
    }
    std::cout << '\n';

    std::cout << "std::initializer_list initialization -> ";
    MyLinkedList <int> llist_initializer_list = {1, 2, 3, 4, 5};
    for (auto& it: llist_initializer_list)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
    std::cout << '\n';

    std::cout << "Push front:\n";
    llist_initializer_list.pushFront(20);
    for (auto& it: llist_initializer_list)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
    std::cout << "Pop front:\n";
    std::cout << "Popped element is " << llist_initializer_list.popFront() << '\n';
    std::cout << "Current state:\n";
    for (auto& it: llist_initializer_list)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
    std::cout << "Push back:\n";
    llist_initializer_list.pushBack(30);
    for (auto& it: llist_initializer_list)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
    std::cout << "Pop back:\n";
    std::cout << "Popped element is " << llist_initializer_list.popBack() << '\n';
    std::cout << "Current state:\n";
    for (auto& it: llist_initializer_list)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
    std::cout << "Size: " << llist_initializer_list.getSize() << '\n';
    std::cout << '\n';

    std::cout << "Iterator class\n";
    std::cout << "for with iterators:\n";
    for (MyLinkedList <int>::Iterator it = llist_initializer_list.begin(); it != llist_initializer_list.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    std::cout << "range-based for:\n";
    for (auto& it: llist_initializer_list)
    {
        std::cout << it << ' ';
    }
    std::cout << '\n';
    std::cout << "Done\n";
}
