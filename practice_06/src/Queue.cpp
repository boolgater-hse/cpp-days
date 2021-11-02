#include <iostream>
#include "Queue.hpp"

template <typename T>
Queue <T>::Queue()
{
}

template <typename T>
void Queue <T>::output()
{
    for (size_t i = 0; i < this->data.size(); ++i)
    {
        std::cout << this->data[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
bool Queue <T>::isEmpty()
{
    return this->data.empty();
}

template <typename T>
void Queue <T>::insert(T n)
{
    this->data.push_back(n);
}

template <typename T>
T Queue <T>::pop()
{
    if (this->isEmpty())
    {
        return 0;
    }

    std::vector <T> temp;

    while (!this->isEmpty())
    {
        temp.push_back(this->data.back());
        this->data.pop_back();
    }

    T out = temp.back();
    temp.pop_back();

    while (!temp.empty())
    {
        this->data.push_back(temp.back());
        temp.pop_back();
    }

    return out;
}

template <typename T>
size_t Queue <T>::getSize()
{
    return this->data.size();
}

template
class Queue <short int>;

template
class Queue <unsigned short int>;

template
class Queue <unsigned int>;

template
class Queue <int>;

template
class Queue <unsigned long int>;

template
class Queue <long int>;

template
class Queue <unsigned long long int>;

template
class Queue <unsigned char>;

template
class Queue <signed char>;

template
class Queue <long long int>;

template
class Queue <float>;

template
class Queue <double>;

template
class Queue <long double>;
