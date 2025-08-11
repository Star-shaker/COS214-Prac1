#include "RectangleFactory.h"

RectangleFactory::RectangleFactory() : ShapeFactory()
{

}

string RectangleFactory::toString()
{
    return "RectangleFactory created!\n";
}

Shape* RectangleFactory::createShape(int l, int w, int x, int y, string colour) 
{
    return new Rectangle(x, y, l, w, colour);
}