#include <iostream>
#include "Mat2D.hpp"
#include "SLAE.hpp"

using namespace std;

int main()
{
    Mat2D mat = {{1,34,4}, {66,5,6}, {2,0,2}};
    VecND vec = {33,44,55};

//    srand(time(0));

//    mat.input();
//    vec.input();

//    for (int i = 0; i < mat.getN(); ++i)
//    {
//        for (int j = 0; j < mat.getM(); ++j)
//        {
//            mat[i][j] = rand() % 10 + 1;
//        }
//    }
//
//    for (int i = 0; i < vec.getSize(); ++i)
//    {
//        vec[i] = rand() % 20 + 1;
//    }

    vec.output();
    mat.output();

    SLAE eqs(mat, vec);

    double* a = eqs.solveByCramersRule();

    cout << endl;
    for (int i = 0; i < eqs.getNumberOfRoots(); ++i)
    {
        cout << a[i] << ' ';
    }
    delete[] a;

    return 0;
}
