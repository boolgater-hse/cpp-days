#include "Vec3D.hpp"


Vec3D::Vec3D() : x(0.0), y(0.0), z(0.0) {}

Vec3D::Vec3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

double Vec3D::operator*(const Vec3D& vec)
{
    return x * vec.x + y * vec.y + z * vec.z;
}

Vec3D Vec3D::operator&(const Vec3D& vec)
{
    Vec3D temp;
    temp.x = y * vec.z - z * vec.y;
    temp.y = -1 * (x * vec.z - z * vec.x);
    temp.z = x * vec.y - y * vec.x;
    return temp;
}
