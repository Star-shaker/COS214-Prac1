#ifndef RECTANGLE
#define RECTANGLE

#include "Shape/Shape.h"

class Rectangle: public Shape {
    public:
        Rectangle(int x, int y, int l, int w, std::string colour);
        virtual Shape* clone();
        virtual std::string shapeType();
};

#endif