#include "VecND.hpp"

VecND::VecND(size_t n)
{
    data = new int[n];
    maxSize = n;
}

VecND::VecND(const VecND& other)
{
    this->maxSize = other.maxSize;
    this->data = new int[maxSize];

    for (size_t i = 0; i < other.maxSize; ++i)
    {
        this->data[i] = other.data[i];
    }
}

VecND::VecND(const std::initializer_list <int>& other) : VecND()
{
    *this = VecND(other.size());

    for (size_t i = 0; i < this->maxSize; ++i)
    {
        this->data[i] = *(other.begin() + i);
    }
}

int& VecND::operator[](size_t index) const
{
    return this->data[index];
}

VecND& VecND::operator=(const VecND& other)
{
    this->maxSize = other.maxSize;

    if (this->data != nullptr && this->data != other.data)
    {
        delete[] this->data;
        this->data = new int[this->maxSize];
    }

    for (size_t i = 0; i < this->maxSize; ++i)
    {
        this->operator[](i) = other[i];
    }

    return *this;
}

size_t VecND::getSize() const
{
    return this->maxSize;
}


void VecND::input()
{
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
    delete[] this->data;
}
