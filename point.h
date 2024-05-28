#ifndef PRACTICAL_ASIGNMENT_POINT_H
#define PRACTICAL_ASIGNMENT_POINT_H

namespace point {

    struct Point {
        float x;
        float y;


        Point();
        Point(float, float);
    };

    float distanceBetween(Point, Point);

}

#endif//PRACTICAL_ASIGNMENT_POINT_H
