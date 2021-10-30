#include "../include/Mat2D.hpp"
#include "../include/SLAE.hpp"

template <typename T>
SLAE <T>::SLAE(const Mat2D <T>& _matrix, const VecND <T>& _vector)
{
    matrix = _matrix;
    vector = _vector;
}

template <typename T>
std::vector <long double> SLAE <T>::solveByCramersRule()
{
    std::vector <long double> answer(matrix.getN(), 0.0);

    if (matrix.getN() != vector.getSize() || matrix.getN() != matrix.getM() || !checkCompatibility())
    {
        return answer;
    }

    long double mainDeterminant = matrix.getDeterminant();

    for (size_t iteration = 0; iteration < matrix.getN(); ++iteration)
    {
        Mat2D <T> temp = matrix;
        for (size_t i = 0; i < matrix.getN(); ++i)
        {
            temp[i][iteration] = vector[i];
        }
        answer[iteration] = temp.getDeterminant();
    }

    for (size_t i = 0; i < matrix.getN(); ++i)
    {
        answer[i] /= mainDeterminant;
    }

    this->lastRootsN = matrix.getN();

    return answer;
}

template <typename T>
size_t SLAE <T>::getNumberOfRoots() const
{
    return this->lastRootsN;
}

template <typename T>
bool SLAE <T>::checkCompatibility()
{
    Mat2D <T> temp(std::max(matrix.getM(), vector.getSize()), matrix.getN() + 1);

    for (size_t i = 0; i < matrix.getN(); ++i)
    {
        for (size_t j = 0; j < matrix.getM(); ++j)
        {
            temp[i][j] = matrix[i][j];
        }
    }

    for (size_t i = 0; i < vector.getSize(); ++i)
    {
        temp[i][temp.getM() - 1] = vector[i];
    }

    if (temp.getRank() == matrix.getRank())
    {
        return true;
    }
    return false;
}

template class SLAE <short int>;
template class SLAE <unsigned short int>;
template class SLAE <unsigned int>;
template class SLAE <int>;
template class SLAE <unsigned long int>;
template class SLAE <long int>;
template class SLAE <unsigned long long int>;
template class SLAE <long long int>;
template class SLAE <float>;
template class SLAE <double>;
template class SLAE <long double>;
