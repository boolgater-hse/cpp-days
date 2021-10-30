#ifndef PRACTICE_06_QUEUE_HPP
#define PRACTICE_06_QUEUE_HPP


#include <vector>

template <typename T>
class Queue
{
private:
    std::vector <T> data;
public:
    Queue();

    void output();

    bool isEmpty();

    void insert(T n);

    T pop();

    size_t getSize();
};


#endif //PRACTICE_06_QUEUE_HPP
