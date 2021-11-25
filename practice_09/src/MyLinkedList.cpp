#include <string>
#include <variant>
#include "MyLinkedList.hpp"

template <typename T>
MyLinkedList <T>::MyLinkedList(size_t n)
{
    if (n == 0)
    {
        return;
    }

    first = new Node();
    last = first;
    for (size_t i = 0; i < n - 1; ++i)
    {
        last->next = new Node();
        last = last->next;
    }
    size = n;
}

template <typename T>
MyLinkedList <T>::MyLinkedList(size_t n, T val)
{
    if (n == 0)
    {
        return;
    }

    first = new Node();
    first->val = val;
    last = first;
    for (size_t i = 0; i < n - 1; ++i)
    {
        last->next = new Node();
        last = last->next;
        last->val = val;
    }
    size = n;
}

template <typename T>
MyLinkedList <T>::MyLinkedList(const MyLinkedList <T>& other) : MyLinkedList()
{
    this->first->val = other.first->val;

    Node* start = other.first->next;

    while (start)
    {
        this->pushFront(start->val);
        start = start->next;
    }
}

template <typename T>
MyLinkedList <T>::MyLinkedList(const std::initializer_list <T>& other)
{
    if (other.size() == 0)
    {
        return;
    }

    first = new Node();
    first->val = *(other.begin());
    last = first;
    for (size_t i = 1; i < other.size(); ++i)
    {
        last->next = new Node();
        last = last->next;
        last->val = *(other.begin() + i);
    }
    size = other.size();
}

template <typename T>
MyLinkedList <T>::MyLinkedList(const std::string& other) : MyLinkedList()
{
    if (other.empty() || !(std::is_same <T, char>::value))
    {
        return;
    }

    first = new Node();
    first->val = *(other.begin());
    last = first;
    for (std::string::const_iterator it = other.begin() + 1; it != other.end(); ++it)
    {
        this->pushFront(*it);
    }
    size = other.size();
}

template <typename T>
MyLinkedList <T>& MyLinkedList <T>::operator=(const MyLinkedList <T>& other)
{
    if (other.size > size)
    {
        Node* currentPtr = first;
        Node* otherPtr = other.first;

        while (currentPtr != nullptr)
        {
            currentPtr->val = otherPtr->val;
            currentPtr = currentPtr->next;
            otherPtr = otherPtr->next;
        }

        while (otherPtr != nullptr)
        {
            this->pushFront(otherPtr->val);
            otherPtr = otherPtr->next;
        }
    }
    else if (other.size < size)
    {
        Node* currentPtr = first;
        Node* otherPtr = other.first;

        while (otherPtr->next != nullptr)
        {
            currentPtr->val = otherPtr->val;
            currentPtr = currentPtr->next;
            otherPtr = otherPtr->next;
        }
        currentPtr->val = otherPtr->val;
        last = currentPtr;
        otherPtr = currentPtr->next;
        currentPtr->next = nullptr;

        while (otherPtr != nullptr)
        {
            Node* temp = otherPtr->next;
            delete otherPtr;

            otherPtr = temp;
        }
    }
    else
    {
        Node* currentPtr = first;
        Node* otherPtr = other.first;

        while (currentPtr != nullptr)
        {
            currentPtr->val = otherPtr->val;
            currentPtr = currentPtr->next;
            otherPtr = otherPtr->next;
        }
    }

    return *this;
}


template <>
MyLinkedList <char>& MyLinkedList <char>::operator=(const std::string& other)
{
    Node* ptr = first;

    while (ptr != nullptr)
    {
        Node* temp = ptr->next;
        delete ptr;

        ptr = temp;
    }

    first = new Node();
    first->val = *(other.begin());
    last = first;
    for (std::string::const_iterator it = other.begin() + 1; it != other.end(); ++it)
    {
        this->pushFront(*it);
    }
    size = other.size();

    return *this;
}

