#ifndef PRACTICAL_ASIGNMENT_TRIANGLE_H
#define PRACTICAL_ASIGNMENT_TRIANGLE_H

#include "point.h"
#include <string>

using namespace point;

enum TRIANGLE_TYPE {
    NormalTriangle,
    IsoscelesTriangle,
    IsoscelesRightTriangle,
    RightTriangle,
    EquilateralTriangle
};

class Triangle {
private:
    Point A;
    Point B;
    Point C;

    float AB;
    float AC;
    float BC;

    float perimeter;
    float area;
    TRIANGLE_TYPE type;

    bool isRightTriangle() const;

public:
    Triangle();
    Triangle(Point, Point, Point);
    Point getPointA() const;
    Point getPointB() const;
    Point getPointC() const;
    float getPerimeter() const;
    float getArea() const;
    std::string getTypeAsString() const;
    void printData() const;
};


#endif//PRACTICAL_ASIGNMENT_TRIANGLE_H
