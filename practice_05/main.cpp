#include <iostream>
#include "Mat2D.hpp"
#include "SLAE.hpp"

using namespace std;

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
    cout << "Matrix:" << endl;
    mat.output();

    cout << "Rows num: " << mat.getN() << endl;
    cout << "Cols num: " << mat.getM() << endl;
    cout << "Det: " << mat.getDeterminant() << endl;
    cout << "Rank: " << mat.getRank() << endl;
    cout << "Zero rows? " << mat.checkZeroRows() << endl;

    cout << endl;

    VecND vec = {4, 6, 3, 5, 2};

//    vec.input();
    cout << "Vector:" << endl;
    vec.output();

    cout << "Vector size: " << vec.getSize() << endl;

    cout << endl;

    cout << "Multiplying vector by number" << endl;
    VecND vec_mult = vec * 3;
    vec_mult.output();

    cout << "Second matrix:" << endl;
    Mat2D mat2 =
            {{3, 7, 9, 6, 3},
             {6, 5, 6, 2, 4},
             {6, 1, 8, 9, 2},
             {8, 7, 3, 1, 6},
             {4, 8, 4, 8, 5}};
    mat2.output();

    cout << "Matrix power 3:" << endl;
    Mat2D mat_pow = mat ^ 3;
    mat_pow.output();

    cout << "Inverse matrix:" << endl;
    Mat2D mat_inv = mat.getInverse();
    mat_inv.output();

    cout << "Matrix adding:" << endl;
    mat = mat + mat2;
    mat.output();

    cout << "Matrix multiplication:" << endl;
    mat = mat * mat2;
    mat.output();

    cout << "Multiplying matrix by number:" << endl;
    mat = mat * 2;
    mat.output();

    cout << "Matrix transpose:" << endl;
    mat = mat.transpose();
    mat.output();

    cout << "SLAE solution for matrix and vector:" << endl;
    SLAE eqs(mat, vec);

    mat.output();
    vec.output();

    double* a = eqs.solveByCramersRule();

    for (int i = 0; i < eqs.getNumberOfRoots(); ++i)
    {
        cout << a[i] << ' ';
    }
    delete[] a;

    cout << endl << endl;

    cout << "Multiplying matrix by vector:" << endl;
    mat = mat * vec;
    mat.output();

    cout << "Done";

    return 0;
}
