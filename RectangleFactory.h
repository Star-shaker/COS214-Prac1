// ConcreteCreator (Factory Method)

#ifndef RectangleFactory_H
#define RectangleFactory_H

#include "ShapeFactory.h"
#include "Rectangle.h"

#include <iostream>
#include <string>
using namespace std;

class RectangleFactory : public ShapeFactory
{
    public:
        RectangleFactory();
        virtual Shape* createShape(int l, int w, int x, int y, string colour);
};

#endif