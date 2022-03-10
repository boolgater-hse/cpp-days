#ifndef PRACTICE_15_SHAPE_HPP
#define PRACTICE_15_SHAPE_HPP


#include <cstddef>

class Shape
{
protected:
    bool valid;
    size_t id;
public:
    Shape();

    static size_t counter;

    size_t getId();

    virtual double getPerimeter() = 0;

    virtual bool isValid() = 0;

    virtual ~Shape();
};


#endif //PRACTICE_15_SHAPE_HPP
