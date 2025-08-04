#ifndef MEMENTO
#define MEMENTO

#include "Shape.h"
#include <vector>

class Memento {
    private:
        std::vector<Shape*> shapes;
    public:
        Memento(std::vector<Shape*>& elements);
        std::vector<Shape*> getState();
}

#endif