#include "shapeApp.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "readInput.h"
#include "exception.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <map>

ShapeApp::ShapeApp() {
    initializeShapesMap();
    initializeChoicesMap();
}

void ShapeApp::initializeShapesMap() {
    shapesMap[1] = &ShapeApp::addCircle;
    shapesMap[2] = &ShapeApp::addRectangle;
    shapesMap[3] = &ShapeApp::addTriangle;
}

void ShapeApp::initializeChoicesMap() {
    choicesMap[1] = &ShapeApp::secondChoice;
    choicesMap[2] = &ShapeApp::listFigures;
    choicesMap[3] = &ShapeApp::listFiguresWithPerimeter;
    choicesMap[4] = &ShapeApp::sortByPerimeter;
    choicesMap[5] = &ShapeApp::deleteFigureByNumber;
    choicesMap[6] = &ShapeApp::deleteFiguresWithPerimeterGreaterThan;
    choicesMap[7] = &ShapeApp::endApp;
}

void ShapeApp::secondChoice() {
    int choice;
    std::cout << "1: Circle\n"
              << "2: Rectangle\n"
              << "3: Triangle\n"
              << "Input number: ";
    choice = readInput<int>();
    auto it = shapesMap.find(choice);
    if (it != shapesMap.end()) {
        (this->*(it->second))();
    } else {
        throw InvalidParameterException("Incorrect number");
    }
}

void ShapeApp::firstChoice() {
    int choice;
    std::cout << "Menu:\n"
              << "1. Choose a shape in collection\n"
              << "2. List Figures\n"
              << "3. List Figures with Perimeter\n"
              << "4. Sort by Perimeter\n"
              << "5. Delete Figure by Number\n"
              << "6. Delete Figures with Perimeter Greater Than\n"
              << "7. Exit\n"
              << "Enter your choice: ";
    choice = readInput<int>();
    auto it = choicesMap.find(choice);
    if (it != choicesMap.end()) {
        (this->*(it->second))();
    } else {
        throw InvalidChoiceException("Incorrect number");
    }
}

void ShapeApp::endApp() {
    this->programState = STOPPED;
}

void ShapeApp::addCircle() {
    Circle* circle = new Circle();
    std::cin >> *circle;
    shapes.push_back(circle);
}

void ShapeApp::addRectangle() {
    Rectangle* rectangle = new Rectangle();
    std::cin >> *rectangle;
    shapes.push_back(rectangle);
}

void ShapeApp::addTriangle() {
    Triangle* triangle = new Triangle();
    std::cin >> *triangle;
    shapes.push_back(triangle);
}

void ShapeApp::deleteFiguresWithPerimeterGreaterThan() {
    double perimeterLimit;
    std::cout << "Enter perimeter limit: ";
    perimeterLimit = readInput<double>();
    for (auto i = shapes.begin(); i != shapes.end();) {
        if ((*i)->perimeter() > perimeterLimit) {
            delete *i;
            i = shapes.erase(i);
        } else {
            ++i;
        }
    }
    std::cout << "Figures with perimeter greater than " << perimeterLimit << " deleted\n";
}

void ShapeApp::listFigures() {
    for (Shape* shape : shapes) {
        std::cout << *shape << std::endl;
    }
}

void ShapeApp::listFiguresWithPerimeter() {
    for (size_t i = 0; i < shapes.size(); i++) {
        std::cout << i + 1 << ". ";
        shapes[i]->print(std::cout);
        std::cout << " Perimeter: " << shapes[i]->perimeter() << std::endl;
    }
}

void ShapeApp::sortByPerimeter() {
    std::sort(shapes.begin(), shapes.end(), [](Shape* a, Shape* b) {
        return a->perimeter() < b->perimeter();
    });
    std::cout << "Shapes sorted by perimeter\n";
}

void ShapeApp::deleteFigureByNumber() {
    size_t index;
    std::cout << "Enter figure number to delete: ";
    index = readInput<size_t>();
    if (index > 0 && index <= shapes.size()) {
        delete shapes[index - 1];
        shapes.erase(shapes.begin() + index - 1);
        std::cout << "Figure deleted\n";
    } else {
        throw InvalidChoiceException("Index doesn't exist\n");
    }
}

void ShapeApp::startApp() {
    programState = RUNNING;
    while (programState == RUNNING) {
        try {
            firstChoice();
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}