#include <iostream>
#include "Mat2D.hpp"

Mat2D::Mat2D(const size_t n, const size_t m)
{
    data = new VecND* [n];
    for (size_t i = 0; i < n; ++i)
    {
        data[i] = new VecND(m);
    }
    this->n = n;
    this->m = m;
}

Mat2D::Mat2D(const Mat2D& other)
{
    this->n = other.n;
    this->m = other.m;

    data = new VecND* [this->n];
    for (size_t i = 0; i < this->n; ++i)
    {
        data[i] = new VecND(this->m);
    }

    for (size_t i = 0; i < other.n; ++i)
    {
        for (size_t j = 0; j < other.m; ++j)
        {
            this->operator[](i)[j] = other.operator[](i)[j];
        }
    }
}

Mat2D::Mat2D(const std::initializer_list <std::initializer_list <long double>>& other) : Mat2D()
{
    size_t _n = other.size();
    size_t _m = 0;

    for (size_t i = 0; i < _n; ++i)
    {
        if ((other.begin() + i)->size() > _m)
        {
            _m = (other.begin() + i)->size();
        }
    }

    *this = Mat2D(_n, _m);

    for (size_t i = 0; i < _n; ++i)
    {
        for (size_t j = 0; j < _m; ++j)
        {
            this->operator[](i)[j] = 0;
        }
    }

    for (size_t i = 0; i < _n; ++i)
    {
        for (size_t j = 0; j < (other.begin() + i)->size(); ++j)
        {
            this->operator[](i)[j] = *((other.begin() + i)->begin() + j);
        }
    }
}

size_t Mat2D::getN() const
{
    return this->n;
}

size_t Mat2D::getM() const
{
    return this->m;
}

void Mat2D::input()
{
    std::cin >> this->n >> this->m;

    *this = Mat2D(this->n, this->m);

    for (size_t i = 0; i < this->n; ++i)
    {
        for (size_t j = 0; j < this->m; ++j)
        {
            std::cin >> this->operator[](i)[j];
        }
    }
}

