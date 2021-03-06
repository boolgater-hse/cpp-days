#include "Mat2D.hpp"
#include "SLAE.hpp"

SLAE::SLAE(const Mat2D& _matrix, const VecND& _vector)
{
    matrix = _matrix;
    vector = _vector;
    lastRootsN = 0;
}

std::unique_ptr <double[]> SLAE::solveByCramersRule()
{
    std::unique_ptr <double[]> answer = std::make_unique <double[]>(matrix.getN());
    for (size_t i = 0; i < matrix.getN(); ++i)
    {
        answer[i] = 0;
    }

    if (matrix.getN() != vector.getSize() || matrix.getN() != matrix.getM() || !checkCompatibility() || matrix.checkZeroRows())
    {
        return answer;
    }

    long double mainDeterminant = matrix.getDeterminant();

    for (size_t iteration = 0; iteration < matrix.getN(); ++iteration)
    {
        Mat2D temp = matrix;
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

size_t SLAE::getNumberOfRoots() const
{
    return this->lastRootsN;
}

bool SLAE::checkCompatibility()
{
    Mat2D temp(std::max(matrix.getM(), vector.getSize()), matrix.getN() + 1);

    for (size_t i = 0; i < temp.getN(); ++i)
    {
        for (size_t j = 0; j < temp.getM(); ++j)
        {
            temp[i][j] = 0;
        }
    }

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
