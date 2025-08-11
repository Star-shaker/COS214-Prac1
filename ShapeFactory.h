#ifndef ShapeFactory_H
#define ShapeFactory_H

#include "Shape.h"
#include <string>
#include <iostream>
using namespace std;

class ShapeFactory
{
    protected:
    virtual string toString() = 0;
    virtual Shape* createShape(int l, int w, int x, int y, string colour) = 0;

    public:
        virtual ~ShapeFactory() = default;
        Shape* userInShape();
	    Shape* newShape(int l, int w, int x, int y, string colour);
};

#endif
