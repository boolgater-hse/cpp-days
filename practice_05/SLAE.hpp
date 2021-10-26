#ifndef PRACTICE_05_SLAE_HPP
#define PRACTICE_05_SLAE_HPP


#include <vector>

class SLAE
{
private:
    Mat2D matrix;
    VecND vector;
    size_t lastRootsN;
public:
    SLAE(const Mat2D& _matrix, const VecND& _vector);

    double* solveByCramersRule();

    size_t getNumberOfRoots() const;

    bool checkCompatibility();
};


#endif //PRACTICE_05_SLAE_HPP
