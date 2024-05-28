#include "triangle.h"
#include <cmath>
#include <iostream>

using namespace point;

Triangle::Triangle() {}

Triangle::Triangle(Point A, Point B, Point C) {
    this->A = A;
    this->B = B;
    this->C = C;

    AB = point::distanceBetween(A, B);
    AC = point::distanceBetween(A, C);
    BC = point::distanceBetween(B, C);

    perimeter = AB + AC + BC;

    // Calculate area using Heron's Formula:
    float s = (AB + AC + BC) / 2;
    area = std::sqrt(s * (s - AB) * (s - AC) * (s - BC));

    if (AB == AC && AB == BC) {
        type = EquilateralTriangle;
    } else if ((AB == AC || AB == BC || AC == BC)) {
        if (isRightTriangle())
            type = IsoscelesRightTriangle;
        else
            type = IsoscelesTriangle;
    } else if (isRightTriangle())
        type = RightTriangle;
    else
        type = NormalTriangle;
}

bool Triangle::isRightTriangle() const {
    if ((std::pow(AB, 2) + std::pow(AC, 2) == std::pow(BC, 2)) || (std::pow(AB, 2) + std::pow(BC, 2) == std::pow(AC, 2)) || (std::pow(AC, 2) + std::pow(BC, 2) == std::pow(AB, 2))) {
        return true;
    }

    return false;
}

Point Triangle::getPointA() const {
    return A;
}

Point Triangle::getPointB() const {
    return B;
};

Point Triangle::getPointC() const {
    return C;
}

float Triangle::getPerimeter() const {
    return perimeter;
}

float Triangle::getArea() const {
    return area;
}

std::string Triangle::getTypeAsString() const {
    if (type == NormalTriangle)
        return "Tam giac thuong";
    if (type == IsoscelesTriangle)
        return "Tam giac can";
    if (type == IsoscelesRightTriangle)
        return "Tam giac vuong can";
    if (type == RightTriangle)
        return "Tam giac vuong";
    return "Tam giac thuong";
}

void Triangle::printData() const {
    using std::cout;
    cout << "Toa do diem A: (" << A.x << ", " << A.y << ")\n";
    cout << "Toa do diem B: (" << B.x << ", " << B.y << ")\n";
    cout << "Toa do diem C: (" << C.x << ", " << C.y << ")\n";
    cout << "Chu vi: " << perimeter << "\n";
    cout << "Dien tich: " << area << "\n";
    cout << "Loai tam giac: ";
    if (type == EquilateralTriangle)
        cout << "Tam giac thuong";
    else if (type == IsoscelesTriangle)
        cout << "Tam giac can";
    else if (type == IsoscelesRightTriangle)
        cout << "Tam giac vuong can";
    else if (type == RightTriangle)
        cout << "Tam giac can";
    else
        cout << "Tam giac thuong";

    cout << "\n";
}