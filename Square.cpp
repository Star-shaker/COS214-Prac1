#include "Square.h"

Square::Square(int x, int y, int side, std::string colour): Shape(x, y, side, side, colour) 
{
    this->position_x = x;
    this->position_y = y;
    this->length = side;
    this->width = side;
    this->colour = colour;
}

Shape* Square::clone() 
{
    return new Square(*this);
}

std::string Square::shapeType() 
{
    return "Square";
}

string Square::getAttributes()
{
    return "(l:" + to_string(length) + ", w:" + to_string(width) + ", colour:" + colour + ")";
}
