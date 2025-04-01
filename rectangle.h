#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"
#include "point.h"
#include "exception.h"
#include <iostream>

class Rectangle : public Shape {
    Point leftPoint, rightPoint;

public:
    Rectangle();
    Rectangle(const std::string& name, const Point& leftPoint, const Point& rightPoint);
    double perimeter() const override;
    std::string getType() const override;
    void print(std::ostream& os) const override;
    void input(std::istream& is) override;
    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);
};

#endif