#ifndef PRACTICE_05_SLAE_HPP
#define PRACTICE_05_SLAE_HPP


#include <vector>

class SLAE
{
private:
    Mat2D matrix;
    VecND vector;
public:
    SLAE(const Mat2D& _matrix, const VecND& _vector);

    double* solveByCramersRule();

    bool checkCompatibility();
};


#endif //PRACTICE_05_SLAE_HPP
