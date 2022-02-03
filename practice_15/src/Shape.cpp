#include "Shape.hpp"

Shape::Shape()
{
    valid = false;
    id = 0;
}

size_t Shape::getId()
{
    return this->id;
}

Shape::~Shape()
{
}
