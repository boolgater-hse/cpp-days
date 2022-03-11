#include "Shape.hpp"

Shape::Shape()
{
    id = 0;
}

size_t Shape::getId()
{
    return this->id;
}

Shape::~Shape()
{
}

size_t Shape::counter = 0;
