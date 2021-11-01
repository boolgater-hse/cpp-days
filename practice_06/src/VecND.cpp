#include <iostream>
#include "VecND.hpp"

template <typename T>
VecND <T>::VecND(size_t n)
{
    std::vector <T> temp(n, 0);
    this->data = temp;
    this->maxSize = n;
}

template <typename T>
VecND <T>::VecND(const VecND& other)
{
    this->maxSize = other.maxSize;
    this->data = other.data;
}

template <typename T>
VecND <T>::VecND(const std::initializer_list <T>& other) : VecND(other.size())
{
    for (size_t i = 0; i < this->maxSize; ++i)
    {
        this->data[i] = *(other.begin() + i);
    }
}

template <typename T>
T const& VecND <T>::operator[](size_t index) const
{
    return this->data[index];
}

template <typename T>
T& VecND <T>::operator[](size_t index)
{
    return this->data[index];
}

template <typename T>
VecND <T>& VecND <T>::operator=(const VecND <T>& other)
{
    this->maxSize = other.maxSize;
    this->data = other.data;

    return *this;
}

template <typename T>
VecND <T> VecND <T>::operator*(size_t other)
{
    VecND <T> temp = *this;

    for (size_t i = 0; i < temp.maxSize; ++i)
    {
        temp[i] = temp[i] * other;
    }

    return temp;
}

template <typename T>
size_t VecND <T>::getSize() const
{
    return this->maxSize;
}

template <typename T>
void VecND <T>::input()
{
    std::cin >> this->maxSize;

    *this = VecND(this->maxSize);

    for (size_t i = 0; i < this->maxSize; ++i)
    {
        std::cin >> this->data[i];
    }
}

template <typename T>
void VecND <T>::output()
{
    for (size_t i = 0; i < this->maxSize; ++i)
    {
        std::cout << this->data[i] << ' ';
    }
    std::cout << std::endl << std::endl;
}

template class VecND <short int>;
template class VecND <unsigned short int>;
template class VecND <unsigned int>;
template class VecND <int>;
template class VecND <unsigned long int>;
template class VecND <long int>;
template class VecND <unsigned long long int>;
template class VecND <long long int>;
template class VecND <float>;
template class VecND <double>;
template class VecND <long double>;
