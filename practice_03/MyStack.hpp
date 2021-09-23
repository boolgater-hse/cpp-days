#ifndef PRACTICE_03_MYSTACK_HPP
#define PRACTICE_03_MYSTACK_HPP


class MyStack
{
private:
    int* data;
    int ptr;
    int maxSize;
public:
    MyStack(int n);
    void push(int n);
    int peek();
    int pop();
    void resize();
    int size();
    ~MyStack();
};


#endif //PRACTICE_03_MYSTACK_HPP
