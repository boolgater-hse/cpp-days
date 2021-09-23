#include <iostream>
#include "DynArray.hpp"


DynArray::DynArray(int n)
{
    a = new double[n];
    maxSize = n;
    ptr = 0;
}

void DynArray::append(int n)
{
    if (ptr == maxSize - 1)
    {
        this->resize();
    }
    a[ptr++] = n;
}

double DynArray::get(int i)
{
    return a[i];
}

int DynArray::size()
{
    return ptr;
}

void DynArray::resize()
{
    size_t newSize = maxSize * 2;
    auto* newA = new double[newSize];

    memcpy(newA, a, maxSize * sizeof(double));

    maxSize = newSize;
    delete[] a;
    a = newA;
}

DynArray::~DynArray()
{
    delete[] a;
}
