// Client (Factory Method)
// Client (Prototype)
// Originator (Memento)

#ifndef CANVAS
#define CANVAS 

#include "Shape/Shape.h"
#include "SquareFactory/SquareFactory.h"
#include "RectangleFactory/RectangleFactory.h"
#include "TextboxFactory/TextboxFactory.h"

// #include "Memento/Memento.h"
// #include "Caretaker/Caretaker.h"

#include <map>
#include <string>
using namespace std;

class Canvas {
    private:
        std::vector<Shape*> shapes;
        std::map<int, Shape*> listShapes();
    public:
        // Memento* captureCurrent();
        // void undoAction(Memento*);
        void drawShape(string input);
        void cloneShape();
        Canvas(); // We should maybe add a constructor?
};

#endif

// TODO: Maybe add a way to call the ShapeFactory so that the correct Shape is actually instantiated