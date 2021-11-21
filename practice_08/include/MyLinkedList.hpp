#ifndef PRACTICE_08_MYLINKEDLIST_HPP
#define PRACTICE_08_MYLINKEDLIST_HPP


#include <iostream>

template <typename T>
class MyLinkedList
{
private:
    typedef struct Node
    {
        T val = 0;
        Node* next = nullptr;
    } Node;

    Node* first;
    Node* last;
    size_t size = 0;
public:
    MyLinkedList(size_t n = 1);

    MyLinkedList(size_t n, T val);

    MyLinkedList(const std::initializer_list <T>& other);

    MyLinkedList(const std::string& other);

    MyLinkedList <char>& operator=(const std::string& other);

    ~MyLinkedList();

    void pushFront(T val);

    T popFront();

    void pushBack(T val);

    T popBack();

    size_t getSize();

    void print();

    class Iterator
    {
    private:
        Node* iNode;
    public:
        Iterator();

        Iterator(Node* other);

        Iterator& operator++();

        Iterator& operator++(int);

        T& operator*();

        bool operator==(Iterator other);

        bool operator!=(Iterator other);

        bool operator==(Node* other);

        bool operator!=(Node* other);
    };

    Iterator begin();

    Iterator end();
};


#endif //PRACTICE_08_MYLINKEDLIST_HPP