template <typename T>
MyLinkedList <T>::~MyLinkedList()
{
    Node* ptr = first;

    while (ptr != nullptr)
    {
        Node* temp = ptr->next;
        delete ptr;

        ptr = temp;
    }
}

template <typename T>
void MyLinkedList <T>::pushFront(T val)
{
    last->next = new Node();
    last = last->next;
    last->val = val;
    size++;
}

template <typename T>
T MyLinkedList <T>::popFront()
{
    Node* newFront = first;

    size_t current = 0;
    while (current < size - 2)
    {
        newFront = newFront->next;
        current++;
    }

    last = newFront;
    T out = newFront->next->val;
    newFront->next = nullptr;
    size--;

    return out;
}

template <typename T>
void MyLinkedList <T>::pushBack(T val)
{
    Node* newBack = new Node();

    newBack->val = val;
    newBack->next = first;
    first = newBack;
    size++;
}

template <typename T>
T MyLinkedList <T>::popBack()
{
    T out = first->val;
    first = first->next;
    size--;

    return out;
}

template <typename T>
size_t MyLinkedList <T>::getSize()
{
    return size;
}

template <typename T>
void MyLinkedList <T>::print()
{
    for (auto& it: *this)
    {
        std::cout << it << ' ';
    }
}

template <typename T>
typename MyLinkedList <T>::Iterator MyLinkedList <T>::begin()
{
    return MyLinkedList::Iterator(first);
}

template <typename T>
typename MyLinkedList <T>::Iterator MyLinkedList <T>::end()
{
    return MyLinkedList::Iterator(last->next);
}

template <typename T>
void MyLinkedList <T>::insert(size_t place, T val)
{
    if (place == 0)
    {
        this->pushBack(val);
    }
    else if (place == this->size - 1)
    {
        this->pushFront(val);
    }
    else
    {
        Iterator position = this->begin() + (place - 1);

        Node* toInsert = new Node();
        toInsert->val = val;
        toInsert->next = position.iNode->next;

        position.iNode->next = toInsert;
    }
}

template <typename T>
MyLinkedList <T>::Iterator::Iterator()
{
    iNode = nullptr;
}

template <typename T>
MyLinkedList <T>::Iterator::Iterator(Node* other)
{
    iNode = other;
}

template <typename T>
typename MyLinkedList <T>::Iterator& MyLinkedList <T>::Iterator::operator++()
{
    this->iNode = this->iNode->next;
    return *this;
}

template <typename T>
typename MyLinkedList <T>::Iterator& MyLinkedList <T>::Iterator::operator++(int)
{
    this->iNode = this->iNode->next;
    return *this;
}

template <typename T>
typename MyLinkedList <T>::Iterator& MyLinkedList <T>::Iterator::operator+(int shift)
{
    int count = 0;

    while (iNode->next && count != shift)
    {
        iNode = iNode->next;
        count++;
    }

    return *this;
}

template <typename T>
T& MyLinkedList <T>::Iterator::operator*()
{
    return this->iNode->val;
}

template <typename T>
bool MyLinkedList <T>::Iterator::operator==(MyLinkedList::Iterator other)
{
    return this->iNode == other.iNode;
}

template <typename T>
bool MyLinkedList <T>::Iterator::operator!=(MyLinkedList::Iterator other)
{
    return this->iNode != other.iNode;
}

template <typename T>
bool MyLinkedList <T>::Iterator::operator==(Node* other)
{
    return this->iNode == other;
}

template <typename T>
bool MyLinkedList <T>::Iterator::operator!=(Node* other)
{
    return this->iNode != other;
}

template
class MyLinkedList <short int>;

template
class MyLinkedList <unsigned short int>;

template
class MyLinkedList <unsigned int>;

template
class MyLinkedList <int>;

template
class MyLinkedList <unsigned long int>;

template
class MyLinkedList <long int>;

template
class MyLinkedList <unsigned long long int>;

template
class MyLinkedList <long long int>;

template
class MyLinkedList <float>;

template
class MyLinkedList <double>;

template
class MyLinkedList <long double>;

template
class MyLinkedList <char>;
