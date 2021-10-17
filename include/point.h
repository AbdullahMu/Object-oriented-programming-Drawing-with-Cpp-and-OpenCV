#ifndef POINT_H
#define POINT_H

#include <array>

struct Point
{
    //constructors
    Point() {}
    // Point(int point[2]) : x(point[0]), y(point[1]) {}
    Point(std::array<int, 2> point) : x(point[0]), y(point[1]) {}
    // Point(std::vector<int> point) : x(point[0]), y(point[1]) {}
    // member objects
    int x;
    int y;
};

#endif // POINT_H