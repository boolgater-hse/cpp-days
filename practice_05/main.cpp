#include <iostream>
#include "Mat2D.hpp"
#include "SLAE.hpp"

using namespace std;

int main()
{
    Mat2D mat =
            {{3, 6, 2},
             {4, 6, 6},
             {2, 6, 8}};

//    mat.input();
    cout << "Matrix:" << endl;
    mat.output();

    cout << "Rows num: " << mat.getN() << endl;
    cout << "Cols num: " << mat.getM() << endl;
    cout << "Det: " << mat.getDeterminant() << endl;
    cout << "Rank: " << mat.getRank() << endl;
    cout << "Zero rows? " << mat.checkZeroRows() << endl;

    cout << endl;

    VecND vec = {4, 6, 3};

//    vec.input();
    cout << "Vector:" << endl;
    vec.output();

    cout << "Vector size: " << vec.getSize() << endl;

    cout << endl;

    cout << "Vector on number multiplying:" << endl;
    VecND vec_mult = vec * 3;
    vec_mult.output();

    cout << "Second matrix:" << endl;
    Mat2D mat2 =
            {{5, 2, 2},
             {9, 3, 3},
             {1, 6, 0}};
    mat2.output();

    cout << "Matrix pow:" << endl;
    Mat2D mat_pow =
            {{5, 2, 2},
             {9, 4, 3},
             {1, 2, 9}};
    mat_pow = mat_pow ^ 3;
    mat_pow.output();

    cout << "Inverse matrix:" << endl;
    Mat2D mat_inv = mat.getInverse();
    mat_inv.output();

    cout << "Matrix adding:" << endl;
    mat = mat + mat2;
    mat.output();

    cout << "Matrix on matrix multiplying:" << endl;
    mat = mat * mat2;
    mat.output();

    cout << "Matrix on number multiplying:" << endl;
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

    cout << "Vector multiple matrix:" << endl;
    mat = mat * vec;
    mat.output();

    cout << "Done";

    return 0;
}
