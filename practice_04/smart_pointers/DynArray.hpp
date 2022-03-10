#ifndef PRACTICE_04_DYNARRAY_HPP
#define PRACTICE_04_DYNARRAY_HPP


#include <memory>

class DynArray
{
private:
    std::unique_ptr <double[]> data;
    size_t maxSize;
public:
    static int alive;

    DynArray(size_t n = 10);

    DynArray(const DynArray& other);

    DynArray& operator=(const DynArray& other);

    double& operator[](size_t index) const;

    size_t size() const;

    DynArray& operator+(const DynArray& other);

    DynArray& operator<<(int d);

    DynArray& operator>>(int d);

    ~DynArray();
};


#endif //PRACTICE_04_DYNARRAY_HPP
