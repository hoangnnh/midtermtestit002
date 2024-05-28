#include "circle.h"

#include <cmath>
#include <iostream>

Circle::Circle() {}

Circle::Circle(point::Point center, float radius) {
    this->center = center;
    this->radius = radius;

    this->perimeter = this->radius * 2 * PI;
    this->area = std::pow(this->radius, 2) * PI;
}

point::Point Circle::getCenter() const {
    return center;
}

float Circle::getPerimeter() const {
    return perimeter;
}

float Circle::getRadius() const {
    return radius;
}

float Circle::getArea() const {
    return area;
}

void Circle::printData() const {

    using std::cout;
    cout << "Tam duong tron: (" << center.x << ", "
         << center.y << ")\n";
    cout << "Ban kinh: " << radius << "\n";
    cout << "Chu vi: " << perimeter << "\n";
    cout << "Dien tich: " << area << "\n";
}