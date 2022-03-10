#include <iostream>
#include "VecND.hpp"

VecND::VecND(size_t n)
{
    data = std::make_unique <long double[]>(n);
    maxSize = n;
}

VecND::VecND(const VecND& other)
{
    this->maxSize = other.maxSize;
    data = std::make_unique <long double[]>(maxSize);

    for (size_t i = 0; i < other.maxSize; ++i)
    {
        this->data[i] = other.data[i];
    }
}

VecND::VecND(const std::initializer_list <long double>& other) : VecND()
{
    *this = VecND(other.size());

    for (size_t i = 0; i < this->maxSize; ++i)
    {
        this->data[i] = *(other.begin() + i);
    }
}

long double& VecND::operator[](size_t index) const
{
    return this->data.get()[index];
}

VecND& VecND::operator=(const VecND& other)
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
        this->data.reset();
        this->data = std::make_unique <long double[]>(maxSize);

        for (size_t i = 0; i < other.maxSize; ++i)
        {
            this->data[i] = other.data[i];
        }
    }

    return *this;
}

VecND VecND::operator*(long double other)
{
    VecND temp = *this;

    for (size_t i = 0; i < temp.maxSize; ++i)
    {
        temp.operator[](i) *= other;
    }

    return temp;
}

size_t VecND::getSize() const
{
    return this->maxSize;
}

void VecND::input()
{
    std::cin >> this->maxSize;

    *this = VecND(this->maxSize);

    for (int i = 0; i < this->maxSize; ++i)
    {
        std::cin >> this->data[i];
    }
}

void VecND::output()
{
    for (int i = 0; i < this->maxSize; ++i)
    {
        std::cout << this->data[i] << ' ';
    }
    std::cout << std::endl << std::endl;
}

VecND::~VecND()
{
}
