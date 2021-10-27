#include <iostream>
#include "Mat2D.hpp"
#include "SLAE.hpp"

int main()
{
//    Mat2D mat =
//            {{3, 6, 2},
//             {4, 6, 6},
//             {2, 6, 8}};
    Mat2D mat =
            {{4, 3, 0, 4, 7},
             {3, 2, 2, 7, 7},
             {9, 5, 7, 5, 8},
             {1, 1, 4, 4, 4},
             {1, 6, 6, 4, 2}};

//    mat.input();
    std::cout << "Matrix:" << std::endl;
    mat.output();

    std::cout << "Rows num: " << mat.getN() << std::endl;
    std::cout << "Cols num: " << mat.getM() << std::endl;
    std::cout << "Det: " << mat.getDeterminant() << std::endl;
    std::cout << "Rank: " << mat.getRank() << std::endl;
    std::cout << "Zero rows? " << mat.checkZeroRows() << std::endl;

    std::cout << std::endl;

    VecND vec = {4, 6, 3, 5, 2};

//    vec.input();
    std::cout << "Vector:" << std::endl;
    vec.output();

    std::cout << "Vector size: " << vec.getSize() << std::endl;

    std::cout << std::endl;

    std::cout << "Multiplying vector by number" << std::endl;
    VecND vec_mult = vec * 3;
    vec_mult.output();

    std::cout << "Second matrix:" << std::endl;
    Mat2D mat2 =
            {{3, 7, 9, 6, 3},
             {6, 5, 6, 2, 4},
             {6, 1, 8, 9, 2},
             {8, 7, 3, 1, 6},
             {4, 8, 4, 8, 5}};
    mat2.output();

    std::cout << "Matrix power 3:" << std::endl;
    Mat2D mat_pow = mat ^ 3;
    mat_pow.output();

    std::cout << "Inverse matrix:" << std::endl;
    Mat2D mat_inv = mat.getInverse();
    mat_inv.output();

    std::cout << "Matrix adding:" << std::endl;
    mat = mat + mat2;
    mat.output();

    std::cout << "Matrix multiplication:" << std::endl;
    mat = mat * mat2;
    mat.output();

    std::cout << "Multiplying matrix by number:" << std::endl;
    mat = mat * 2;
    mat.output();

    std::cout << "Matrix transpose:" << std::endl;
    mat = mat.transpose();
    mat.output();

    std::cout << "SLAE solution for matrix and vector:" << std::endl;
    SLAE eqs(mat, vec);

    mat.output();
    vec.output();

    double* a = eqs.solveByCramersRule();

    for (int i = 0; i < eqs.getNumberOfRoots(); ++i)
    {
        std::cout << a[i] << ' ';
    }
    delete[] a;

    std::cout << std::endl << std::endl;

    std::cout << "Multiplying matrix by vector:" << std::endl;
    mat = mat * vec;
    mat.output();

    std::cout << "Done";

    return 0;
}
