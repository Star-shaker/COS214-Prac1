#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int l, int w, std::string colour)
: Shape(x, y, l, w, colour) {}

Shape* Rectangle::clone() 
{
    return new Rectangle(*this);
}

std::string Rectangle::shapeType() 
{
    return "Rectangle";
}
