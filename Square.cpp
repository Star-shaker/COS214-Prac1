#include "Square.h"

Square::Square(int x, int y, int side, std::string colour)
: Shape(x, y, side, side, colour) {}

Shape* Square::clone() {
    return new Square(*this);
}

std::string Square::shapeType() {
    return "Square";
}