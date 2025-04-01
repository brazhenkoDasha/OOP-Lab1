#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
    double x, y;
public:
    Point();
    Point(double x, double y);

    double getX() const;
    double getY() const;

    friend std::istream& operator>>(std::istream& is, Point& point);
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

#endif