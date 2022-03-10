#ifndef PRACTICE_04_VEC3D_HPP
#define PRACTICE_04_VEC3D_HPP


class Vec3D
{
public:
    double x, y, z;

    Vec3D();

    Vec3D(double _x, double _y, double _z);

    double operator*(const Vec3D& vec);

    Vec3D operator&(const Vec3D& vec);
};


#endif //PRACTICE_04_VEC3D_HPP
