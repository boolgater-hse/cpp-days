#ifndef PRACTICE_06_DYNARRAY_HPP
#define PRACTICE_06_DYNARRAY_HPP


#include <vector>

template <typename T>
class DynArray
{
private:
    std::vector <T> data;
public:
    static size_t alive;

    DynArray(size_t n = 10);

    DynArray(const DynArray <T>& other);

    DynArray <T>& operator=(const DynArray <T>& other);

    void input();

    void output();

    T& operator[](size_t index);

    size_t getSize();

    void append(T other);

    DynArray <T> operator+(const DynArray <T>& other);

    DynArray <T> operator<<(size_t d);

    DynArray <T> operator>>(size_t d);
};


#endif //PRACTICE_06_DYNARRAY_HPP
