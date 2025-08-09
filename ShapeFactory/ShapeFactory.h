#ifndef ShapeFactory_H
#define ShapeFactory_H

#include "Shape/Shape.h"
#include <string>
#include <iostream>
using namespace std;

class ShapeFactory
{
    private:
        Shape* shape;

    public:
        Shape* anOperation();
        virtual Shape* createShape() = 0;
        virtual Shape* createShape(int l, int w, int x, int y, string colour) = 0;
};

#endif 

// TODO: Maybe add a function so that the createShape() function is actually called