#include "Textbox.h"

Textbox::Textbox(int x, int y, int l, int w, std::string colour, std::string text)
: Shape(x, y, l, w, colour), text(text) {}

Shape* Textbox::clone() {
    return new Textbox(*this);
}

std::string Textbox::shapeType() {
    return "Textbox";
}