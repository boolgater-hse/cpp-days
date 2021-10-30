#ifndef PRACTICE_06_SLAE_HPP
#define PRACTICE_06_SLAE_HPP


template <typename T>
class SLAE
{
private:
    Mat2D <T> matrix;
    VecND <T> vector;
    size_t lastRootsN;
public:
    SLAE(const Mat2D <T>& _matrix, const VecND <T>& _vector);

    std::vector <long double> solveByCramersRule();

    size_t getNumberOfRoots() const;

    bool checkCompatibility();
};


#endif //PRACTICE_06_SLAE_HPP
