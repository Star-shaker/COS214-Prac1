// ConcretePrototype (Prototype)
// ConcreteProduct (Factory Method)

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square: public Shape 
{
    public:
        Square(int x, int y, int side, std::string colour);
        virtual Shape* clone();
        virtual std::string shapeType();
};

#endif