#include "Canvas.h"

// Memento* Canvas::captureCurrent() {
//     return new Memento(this->shapes);
// }

// void Canvas::undoAction(Memento* memento) {
//     this->shapes = memento->getState();
// }

Canvas::Canvas()
{
    
}

void Canvas::drawShape(string input)
{
    if(input == "Square")
    {
        ShapeFactory* squareFactory = new SquareFactory();
        Shape* newSquare = squareFactory->addShape();
    }
    else if(input == "Rectangle")
    {

    }
    else if(input == "Textbox")
    {

    }
}