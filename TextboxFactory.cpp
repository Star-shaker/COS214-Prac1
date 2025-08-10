#include "TextboxFactory.h"

TextboxFactory::TextboxFactory(string text) : ShapeFactory(), text(text)
{
    cout << "TextboxFactory created!\n";
}

Shape *TextboxFactory::createShape(int l, int w, int x, int y, string colour)
{
    if (this->text == "")
    {
        this->text = "Default Text";
    } else if (this->text == "DEMO") {
        cout << "\033[1;92mEnter the text: \033[0m";
        cin >> this->text;
    }

    return new Textbox(x, y, l, w, colour, this->text);
}

void TextboxFactory::setText(string text)
{
    this->text = text;
}