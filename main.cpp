#include <fstream>
#include <iostream>
#include <vector>

#include "circle.h"
#include "point.h"
#include "triangle.h"


using namespace std;
using namespace point;

int main() {
    int n;
    cout << "Nhap N: ";
    cin >> n;

    vector<Triangle> triangleList;
    vector<Circle> circleList;

    for (int i = 0; i < n; i++) {

        cout << "Hinh thu " << i + 1 << " (0: Hinh tron. 1: Hinh tam giac): ";
        int type;
        cin >> type;

        switch (type) {
            case 0: {
                float x, y;
                cout << "Nhap tam duong tron (x, y): ";
                cin >> x >> y;

                Point p = Point(x, y);

                float r;
                cout << "Ban kinh: ";
                cin >> r;
                Circle c = Circle(p, r);

                circleList.push_back(c);
            } break;

            case 1: {
                float x1, y1;
                cout << "Nhap toa do diem A (xA, yA): ";
                cin >> x1 >> y1;
                Point A = Point(x1, y1);

                float x2, y2;
                cout << "Nhap toa do diem B (xB, yB): ";
                cin >> x2 >> y2;
                Point B = Point(x2, y2);

                float x3, y3;
                cout << "Nhap toa do diem C (xC, yC): ";
                cin >> x3 >> y3;
                Point C = Point(x3, y3);

                Triangle t = Triangle(A, B, C);

                triangleList.push_back(t);
            } break;

            default:
                break;
        }
    }

    cout << "Thong tin cua " << n << " hinh da nhap:\n";

    Triangle maxAreaTriangle;
    Circle maxAreaCircle;

    if (!triangleList.empty()) {
        maxAreaTriangle = triangleList[0];
        int i = 1;

        for (const auto &t: triangleList) {
            if (maxAreaTriangle.getArea() < t.getArea())
                maxAreaTriangle = t;
            cout << "Hinh tam giac thu " << i << ":\n";
            t.printData();
            cout << "\n";
            i++;
        }
    } else {
        cout << "Khong co hinh tam giac nao duoc nhap.\n";
    }

    if (!circleList.empty()) {
        maxAreaCircle = circleList[0];
        int i = 1;

        for (const auto &c: circleList) {
            if (maxAreaCircle.getArea() < c.getArea())
                maxAreaCircle = c;
            cout << "Hinh tron thu " << i << ":\n";
            c.printData();
            cout << "\n";
            i++;
        }
    } else {
        cout << "Khong co hinh tron nao duoc nhap.\n";
    }

    ofstream file("RESULT.OUT");


    cout << "Hinh co dien tich lon nhat:\n";
    if (maxAreaCircle.getArea() < maxAreaTriangle.getArea()) {
        file << "Hinh tam giac:\n";
        file << "Toa do diem A: (" << maxAreaTriangle.getPointA().x << ", " << maxAreaTriangle.getPointA().y << ")\n";
        file << "Toa do diem B: (" << maxAreaTriangle.getPointB().x << ", " << maxAreaTriangle.getPointB().y << ")\n";
        file << "Toa do diem C: (" << maxAreaTriangle.getPointC().x << ", " << maxAreaTriangle.getPointC().y << ")\n";
        file << "Chu vi: " << maxAreaTriangle.getPerimeter() << "\n";
        file << "Dien tich: " << maxAreaTriangle.getArea() << "\n";
        file << "Loai tam giac: " << maxAreaTriangle.getTypeAsString() << "\n";
    } else {

        file << "Hinh tron:\n";
        file << "Toa do tam duong tron: (" << maxAreaCircle.getCenter().x << ", " << maxAreaCircle.getCenter().y << ")\n";
        file << "Ban kinh: " << maxAreaCircle.getRadius() << "\n";
        file << "Chu vi: " << maxAreaCircle.getPerimeter() << "\n";
        file << "Dien tich: " << maxAreaCircle.getArea() << "\n";
    }


    file.close();

    return 0;
}