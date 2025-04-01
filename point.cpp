#include "point.h"
#include <iostream>
#include <limits>

Point::Point() : x(), y() {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

std::istream& operator>>(std::istream& is, Point& point) {
    return is >> point.x >> point.y;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    return os << "(" << point.getX() << ", " << point.getY() << ")";
}