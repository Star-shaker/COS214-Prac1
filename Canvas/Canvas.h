// Client (Factory Method)
// Client (Prototype)
// Originator (Memento)

#ifndef CANVAS_H
#define CANVAS_H

#include "Shape/Shape.h"
#include "SquareFactory/SquareFactory.h"
#include "RectangleFactory/RectangleFactory.h"
#include "TextboxFactory/TextboxFactory.h"

#include "Memento/Memento.h"

#include <string>
using namespace std;

class Canvas 
{
    private:
        std::vector<Shape*> shapes;
        int shapeCount;
        
    public:
        Canvas();
        string listShapes();
        int getShapeCount();
        Memento* captureCurrent();
        void undoAction(Memento*);
        void drawShape(string input);

        // Overload drawShape to allow for passing parameters
        void drawShape(string input, int l, int w, int x, int y, string colour);
        void drawShape(int l, int w, int x, int y, string colour, string text);
        bool cloneShape(int index);
        void clearCanvas();
};

#endif