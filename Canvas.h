#ifndef CANVAS
#define CANVAS 

#include "Shape.h"
#include "Memento.h"
#include "Caretaker.h"

#include <map>

class Canvas {
    private:
        std::vector<Shape*> shapes;
        std::map<int, Shape*> listShapes();
    public:
        Memento* captureCurrent();
        void undoAction(Memento*);
        void drawShape();
        void cloneShape();
};

#endif