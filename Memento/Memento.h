#ifndef MEMENTO_H
#define MEMENTO_H

#include "Shape/Shape.h"
#include <vector>

class Memento 
{
    private:
        std::vector<Shape*> shapes;
        
    public:
        ~Memento();
        Memento(std::vector<Shape*>& elements);
        std::vector<Shape*> getState();
};

#endif