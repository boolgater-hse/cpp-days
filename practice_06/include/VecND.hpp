#ifndef PRACTICE_06_VECND_HPP
#define PRACTICE_06_VECND_HPP


#include <vector>

template <typename T>
class VecND
{
private:
    std::vector <T> data;
    size_t maxSize;
public:
    VecND(size_t n = 3);

    VecND(const VecND& other);

    VecND(const std::initializer_list <T>& other);

    T const& operator[](size_t index) const;

    T& operator[](size_t index);

    VecND <T>& operator=(const VecND <T>& other);

    VecND <T> operator*(size_t other);

    size_t getSize() const;

    void input();

    void output();
};


#endif //PRACTICE_06_VECND_HPP
