#include <iostream>
#include "MyStack.hpp"


MyStack::MyStack(int n)
{
    data = new int[n + 1];
    ptr = 0;
    maxSize = n;
}

void MyStack::push(int n)
{
    if (ptr == maxSize - 1)
    {
        this->resize();
    }
    data[ptr++] = n;
}

int MyStack::peek()
{
    return data[ptr - 1];
}

int MyStack::pop()
{
    ptr--;
    return ptr + 1;
}

void MyStack::resize()
{
    size_t newSize = maxSize * 2;
    auto* newStack = new int[newSize];

    memcpy(newStack, data, maxSize * sizeof(int));

    maxSize = newSize;
    delete [] data;
    data = newStack;
}

int MyStack::size()
{
    return ptr;
}

MyStack::~MyStack()
{
    delete[] data;
}
