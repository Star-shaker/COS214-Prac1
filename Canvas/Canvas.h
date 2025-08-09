// Client (Factory Method)
// Client (Prototype)
// Originator (Memento)

#ifndef CANVAS_H
#define CANVAS_H

#include "Shape/Shape.h"
#include "SquareFactory/SquareFactory.h"
#include "RectangleFactory/RectangleFactory.h"
#include "TextboxFactory/TextboxFactory.h"

// #include "Memento/Memento.h"
// #include "Caretaker/Caretaker.h"

#include <string>
using namespace std;

class Canvas 
{
    private:
        std::vector<Shape*> shapes;
        
    public:
        // Canvas();
        ~Canvas();
        void listShapes();
        // Memento* captureCurrent();
        // void undoAction(Memento*);
        void drawShape(string input);
        void cloneShape();
};

#endif