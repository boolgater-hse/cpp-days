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

    int determinantOfMatrix(Mat2D& mat, size_t _n);

public:
    Mat2D(size_t n = 3, size_t m = 3);

    Mat2D(const Mat2D& other);

    size_t getN() const;

    size_t getM() const;

    void input();

    void output();

    VecND& operator[](size_t index) const;

    Mat2D& operator=(const Mat2D& other);

    Mat2D& operator+(const Mat2D& other);

    Mat2D& operator*(const Mat2D& other);

    Mat2D& operator*(const VecND& other);

    Mat2D& transpose();

    int getDeterminant();

    int getRank();

    bool checkZeroRows() const;

    ~Mat2D();
};


#endif //PRACTICE_05_MAT2D_HPP
