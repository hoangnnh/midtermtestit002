#ifndef PRACTICAL_ASIGNMENT_CIRCLE_H
#define PRACTICAL_ASIGNMENT_CIRCLE_H

#define PI 3.14

#include "point.h"

class Circle {
private:
    point::Point center;
    float radius;
    float perimeter;
    float area;

public:
    Circle();
    Circle(point::Point, float);
    point::Point getCenter() const;
    float getRadius() const;
    float getPerimeter() const;
    float getArea() const;
    void printData() const;
};

#endif//PRACTICAL_ASIGNMENT_CIRCLE_H