void Mat2D::output()
{
    for (size_t i = 0; i < this->n; ++i)
    {
        for (size_t j = 0; j < this->m; ++j)
        {
            std::cout << this->operator[](i)[j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

VecND& Mat2D::operator[](size_t index) const
{
    return *data[index];
}

Mat2D& Mat2D::operator=(const Mat2D& other)
{
    this->n = other.n;
    this->m = other.m;

    if (this->data != nullptr && this->data != other.data)
    {
        delete[] this->data;
        this->data = new VecND* [this->n];
        for (size_t i = 0; i < this->n; ++i)
        {
            data[i] = new VecND(this->m);
        }
    }

    for (size_t i = 0; i < other.n; ++i)
    {
        for (size_t j = 0; j < other.m; ++j)
        {
            this->operator[](i)[j] = other.operator[](i)[j];
        }
    }

    return *this;
}

Mat2D Mat2D::operator+(const Mat2D& other)
{
    if (this->n != other.n || this->m != other.m)
    {
        return *this;
    }

    Mat2D temp = *this;

    for (size_t i = 0; i < this->n; ++i)
    {
        for (size_t j = 0; j < this->m; ++j)
        {
            temp.operator[](i)[j] = temp.operator[](i)[j] + other.operator[](i)[j];
        }
    }

    return temp;
}

Mat2D Mat2D::operator*(const Mat2D& other)
{
    if (this->m != other.n)
    {
        return *this;
    }

    Mat2D temp(this->n, other.m);
    for (size_t i = 0; i < temp.n; ++i)
    {
        for (size_t j = 0; j < temp.m; ++j)
        {
            long double sum = 0;
            for (size_t k = 0; k < this->m; ++k)
            {
                sum += this->operator[](i)[k] * other.operator[](k)[j];
            }
            temp.operator[](i)[j] = sum;
        }
    }

    return temp;
}

Mat2D Mat2D::operator*(const VecND& other)
{
    if (this->n != other.getSize())
    {
        return *this;
    }

    Mat2D temp(other.getSize(), 1);
    for (size_t i = 0; i < temp.n; ++i)
    {
        temp.operator[](i)[0] = other[i];
    }

    temp = *this * temp;

    return temp;
}

Mat2D Mat2D::operator*(const size_t other)
{
    Mat2D temp = *this;

    for (size_t i = 0; i < temp.n; ++i)
    {
        for (size_t j = 0; j < temp.m; ++j)
        {
            temp.operator[](i)[j] *= other;
        }
    }

    return temp;
}

Mat2D Mat2D::operator^(const size_t pow)
{
    Mat2D temp = *this;
    for (size_t iteration = 1; iteration < pow; ++iteration)
    {
        temp = temp * *this;
    }

    return temp;
}

Mat2D& Mat2D::transpose()
{
    Mat2D temp(this->m, this->n);

    for (size_t i = 0; i < this->n; ++i)
    {
        for (size_t j = 0; j < this->m; ++j)
        {
            temp.operator[](j)[i] = this->operator[](i)[j];
        }
    }

    *this = temp;

    return *this;
}

void Mat2D::subMatrix(const Mat2D& mat, Mat2D& temp, int p, int q, size_t _n)
{
    int i = 0, j = 0;
    for (int row = 0; row < _n; ++row)
    {
        for (int col = 0; col < _n; ++col)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];
                if (j == _n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

long double Mat2D::determinantOfMatrix(Mat2D& mat, size_t _n)
{
    long double determinant = 0;

    if (_n == 1)
    {
        return mat[0][0];
    }
    if (_n == 2)
    {
        return (mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]);
    }

    Mat2D temp(_n, _n);
    int sign = 1;
    for (int i = 0; i < _n; ++i)
    {
        subMatrix(mat, temp, 0, i, _n);
        determinant += sign * mat[0][i] * determinantOfMatrix(temp, _n - 1);
        sign = -sign;
    }

    return determinant;
}

void Mat2D::getAdjoint(const Mat2D& mat, Mat2D& adjoint)
{
    if (mat.n == 1)
    {
        adjoint[0][0] = 1;
        return;
    }

    int sign = 1;
    Mat2D temp(mat.n, mat.m);

    for (size_t i = 0; i < adjoint.n; ++i)
    {
        for (size_t j = 0; j < adjoint.m; ++j)
        {
            getCofactor(mat, temp, i, j, mat.n);

            if ((i + j) % 2 == 0)
            {
                sign = 1;
            }
            else
            {
                sign = -1;
            }

            adjoint[j][i] = sign * determinantOfMatrix(temp, mat.n - 1);
        }
    }
}

void Mat2D::getCofactor(const Mat2D& mat, Mat2D& temp, size_t p, size_t q, size_t _n)
{
    size_t i = 0;
    size_t j = 0;

    for (size_t row = 0; row < temp.n; ++row)
    {
        for (size_t col = 0; col < temp.m; ++col)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = mat[row][col];

                if (j == _n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

long double Mat2D::getDeterminant()
{
    if (this->n != this->m)
    {
        return 0;
    }

    return determinantOfMatrix(*this, this->n);
}

Mat2D Mat2D::getInverse()
{
    long double determinant = this->getDeterminant();
    if (determinant == 0)
    {
        return *this;
    }

    Mat2D inverse(this->n, this->m);
    Mat2D adjoint(this->n, this->m);
    getAdjoint(*this, adjoint);

    for (size_t i = 0; i < this->n; ++i)
    {
        for (size_t j = 0; j < this->m; ++j)
        {
            inverse[i][j] = adjoint[i][j] / determinant;
        }
    }

    return inverse;
}

const double EPS = 1E-9;

int Mat2D::getRank()
{
    int rank = 0;

    bool* selectedRow = new bool[this->n];
    Mat2D temp = *this;

    for (size_t i = 0; i < this->n; ++i)
    {
        selectedRow[i] = false;
    }

    for (size_t i = 0; i < this->m; ++i)
    {
        size_t j;
        for (j = 0; j < this->n; ++j)
        {
            if (!selectedRow[j] && std::abs(temp[j][i]) > EPS)
            {
                break;
            }
        }

        if (j != this->n)
        {
            rank++;
            selectedRow[j] = true;
            for (size_t p = i + 1; p < this->m; ++p)
            {
                if (temp[j][i] != 0)
                {
                    temp[j][p] /= temp[j][i];
                }
            }
            for (size_t k = 0; k < this->n; ++k)
            {
                if (k != j && std::abs(temp[j][i]) > EPS)
                {
                    for (size_t p = i + 1; p < this->m; ++p)
                    {
                        temp[k][p] -= temp[j][p] * temp[k][i];
                    }
                }
            }
        }
    }
    delete[] selectedRow;

    return rank;
}

bool Mat2D::checkZeroRows() const
{
    for (size_t i = 0; i < this->n; ++i)
    {
        bool flag = true;
        for (size_t j = 0; j < this->m; ++j)
        {
            if (this->operator[](i)[j] != 0)
            {
                flag = false;
                break;
            }
            flag = true;
        }
        if (flag)
        {
            return true;
        }
    }
    return false;
}

Mat2D::~Mat2D()
{
    delete[] this->data;
}
