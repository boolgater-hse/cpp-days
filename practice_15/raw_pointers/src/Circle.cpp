#include "Circle.hpp"

Circle::Circle(double radius)
{
    if (radius < 0)
    {
        return;
    }

    this->id = counter++;
    this->valid = true;

    this->radius = radius;
}

double Circle::getPerimeter()
{
    return M_PI * (2 * radius);
}

bool Circle::isValid()
{
    return this->valid;
}
