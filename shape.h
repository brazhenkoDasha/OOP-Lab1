#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <ostream>

class Shape {
protected:
    std::string name;
public:
    Shape();
    Shape(const std::string& name);
    virtual double perimeter() const = 0;
    virtual ~Shape() = default;
    virtual std::string getType() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void input(std::istream& is) = 0;
    friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
    friend std::istream& operator>>(std::istream& is, Shape& shape);
};

#endif