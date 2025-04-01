#include "rectangle.h"
#include <iostream>
#include "readInput.h"

Rectangle::Rectangle() : Shape("Unnamed"), leftPoint(), rightPoint() {}

Rectangle::Rectangle(const std::string& name, const Point& leftPoint, const Point& rightPoint)
    : Shape(name), leftPoint(leftPoint), rightPoint(rightPoint) {
    if (leftPoint.getX() >= rightPoint.getX() || leftPoint.getY() <= rightPoint.getY()) {
        throw InvalidParameterException("Invalid rectangle coordinates: x1 must be less than x2 and y1 must be greater than y2");
    }
}

double Rectangle::perimeter() const {
    return 2 * ((rightPoint.getX() - leftPoint.getX()) + (leftPoint.getY() - rightPoint.getY()));
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle: " << name << ", Left Point: " << leftPoint << ", Right Point: " << rightPoint;
}

std::string Rectangle::getType() const {
    return "Rectangle";
}

void Rectangle::input(std::istream& is) {
    is >> name;
    leftPoint = readInput<Point>();
    rightPoint = readInput<Point>();
    if (leftPoint.getX() >= rightPoint.getX() || leftPoint.getY() <= rightPoint.getY()) {
        throw InvalidParameterException("Invalid rectangle coordinates: x1 must be less than x2 and y1 must be greater than y2");
    }
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
    rectangle.input(is);
    return is;
}