// ConcreteCreator (Factory Method)

#ifndef SquareFactory_H
#define SquareFactory_H

#include "ShapeFactory/ShapeFactory.h"
#include "Square/Square.h"

#include <iostream>
#include <string>
using namespace std;

class SquareFactory : public ShapeFactory
{
    public:
        SquareFactory();
        Shape* createShape();
        virtual Shape* createShape(int l, int w, int x, int y, string colour);
};

#endif