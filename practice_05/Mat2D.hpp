#ifndef PRACTICE_05_MAT2D_HPP
#define PRACTICE_05_MAT2D_HPP


#include <iostream>
#include "VecND.hpp"

class Mat2D
{
private:
    VecND** data;
    size_t n, m;

    void subMatrix(const Mat2D& mat, Mat2D& temp, int p, int q, size_t _n);

    long double determinantOfMatrix(Mat2D& mat, size_t _n);

    void getAdjoint(const Mat2D& mat, Mat2D& adjoint);

    void getCofactor(const Mat2D& mat, Mat2D& temp, size_t p, size_t q, size_t _n);

public:
    Mat2D(size_t n = 3, size_t m = 3);

    Mat2D(const Mat2D& other);

    Mat2D(const std::initializer_list <std::initializer_list <int>>& other);

    size_t getN() const;

    size_t getM() const;

    void input();

    void output();

    VecND& operator[](size_t index) const;

    Mat2D& operator=(const Mat2D& other);

    Mat2D operator+(const Mat2D& other);

    Mat2D operator*(const Mat2D& other);

    Mat2D operator*(const VecND& other);

    Mat2D operator*(size_t other);

    Mat2D operator^(size_t pow);

    Mat2D& transpose();

    long double getDeterminant();

    Mat2D getInverse();

    int getRank();

    bool checkZeroRows() const;

    ~Mat2D();
};


#endif //PRACTICE_05_MAT2D_HPP
