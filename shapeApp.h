#ifndef SHAPE_APP_H
#define SHAPE_APP_H

#include <vector>
#include <map>
#include "shape.h"

typedef enum {
    STOPPED,
    RUNNING,
} ProgramState;

class ShapeApp {
public:
    ShapeApp();
    void startApp();
    void endApp();
private:
    std::vector<Shape*> shapes;
    ProgramState programState;
    std::map<int, void (ShapeApp::*)()> shapesMap;
    std::map<int, void (ShapeApp::*)()> choicesMap;
    void initializeShapesMap();
    void initializeChoicesMap();
    void secondChoice();
    void firstChoice();
    void addCircle();
    void addRectangle();
    void addTriangle();
    void listFigures();
    void listFiguresWithPerimeter();
    void sortByPerimeter();
    void deleteFigureByNumber();
    void deleteFiguresWithPerimeterGreaterThan();
};

#endif