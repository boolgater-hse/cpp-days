#include <iostream>
#include "DynArray.hpp"

DynArray::DynArray(size_t n)
{
    data = new double[n];
    maxSize = n;
    alive++;
}

DynArray::DynArray(const DynArray& other)
{
    this->maxSize = other.maxSize;
    this->data = new double[maxSize];

    for (size_t i = 0; i < other.maxSize; ++i)
    {
        this->data[i] = other.data[i];
    }
    alive++;
}

DynArray& DynArray::operator=(const DynArray& other)
{
    this->maxSize = other.maxSize;
    if (this->data != nullptr && this->data != other.data)
    {
        delete[] this->data;
    }
    if (this->data != other.data)
    {
        this->data = new double[other.maxSize];
    }
    for (size_t i = 0; i < other.maxSize; ++i)
    {
        this->data[i] = other.data[i];
    }

    return *this;
}

double& DynArray::operator[](size_t index) const
{
    return data[index];
}

size_t DynArray::size()
{
    return this->maxSize;
}

DynArray& DynArray::operator+(const DynArray& other)
{
    size_t newSize = this->maxSize + other.maxSize;
    double* temp = new double[newSize];

    size_t counter = 0;
    for (size_t i = 0; i < this->maxSize; ++i)
    {
        temp[i] = this->data[i];
        counter++;
    }
    for (size_t i = 0; i < other.maxSize; ++i)
    {
        temp[counter + i] = other[i];
    }

    if (this->data != nullptr)
    {
        delete[] data;
    }

    data = new double[newSize];
    memcpy(data, temp, newSize * sizeof(double));
    this->maxSize = newSize;
    delete[] temp;

    return *this;
}

DynArray& DynArray::operator<<(int d)
{
    for (int i = 0; i < d; ++i)
    {
        double first = this->data[0];
        for (int j = 0; j < this->maxSize - 1; ++j)
        {
            this->data[j] = this->data[j + 1];
        }
        this->data[this->maxSize - 1] = first;
    }

    return *this;
}

DynArray& DynArray::operator>>(int d)
{
    for (int i = 0; i < d; ++i)
    {
        double last = this->data[this->maxSize - 1];
        for (int j = this->maxSize - 1; j >= 1; --j)
        {
            this->data[j] = this->data[j - 1];
        }
        this->data[0] = last;
    }

    return *this;
}

DynArray::~DynArray()
{
    delete[] data;
}

int DynArray::alive = 0;
