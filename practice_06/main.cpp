#include <iostream>
#include "DynArray.hpp"
#include "Queue.hpp"
#include "Mat2D.hpp"
#include "SLAE.hpp"

void DynArray_TestSuite();
void Queue_TestSuite();
void Mat2D_SLAE_TestSuite();

int main()
{
    DynArray_TestSuite();
    Queue_TestSuite();
    Mat2D_SLAE_TestSuite();

    return 0;
}

void DynArray_TestSuite()
{
    std::cout << "Int array with 5 elems:" << std::endl;
    DynArray <int> a(5);

    for (int i = 0; i < 5; ++i)
    {
        a[i] = i;
    }
    a.output();

    std::cout << "Enter n and then enter n elems in array:" << std::endl;
    DynArray <int> b;
    b.input();

    std::cout << "Your array:" << std::endl;
    b.output();

    std::cout << "Move 2 elems to the left:" << std::endl;
    b = b << 2;
    b.output();

    std::cout << "Move 6 elems to the right:" << std::endl;
    b = b >> 6;
    b.output();

    std::cout << "Concat two arrays:" << std::endl;
    b = a + b;
    b.output();

    std::cout << "Done" << std::endl << std::endl;
}

void Queue_TestSuite()
{
    std::cout << "Float queue init" << std::endl;
    Queue <float> q;

    size_t n;
    std::cout << "Enter n and n elems in queue:" << std::endl;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        float temp;
        std::cin >> temp;
        q.insert(temp);
    }

    std::cout << "Your queue:" << std::endl;
    q.output();

    std::cout << "Is empty? " << (q.isEmpty() ? "True" : "False") << std::endl;
    std::cout << "Size: " << q.getSize() << std::endl;
    std::cout << "Pop 2 elems:" << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << std::endl;

    std::cout << "Current queue:" << std::endl;
    q.output();

    std::cout << "Done" << std::endl << std::endl;
}

void Mat2D_SLAE_TestSuite()
{
    std::cout << "Matrix:" << std::endl;
    Mat2D <double> mat =
            {{4, 3, 0, 4, 7},
             {3, 2, 2, 7, 7},
             {9, 5, 7, 5, 8},
             {1, 1, 4, 4, 4},
             {1, 6, 6, 4, 2}};
    mat.output();

    std::cout << "Rows num: " << mat.getN() << std::endl;
    std::cout << "Cols num: " << mat.getM() << std::endl;
    std::cout << "Det: " << mat.getDeterminant() << std::endl;
    std::cout << "Rank: " << mat.getRank() << std::endl;

    std::cout << std::endl;

    std::cout << "Matrix power 3:" << std::endl;
    Mat2D <double> mat_pow = mat ^ 3;
    mat_pow.output();

    std::cout << "Inverse matrix:" << std::endl;
    Mat2D <double> mat_inv = mat.getInverse();
    mat_inv.output();

    std::cout << "Vector:" << std::endl;
    VecND <double> vec = {4, 6, 3, 5, 2};
    vec.output();

    std::cout << "Vector size: " << vec.getSize() << std::endl;

    std::cout << std::endl;

    std::cout << "Multiplying vector by number:" << std::endl;
    VecND <double> vec_mult = vec * 3;
    vec_mult.output();

    std::cout << "Second matrix:" << std::endl;
    Mat2D <double> mat2 =
            {{3, 7, 9, 6, 3},
             {6, 5, 6, 2, 4},
             {6, 1, 8, 9, 2},
             {8, 7, 3, 1, 6},
             {4, 8, 4, 8, 5}};
    mat2.output();

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
    SLAE <double> eqs(mat, vec);

    mat.output();
    vec.output();

    std::vector <long double> solution = eqs.solveByCramersRule();

    for (int i = 0; i < eqs.getNumberOfRoots(); ++i)
    {
        std::cout << solution[i] << ' ';
    }

    std::cout << std::endl << std::endl;

    std::cout << "Multiplying matrix by vector:" << std::endl;
    mat = mat * vec;
    mat.output();

    std::cout << "Done";
}
