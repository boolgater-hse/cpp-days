#include <iostream>
#include "DynArray.hpp"
#include "MyStack.hpp"

using namespace std;

int main()
{
    cout << "DynArray Test:" << endl;
    DynArray arr(10);
    arr.append(1.0);
    for (size_t i = 0; i < 15; ++i)
    {
        arr.append(i + 0.0);
    }

    for (size_t j = 0; j < arr.size(); ++j)
    {
        cout << arr.get(j) << ' ';
    }
    cout << endl;
    cout << "Size: " << arr.size() << endl;
    cout << "DynArray Test end" << endl;

    cout << endl;

    cout << "MyStack Test:" << endl;
    MyStack stack(2);
    stack.push(3);
    cout << stack.peek() << endl;
    stack.push(10);
    cout << stack.peek() << endl;
    stack.pop();
    stack.push(34);
    stack.push(65);
    stack.push(75);
    stack.push(34);
    stack.push(228);
    cout << "Size: " << stack.size() << endl;
    cout << "MyStack Test end" << endl;

    return 0;
}
