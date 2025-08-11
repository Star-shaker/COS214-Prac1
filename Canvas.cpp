#include "Canvas.h"

Canvas::Canvas()
{
    shapeCount = 0;
}

void Canvas::drawShape(string input)
{
    Shape *newShape = nullptr;

    if (input == "Square")
    {
        ShapeFactory *squareFactory = new SquareFactory();
        newShape = squareFactory->userInShape();
        delete squareFactory;
    }
    else if (input == "Rectangle")
    {
        ShapeFactory *rectangleFactory = new RectangleFactory();
        newShape = rectangleFactory->userInShape();
        delete rectangleFactory;
    }
    else if (input == "Textbox")
    {
        ShapeFactory *textboxFactory = new TextboxFactory("DEMO");
        newShape = textboxFactory->userInShape();
        delete textboxFactory;
    }

    if (newShape)
    {
        shapes.push_back(newShape);
        shapeCount++;
    }
}

void Canvas::drawShape(string input, int l, int w, int x, int y, string colour) {
    if (input == "Rectangle") {
        ShapeFactory* rectangleFact = new RectangleFactory();
        this->shapes.push_back(rectangleFact->createShape(l, w, x, y, colour));
        delete rectangleFact;
    } else if (input == "Square") {
        ShapeFactory* squareFact = new SquareFactory();
        this->shapes.push_back(squareFact->createShape(l, w, x, y, colour));
        delete squareFact;
    }
    shapeCount++;
}

void Canvas::drawShape(int l, int w, int x, int y, string colour, string text) {
    ShapeFactory* tbFact = new TextboxFactory("Some Text");
    this->shapes.push_back(tbFact->createShape(l, w, x, y, colour));
    delete tbFact;
    shapeCount++;
}

string Canvas::listShapes()
{
    string out = "";
    if (shapes.empty())
    {
        out = "There are no shapes yet\n";
    }

    for (Shape* shape : shapes) {
        out += shape->shapeType() + "\n";
    }

    return out;
}

int Canvas::getShapeCount()
{
    return shapeCount;
}

bool Canvas::cloneShape(int index)
{
    /*
    Clones shapes[index], if index out of range return false, if clone
    succeeded return true
    Cloned shape to be added to vector
    */

    if (this->shapes.empty() ||
        std::size_t(index) >= this->shapes.size() ||
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

    for (Shape* shape : shapes) {
        if (shape != nullptr) {
            delete shape;
            shape = nullptr;
        }
    }

    this->shapes.clear();
}

Memento* Canvas::captureCurrent() {
    return new Memento(this->shapes);
}

void Canvas::undoAction(Memento* memento) {
    this->clearCanvas();

    vector<Shape*> memShapes = memento->getState();
    for (Shape* shape : memShapes) {
        this->shapes.push_back(shape->clone());
    }
    delete memento;
}

Canvas::~Canvas() {
    clearCanvas();
}