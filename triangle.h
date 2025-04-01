#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"
#include "point.h"
#include "exception.h"

class Triangle : public Shape {
    Point point1, point2, point3;

public:
    Triangle();
    Triangle(const std::string& name, const Point& point1, const Point& point2, const Point& point3);
    double perimeter() const override;
    void print(std::ostream& os) const override;
    std::string getType() const override;
    void input(std::istream& is) override;
};

#endif