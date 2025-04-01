#include "shape.h"

Shape::Shape() : name() {}

Shape::Shape(const std::string& name) : name(name) {}

std::ostream& operator<<(std::ostream& os, const Shape& shape) {
    shape.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Shape& shape) {
    shape.input(is);
    return is;
}