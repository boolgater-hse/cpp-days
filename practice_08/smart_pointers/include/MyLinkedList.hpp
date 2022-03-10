#ifndef PRACTICE_08_MYLINKEDLIST_HPP
#define PRACTICE_08_MYLINKEDLIST_HPP


#include <iostream>
#include <memory>

template <typename T>
class MyLinkedList
{
private:
    typedef struct Node
    {
        T val = 0;
        std::shared_ptr <Node> next = nullptr;
    } Node;

    std::shared_ptr <Node> first;
    std::shared_ptr <Node> last;
    size_t size = 0;
public:
    MyLinkedList(size_t n = 0);

    MyLinkedList(size_t n, T val);

    MyLinkedList(const MyLinkedList <T>& other);

    MyLinkedList(const std::initializer_list <T>& other);

    MyLinkedList(const std::string& other);

    MyLinkedList <T>& operator=(const MyLinkedList <T>& other);

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
    public:
        std::shared_ptr <Node> iNode;

        Iterator();

        Iterator(std::shared_ptr <Node> other);

        Iterator& operator++();

        Iterator& operator++(int);

        Iterator& operator+(int shift);

        T& operator*();

        bool operator==(Iterator other);

        bool operator!=(Iterator other);

        bool operator==(std::shared_ptr <Node> other);

        bool operator!=(std::shared_ptr <Node> other);
    };

    Iterator begin();

    Iterator end();

    void insert(size_t place, T val);
};


#endif //PRACTICE_08_MYLINKEDLIST_HPP
