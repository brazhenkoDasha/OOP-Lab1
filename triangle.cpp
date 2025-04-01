#include "triangle.h"
#include <iostream>
#include <cmath>
#include "readInput.h"

Triangle::Triangle() : Shape("Unnamed"), point1(), point2(), point3() {}

Triangle::Triangle(const std::string& name, const Point& point1, const Point& point2, const Point& point3)
    : Shape(name), point1(point1), point2(point2), point3(point3) {}
    
double Triangle::perimeter() const {
    double a = std::sqrt(std::pow(point2.getX() - point1.getX(), 2) + std::pow(point2.getY() - point1.getY(), 2));
    double b = std::sqrt(std::pow(point3.getX() - point2.getX(), 2) + std::pow(point3.getY() - point2.getY(), 2));
    double c = std::sqrt(std::pow(point3.getX() - point1.getX(), 2) + std::pow(point3.getY() - point1.getY(), 2));
    return a + b + c;
}

std::string Triangle::getType() const {
    return "Triangle";
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle: " << name << ", Coordinates: " << point1 << ", " << point2 << ", " << point3;
}

void Triangle::input(std::istream& is) {
    is >> name;
    point1 = readInput<Point>();
    point2 = readInput<Point>();
    point3 = readInput<Point>();
}