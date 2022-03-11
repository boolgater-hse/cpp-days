#include "Circle.hpp"

Circle::Circle(double radius)
{
    if (!Circle::isValid(radius))
    {
        return;
    }

    this->id = counter++;

    this->radius = radius;
}

double Circle::getPerimeter()
{
    return M_PI * (2 * radius);
}

bool Circle::isValid(double radius)
{
    if (radius < 0)
    {
        return false;
    }
    return true;
}
