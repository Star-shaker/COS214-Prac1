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
    protected:
        virtual Shape* createShape() = 0;
        virtual void toString() = 0;

    public:
        Shape* anOperation();
        ShapeFactory(){};
        virtual ~ShapeFactory() {};
};

#endif 

// TODO: Maybe add a function so that the createShape() function is actually called