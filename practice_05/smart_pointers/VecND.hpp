#ifndef PRACTICE_05_VECND_HPP
#define PRACTICE_05_VECND_HPP


#include <iostream>
#include <memory>

class VecND
{
private:
    std::unique_ptr <long double[]> data;
    size_t maxSize;
public:
    VecND(size_t n = 3);

    VecND(const VecND& other);

    VecND(const std::initializer_list <long double>& other);

    long double& operator[](size_t index) const;

    VecND& operator=(const VecND& other);

    VecND operator*(long double other);

    size_t getSize() const;

    void input();

    void output();

    ~VecND();
};


#endif //PRACTICE_05_VECND_HPP
