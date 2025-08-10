// ConcreteCreator (Factory Method)

#ifndef RectangleFactory_H
#define RectangleFactory_H

#include "../ShapeFactory/ShapeFactory.h"
#include "../Rectangle/Rectangle.h"

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