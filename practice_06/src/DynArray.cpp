#include <iostream>
#include "DynArray.hpp"

template <typename T>
size_t DynArray <T>::alive = 0;

template <typename T>
DynArray <T>::DynArray(size_t n)
{
    std::vector <T> temp(n, 0);
    this->data = temp;
    alive++;
}

template <typename T>
DynArray <T>::DynArray(const DynArray <T>& other)
{
    this->data = other.data;
    alive++;
}

template <typename T>
DynArray <T>& DynArray <T>::operator=(const DynArray <T>& other)
{
    this->data = other.data;

    return *this;
}

template <typename T>
void DynArray <T>::input()
{
    size_t n;
    std::cin >> n;

    DynArray temp(n);
    *this = temp;

    for (size_t i = 0; i < this->data.size(); ++i)
    {
        std::cin >> this->data[i];
    }
}

template <typename T>
void DynArray <T>::output()
{
    for (size_t i = 0; i < this->data.size(); ++i)
    {
        std::cout << this->data[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
T& DynArray <T>::operator[](size_t index)
{
    return this->data[index];
}

template <typename T>
size_t DynArray <T>::getSize()
{
    return data.size();
}

template <typename T>
void DynArray <T>::append(T other)
{
    data.push_back(other);
}

template <typename T>
DynArray <T> DynArray <T>::operator+(const DynArray <T>& other)
{
    DynArray <T> temp = *this;
    temp.data.insert(temp.data.end(), other.data.begin(), other.data.end());

    return temp;
}

template <typename T>
DynArray <T> DynArray <T>::operator<<(size_t d)
{
    DynArray <T> temp = *this;

    for (size_t i = 0; i < d; ++i)
    {
        T first = temp.data[0];
        for (size_t j = 0; j < temp.data.size() - 1; ++j)
        {
            temp.data[j] = temp.data[j + 1];
        }
        temp.data[temp.data.size() - 1] = first;
    }

    return temp;
}

template <typename T>
DynArray <T> DynArray <T>::operator>>(size_t d)
{
    DynArray <T> temp = *this;

    for (size_t i = 0; i < d; ++i)
    {
        T last = temp.data[temp.data.size() - 1];
        for (size_t j = temp.data.size() - 1; j >= 1; --j)
        {
            temp.data[j] = temp.data[j - 1];
        }
        temp.data[0] = last;
    }

    return temp;
}

template
class DynArray <short int>;

template
class DynArray <unsigned short int>;

template
class DynArray <unsigned int>;

template
class DynArray <int>;

template
class DynArray <unsigned long int>;

template
class DynArray <long int>;

template
class DynArray <unsigned long long int>;

template
class DynArray <unsigned char>;

template
class DynArray <signed char>;

template
class DynArray <char>;

template
class DynArray <long long int>;

template
class DynArray <float>;

template
class DynArray <double>;

template
class DynArray <long double>;
