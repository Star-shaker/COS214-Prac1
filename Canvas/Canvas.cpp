#include "Canvas.h"

// Memento* Canvas::captureCurrent() {
//     return new Memento(this->shapes);
// }

// void Canvas::undoAction(Memento* memento) {
//     this->shapes = memento->getState();
// }

// Canvas::Canvas()
// {
    
// }

void Canvas::drawShape(string input)
{
    Shape* newShape = nullptr;

    if(input == "Square")
    {
        ShapeFactory* squareFactory = new SquareFactory();
        newShape = squareFactory->anOperation();
        delete squareFactory;
    }
    else if(input == "Rectangle")
    {
        ShapeFactory* rectangleFactory = new RectangleFactory();
        newShape = rectangleFactory->anOperation();
        delete rectangleFactory;
    }
    else if(input == "Textbox")
    {
        ShapeFactory* textboxFactory = new TextboxFactory();
        newShape = textboxFactory->anOperation();
        delete textboxFactory;
    }

    if(newShape)
    {
        shapes.push_back(newShape);
    }
}

void Canvas::listShapes() {
    if (shapes.empty()) {
        std::cout << "There are no shapes yet\n";
        return; 
    }

    for (int i = 0; i < shapes.size(); i++) {
        std::cout << std::to_string(i) + ", " + shapes[i]->shapeType() + "\n";
    }
}