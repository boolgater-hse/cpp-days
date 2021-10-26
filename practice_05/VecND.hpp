#ifndef PRACTICE_05_VECND_HPP
#define PRACTICE_05_VECND_HPP


#include <iostream>

class VecND
{
private:
    long double* data;
    size_t maxSize;
public:
    VecND(size_t n = 3);

    VecND(const VecND& other);

    VecND(const std::initializer_list <int>& other);

    long double& operator[](size_t index) const;

    VecND& operator=(const VecND& other);

    VecND operator*(size_t other);

    size_t getSize() const;

    void input();

    void output();

    ~VecND();
};


#endif //PRACTICE_05_VECND_HPP
