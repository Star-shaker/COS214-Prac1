// Client (Factory Method)
// Client (Prototype)
// Originator (Memento)

#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"
#include "SquareFactory.h"
#include "RectangleFactory.h"
#include "TextboxFactory.h"

#include "Memento.h"

#include <string>
using namespace std;

class Canvas 
{
    private:
        std::vector<Shape*> shapes;
        int shapeCount;
        
    public:
        Canvas();
        ~Canvas();
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