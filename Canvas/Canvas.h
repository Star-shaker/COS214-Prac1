#ifndef CANVAS
#define CANVAS 

#include "Shape/Shape.h"
#include "Memento/Memento.h"
#include "Caretaker/Caretaker.h"

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