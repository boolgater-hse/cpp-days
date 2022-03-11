#ifndef PRACTICE_15_RECTANGLE_HPP
#define PRACTICE_15_RECTANGLE_HPP


#include "Shape.hpp"

class Rectangle : public Shape
{
private:
    double width;
    double height;
public:
    Rectangle(double width, double height);

    Rectangle(double side) : Rectangle(side, side)
    {
    }

    Rectangle(const Rectangle& other) : Rectangle(other.width, other.height)
    {
    }

    ~Rectangle() override;

    double getPerimeter() override;

    static bool isValid(double width, double height);
};

#endif //PRACTICE_15_RECTANGLE_HPP
