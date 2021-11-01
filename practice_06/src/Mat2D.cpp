#include <iostream>
#include "Mat2D.hpp"

template <typename T>
Mat2D <T>::Mat2D(size_t n, size_t m)
{
    std::vector <VecND <T>> temp(n);

    VecND <T> line(m);
    for (size_t i = 0; i < n; ++i)
    {
        temp[i] = line;
    }

    this->n = n;
    this->m = m;
    this->data = temp;
}

template <typename T>
Mat2D <T>::Mat2D(const Mat2D& other)
{
    this->n = other.n;
    this->m = other.m;

    std::vector <VecND <T>> temp(this->n);

    VecND <T> line(this->m);
    for (size_t i = 0; i < this->n; ++i)
    {
        temp[i] = line;
    }

    this->data = temp;

    for (size_t i = 0; i < other.n; ++i)
    {
        for (size_t j = 0; j < other.m; ++j)
        {
            this->operator[](i)[j] = other[i][j];
        }
    }
}

template <typename T>
Mat2D <T>::Mat2D(const std::initializer_list <std::initializer_list <T>>& other)
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

    *this = Mat2D <T>(_n, _m);

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

template <typename T>
size_t Mat2D <T>::getN() const
{
    return this->n;
}

template <typename T>
size_t Mat2D <T>::getM() const
{
    return this->m;
}

template <typename T>
void Mat2D <T>::input()
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

template <typename T>
void Mat2D <T>::output()
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

template <typename T>
VecND <T> const& Mat2D <T>::operator[](size_t index) const
{
    return this->data[index];
}

template <typename T>
VecND <T>& Mat2D <T>::operator[](size_t index)
{
    return this->data[index];
}

template <typename T>
Mat2D <T>& Mat2D <T>::operator=(const Mat2D& other)
{
    this->n = other.n;
    this->m = other.m;

    this->data = other.data;


    // TODO: Check
    for (size_t i = 0; i < other.n; ++i)
    {
        for (size_t j = 0; j < other.m; ++j)
        {
            this->operator[](i)[j] = other.operator[](i)[j];
        }
    }

    return *this;
}

template <typename T>
Mat2D <T> Mat2D <T>::operator+(const Mat2D& other)
{
    if (this->n != other.n || this->m != other.m)
    {
        return *this;
    }

    Mat2D <T> temp = *this;

    for (size_t i = 0; i < this->n; ++i)
    {
        for (size_t j = 0; j < this->m; ++j)
        {
            temp.operator[](i)[j] = temp.operator[](i)[j] + other.operator[](i)[j];
        }
    }

    return temp;
}

template <typename T>
Mat2D <T> Mat2D <T>::operator*(const Mat2D& other)
{
    if (this->m != other.n)
    {
        return *this;
    }

    Mat2D <T> temp(this->n, other.m);

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

template <typename T>
Mat2D <T> Mat2D <T>::operator*(const VecND <T>& other)
{
    if (this->n != other.getSize())
    {
        return *this;
    }

    Mat2D <T> temp(other.getSize(), 1);

    for (size_t i = 0; i < temp.n; ++i)
    {
        temp.operator[](i)[0] = other[i];
    }

    temp = *this * temp;

    return temp;
}

template <typename T>
Mat2D <T> Mat2D <T>::operator*(size_t other)
{
    Mat2D <T> temp = *this;

    for (size_t i = 0; i < temp.n; ++i)
    {
        for (size_t j = 0; j < temp.m; ++j)
        {
            temp.operator[](i)[j] = temp.operator[](i)[j] * other;
        }
    }

    return temp;
}

template <typename T>
Mat2D <T> Mat2D <T>::operator^(size_t pow)
{
    Mat2D <T> temp = *this;

    for (size_t iteration = 1; iteration < pow; ++iteration)
    {
        temp = temp * *this;
    }

    return temp;
}

template <typename T>
Mat2D <T>& Mat2D <T>::transpose()
{
    Mat2D <T> temp(this->m, this->n);

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

template <typename T>
long double Mat2D <T>::getDeterminant()
{
    if (this->n != this->m)
    {
        return 0;
    }

    return determinantOfMatrix(*this, this->n);
}

template <typename T>
long double Mat2D <T>::determinantOfMatrix(Mat2D <T>& mat, size_t _n)
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

    Mat2D <T> temp(_n, _n);

    int sign = 1;
    for (int i = 0; i < _n; ++i)
    {
        subMatrix(mat, temp, 0, i, _n);
        determinant += sign * mat[0][i] * determinantOfMatrix(temp, _n - 1);
        sign = -sign;
    }

    return determinant;
}

template <typename T>
void Mat2D <T>::subMatrix(const Mat2D <T>& mat, Mat2D <T>& temp, int p, int q, size_t _n)
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

template <typename T>
Mat2D <T> Mat2D <T>::getInverse()
{
    long double determinant = this->getDeterminant();
    if (determinant == 0)
    {
        return *this;
    }

    Mat2D <T> inverse(this->n, this->m);
    Mat2D <T> adjoint(this->n, this->m);
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

template <typename T>
void Mat2D <T>::getAdjoint(const Mat2D <T>& mat, Mat2D <T>& adjoint)
{
    if (mat.n == 1)
    {
        adjoint[0][0] = 1;
        return;
    }

    int sign = 1;
    Mat2D <T> temp(mat.n, mat.m);

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

template <typename T>
void Mat2D <T>::getCofactor(const Mat2D <T>& mat, Mat2D <T>& temp, size_t p, size_t q, size_t _n)
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

const double EPS = 1E-9;

template <typename T>
int Mat2D <T>::getRank()
{
    int rank = 0;

    std::vector <bool> selectedRow(this->n, false);
    std::vector <std::vector <long double>> temp(this->n, std::vector <long double>(this->m));

    for (size_t i = 0; i < this->n; ++i)
    {
        for (size_t j = 0; j < this->m; ++j)
        {
            temp[i][j] = this->operator[](i)[j];
        }
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

    return rank;
}

template class Mat2D <short int>;
template class Mat2D <unsigned short int>;
template class Mat2D <unsigned int>;
template class Mat2D <int>;
template class Mat2D <unsigned long int>;
template class Mat2D <long int>;
template class Mat2D <unsigned long long int>;
template class Mat2D <long long int>;
template class Mat2D <float>;
template class Mat2D <double>;
template class Mat2D <long double>;
