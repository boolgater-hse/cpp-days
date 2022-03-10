#include "Triangle.hpp"

Point2D::Point2D(const double x, const double y)
{
    this->x = x;
    this->y = y;
}

Point2D::Point2D()
{
    this->x = 0;
    this->y = 0;
}

Triangle::Triangle(Point2D coord1, Point2D coord2, Point2D coord3)
{
    double AB = std::sqrt(std::pow(coord2.x - coord1.x, 2) + std::pow(coord2.y - coord1.y, 2));
    double BC = std::sqrt(std::pow(coord3.x - coord2.x, 2) + std::pow(coord3.y - coord2.y, 2));
    double CA = std::sqrt(std::pow(coord3.x - coord1.x, 2) + std::pow(coord3.y - coord1.y, 2));

    if (AB + BC <= CA || BC + CA <= AB || CA + AB <= BC)
    {
        return;
    }

    this->id = counter++;
    this->valid = true;

    this->coord1 = coord1;
    this->coord2 = coord2;
    this->coord3 = coord3;
}

double Triangle::getPerimeter()
{
    double AB = std::sqrt(std::pow(coord2.x - coord1.x, 2) + std::pow(coord2.y - coord1.y, 2));
    double BC = std::sqrt(std::pow(coord3.x - coord2.x, 2) + std::pow(coord3.y - coord2.y, 2));
    double CA = std::sqrt(std::pow(coord3.x - coord1.x, 2) + std::pow(coord3.y - coord1.y, 2));

    return AB + BC + CA;
}

bool Triangle::isValid()
{
    return this->valid;
}
