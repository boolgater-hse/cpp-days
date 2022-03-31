#include <iostream>
#include "DynArray.hpp"

DynArray::DynArray(size_t n)
{
    this->data = std::make_unique <double[]>(n);
    this->maxSize = n;
    alive++;
}

DynArray::DynArray(const DynArray& other)
{
    this->maxSize = other.maxSize;
    this->data.reset(new double[maxSize]);

    for (size_t i = 0; i < other.maxSize; ++i)
    {
        this->data[i] = other.data[i];
    }
    alive++;
}

DynArray& DynArray::operator=(const DynArray& other)
{
    if (this->maxSize == other.maxSize)
    {
        for (size_t i = 0; i < other.maxSize; ++i)
        {
            this->data[i] = other.data[i];
        }
    }
    else
    {
        this->maxSize = other.maxSize;
        this->data.reset(new double[maxSize]);

        for (size_t i = 0; i < other.maxSize; ++i)
        {
            this->data[i] = other.data[i];
        }
    }

    return *this;
}

double& DynArray::operator[](size_t index) const
{
    return this->data.get()[index];
}

size_t DynArray::size() const
{
    return this->maxSize;
}

DynArray& DynArray::operator+(const DynArray& other)
{
    size_t newSize = this->maxSize + other.maxSize;
    std::unique_ptr <double[]> newData = std::make_unique <double[]>(newSize);

    int j = 0;
    for (int i = 0; i < this->maxSize; ++i, ++j)
    {
        newData[j] = this->data[i];
    }
    for (int i = 0; i < other.maxSize; ++i, ++j)
    {
        newData[j] = other.data[i];
    }

    this->data.reset(new double[newSize]);
    this->maxSize = newSize;
    for (int i = 0; i < maxSize; ++i)
    {
        data[i] = newData[i];
    }

    newData.reset();

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
        double last = this->data.get()[this->maxSize - 1];
        for (int j = this->maxSize - 1; j >= 1; --j)
        {
            this->data.get()[j] = this->data.get()[j - 1];
        }
        this->data.get()[0] = last;
    }

    return *this;
}

DynArray::~DynArray()
{
}

int DynArray::alive = 0;
