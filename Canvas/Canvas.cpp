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
    Shape *newShape = nullptr;

    if (input == "Square")
    {
        ShapeFactory *squareFactory = new SquareFactory();
        newShape = squareFactory->anOperation();
        delete squareFactory;
    }
    else if (input == "Rectangle")
    {
        ShapeFactory *rectangleFactory = new RectangleFactory();
        newShape = rectangleFactory->anOperation();
        delete rectangleFactory;
    }
    else if (input == "Textbox")
    {
        ShapeFactory *textboxFactory = new TextboxFactory();
        newShape = textboxFactory->anOperation();
        delete textboxFactory;
    }

    if (newShape)
    {
        shapes.push_back(newShape);
    }
}

void Canvas::drawShape(string input, int l, int w, int x, int y, string colour) {
    if (input == "Rectangle") {
        ShapeFactory* rectangleFact = new RectangleFactory();
        this->shapes.push_back(rectangleFact->createShape(l, w, x, y, colour));
    } else if (input == "Square") {
        ShapeFactory* squareFact = new SquareFactory();
        this->shapes.push_back(squareFact->createShape(l, w, x, y, colour));
    }
}

void Canvas::drawShape(int l, int w, int x, int y, string colour, string text) {
    ShapeFactory* tbFact = new TextboxFactory("Some Text");
    this->shapes.push_back(tbFact->createShape(l, w, x, y, colour));
}

string Canvas::listShapes()
{
    string out = "";
    if (shapes.empty())
    {
        out = "There are no shapes yet\n";
    }

    for (int i = 0; i < shapes.size(); i++)
    {
        out += std::to_string(i) + ", " + shapes[i]->shapeType() + "\n";
    }

    cout << out;
    return out;
}

bool Canvas::cloneShape(int index)
{
    /*
    Clones shapes[index], if index out of range return false, if clone
    succeeded return true
    Cloned shape to be added to vector
    */

    if (this->shapes.empty() ||
        index >= this->shapes.size() ||
        index < 0)
    {
        return false;
    }

    // Using this keyword explicitly cause it reminds me that shapes is an attr
    // If index validated cant see any exception being thrown here so no try-catch
    this->shapes.push_back(this->shapes[index]->clone());

    return true;
}

void Canvas::clearCanvas() {
    /*
    Deallocates all Shape objects and empties vector
    */

    for (int i = 0; i < this->shapes.size(); i++) {
        delete this->shapes[i];
    }

    this->shapes.clear();
}