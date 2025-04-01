#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

class ShapeException : public std::exception {
public:
    explicit ShapeException(const std::string& message) : msg(message) {}
    const char* what() const noexcept override {
        return msg.c_str();
    }
private:
    std::string msg;
};

class InvalidChoiceException : public std::exception {
public:
    explicit InvalidChoiceException(const std::string& message) : msg(message) {}
    const char* what() const noexcept override {  //check
        return msg.c_str();
    }
private:
    std::string msg;
};


class InvalidParameterException : public ShapeException {
public:
    explicit InvalidParameterException(const std::string& message) : ShapeException(message) {} //check
};

#endif 