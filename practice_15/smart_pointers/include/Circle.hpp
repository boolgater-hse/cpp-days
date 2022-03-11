#ifndef PRACTICE_15_CIRCLE_HPP
#define PRACTICE_15_CIRCLE_HPP


#include "Shape.hpp"
#define M_PI 3.14159265358979323846

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(double radius);

    Circle(const Circle& other) : Circle(other.radius)
    {
    }

    double getPerimeter() override;

    static bool isValid(double radius);
};


#endif //PRACTICE_15_CIRCLE_HPP
