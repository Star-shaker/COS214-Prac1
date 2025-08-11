// ConcretePrototype (Prototype)
// ConcreteProduct (Factory Method)

#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square: public Shape 
{
    private:
	int length;
	int width;
	string colour;
	int position_x;
	int position_y;
    public:
        Square(int x, int y, int side, std::string colour);
        virtual Shape* clone();
        virtual std::string shapeType();
};

#endif
