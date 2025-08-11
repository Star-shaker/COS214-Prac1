#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int l, int w, std::string colour): Shape(x, y, l, w, colour) 
{
    this->position_x = x;
    this->position_y = y;
    this->length = l;
    this->width = w;
    this->colour = colour;
}

Shape* Rectangle::clone() 
{
    return new Rectangle(*this);
}

std::string Rectangle::shapeType() 
{
    return "Rectangle";
}

string Rectangle::getAttributes()
{
    return "(l:" + to_string(length) + ", w:" + to_string(width) + ", colour:" + colour + ")";
}