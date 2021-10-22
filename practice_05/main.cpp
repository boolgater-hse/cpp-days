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

    cout << "Second matrix:" << endl;
    Mat2D mat2 =
            {{5, 2, 2},
             {9, 3, 3},
             {1, 6, 0}};
    mat2.output();

    cout << "Matrix adding:" << endl;
    mat = mat + mat2;
    mat.output();

    cout << "Matrix multiplying:" << endl;
    mat = mat * mat2;
    mat.output();

    cout << "Matrix transpose:" << endl;
    mat = mat.transpose();
    mat.output();

    cout << "SLAE solution for matrix and vector:" << endl;
    SLAE eqs(mat, vec);

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
