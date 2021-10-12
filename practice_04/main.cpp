#include <iostream>
#include "Vec3D.hpp"
#include "DynArray.hpp"

using namespace std;

int main()
{
    cout << "Vec3D Test:" << endl;

    Vec3D vec1(1.0, 2.0, 3.0);
    Vec3D vec2(6.0, 5.0, 4.0);
    Vec3D vec3(4.0, 3.0, 7.0);

    double dot_prod = vec1 * vec2;
    cout << dot_prod << endl;

    Vec3D cross_prod = vec1 & vec2;
    cout << cross_prod.x << ' ' << cross_prod.y << ' ' << cross_prod.z;
    cout << endl;

    Vec3D cross_prod_2 = vec1 & vec2 & vec3;
    cout << cross_prod_2.x << ' ' << cross_prod_2.y << ' ' << cross_prod_2.z;
    cout << endl;


    cout << endl << "DynArray Test:" << endl;

    cout << "No size ctor: ";
    DynArray one;
    for (int i = 0; i < one.size(); ++i)
    {
        one[i] = 10 + i;
    }
    cout << "Done" << endl;

    cout << "Size ctor: ";
    DynArray two(3);
    for (int i = 0; i < two.size(); ++i)
    {
        two[i] = 20 + i;
    }
    cout << "Done" << endl;

    cout << "Copy ctor: " << endl;
    DynArray three(two);
    for (int i = 0; i < three.size(); ++i)
    {
        cout << three[i] << ' ';
    }
    cout << endl;
    cout << "Done" << endl;

    cout << "Concat and equal: " << endl;
    DynArray four = two + three;
    for (int i = 0; i < four.size(); ++i)
    {
        cout << four[i] << ' ';
    }
    cout << endl;
    cout << "Done" << endl;

    cout << "Left rotation: " << endl;
    four = four << 1;
    for (int i = 0; i < four.size(); ++i)
    {
        cout << four[i] << ' ';
    }
    cout << endl;
    cout << "Done";
    cout << endl;

    cout << "Right rotation: " << endl;
    cout << "Before" << endl;
    for (int i = 0; i < one.size(); ++i)
    {
        cout << one[i] << ' ';
    }
    cout << endl;
    cout << "After" << endl;
    one = one >> 4;
    for (int i = 0; i < one.size(); ++i)
    {
        cout << one[i] << ' ';
    }
    cout << endl;
    cout << "Done";
    cout << endl;

    cout << "Alives: " << DynArray::alive << endl;
    cout << "Done";

    return 0;
}
