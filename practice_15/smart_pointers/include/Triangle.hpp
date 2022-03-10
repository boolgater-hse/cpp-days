#ifndef PRACTICE_15_TRIANGLE_HPP
#define PRACTICE_15_TRIANGLE_HPP


#include <cmath>
#include "Shape.hpp"

class Point2D
{
public:
    double x;
    double y;

    Point2D(double x, double y);

    Point2D();
};

class Triangle : public Shape
{
private:
    Point2D coord1;
    Point2D coord2;
    Point2D coord3;
public:
    Triangle(Point2D coord1, Point2D coord2, Point2D coord3);

    Triangle(const Triangle& other) : Triangle(other.coord1, other.coord2, other.coord3)
    {
    }

    double getPerimeter() override;

    bool isValid() override;
};


#endif //PRACTICE_15_TRIANGLE_HPP
