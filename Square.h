#ifndef SQUARE
#define SQUARE

#include "Shape.h"

class Square: public Shape {
    public:
        Square(int x, int y, int side, std::string colour);
        virtual Shape* clone();
        virtual std::string shapeType();
};

#endif