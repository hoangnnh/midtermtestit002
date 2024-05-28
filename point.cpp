#include "point.h"

#include <cmath>

point::Point::Point() {
    x = 0.0;
    y = 0.0;
}

point::Point::Point(float x, float y) {
    this->x = x;
    this->y = y;
}

float point::distanceBetween(const Point p1, const Point p2) {
    return sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}