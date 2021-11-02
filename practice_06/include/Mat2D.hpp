#ifndef PRACTICE_06_MAT2D_HPP
#define PRACTICE_06_MAT2D_HPP


#include "VecND.hpp"

template <typename T>
class Mat2D
{
private:
    std::vector <VecND <T>> data;
    size_t n, m;

    void subMatrix(const Mat2D <T>& mat, Mat2D <T>& temp, int p, int q, size_t _n);

    long double determinantOfMatrix(Mat2D <T>& mat, size_t _n);

    void getAdjoint(const Mat2D <T>& mat, Mat2D <T>& adjoint);

    void getCofactor(const Mat2D <T>& mat, Mat2D <T>& temp, size_t p, size_t q, size_t _n);

public:
    Mat2D(size_t n = 3, size_t m = 3);

    Mat2D(const Mat2D <T>& other);

    Mat2D(const std::initializer_list <std::initializer_list <T>>& other);

    size_t getN() const;

    size_t getM() const;

    void input();

    void output();

    VecND <T> const& operator[](size_t index) const;

    VecND <T>& operator[](size_t index);

    Mat2D <T>& operator=(const Mat2D <T>& other);

    Mat2D <T> operator+(const Mat2D <T>& other);

    Mat2D <T> operator*(const Mat2D <T>& other);

    Mat2D <T> operator*(const VecND <T>& other);

    Mat2D <T> operator*(size_t other);

    Mat2D <T> operator^(size_t pow);

    Mat2D <T>& transpose();

    long double getDeterminant();

    Mat2D <T> getInverse();

    int getRank();
};


#endif //PRACTICE_06_MAT2D_HPP
