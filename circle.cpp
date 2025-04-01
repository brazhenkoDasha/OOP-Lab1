#include "circle.h"
#include <cmath>
#include <iostream>

Circle::Circle() : Shape(), center(), radius() {}

Circle::Circle(const std::string& name, const Point& center, double radius)
    : Shape(name), center(center), radius(radius) {
    if (radius <= 0) {
        throw InvalidParameterException("Radius must be positive");
    }
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::print(std::ostream& os) const {
    os << "Circle: " << name << ", Center: (" << center.getX() << ", " << center.getY() << "), Radius: " << radius;
}

std::string Circle::getType() const {
    return "Circle";
}

void Circle::input(std::istream& is) {
    std::cout << "Input name, x, y and radius\n";
    is >> name >> center >> radius;
    if (radius <= 0) {
        throw InvalidParameterException("Radius must be positive");
    }
}