#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
#include "point.h"
#include "exception.h"
#include <iostream>

class Circle : public Shape {
    Point center;
    double radius;
public:
    Circle();
    Circle(const std::string& name, const Point& center, double radius);
    double perimeter() const override;
    void print(std::ostream& os) const override;
    std::string getType() const override;
    void input(std::istream& is) override;
};

#endif