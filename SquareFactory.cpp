#include "SquareFactory.h"

SquareFactory::SquareFactory() : ShapeFactory() {}

string SquareFactory::toString()
{
    return "SquareFactory created!\n";
}

Shape* SquareFactory::createShape(int l, int w, int x, int y, string colour) 
{
    return new Square(x, y, l, colour);
}