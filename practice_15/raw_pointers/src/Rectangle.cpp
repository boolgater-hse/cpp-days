#include "Rectangle.hpp"

Rectangle::Rectangle(double width, double height)
{
    if (width < 0 || height < 0)
    {
        return;
    }

    this->id = counter++;
    this->valid = true;

    this->width = width;
    this->height = height;
}

Rectangle::~Rectangle() = default;

double Rectangle::getPerimeter()
{
    return 2 * (this->width + this->height);
}

bool Rectangle::isValid()
{
    return this->valid;
}
