#include "RectangleFactory.h"

RectangleFactory::RectangleFactory() : ShapeFactory()
{
    cout << "RectangleFactory created!\n";
}

Shape* RectangleFactory::createShape()
{
    string input_l;
    bool l_valid = false;
    int l;
    while (!l_valid)
    {
        cout << "Enter the length: ";
        cin >> input_l;

        try
        {
            l = stoi(input_l);
            l_valid = true;
        }
        catch(const exception& e)
        {
            cout << "Not a valid integer. Please try again." << endl;
        }
    }

    string input_w;
    bool w_valid = false;
    int w;
    while (!w_valid)
    {
        cout << "Enter the width: ";
        cin >> input_w;

        try
        {
            w = stoi(input_l);
            w_valid = true;
        }
        catch(const exception& e)
        {
            cout << "Not a valid integer. Please try again." << endl;
        }
    }

    string input_x;
    bool x_valid = false;
    int x;
    while (!x_valid)
    {
        cout << "Enter the x-coordinate: ";
        cin >> input_x;

        try
        {
            x = stoi(input_x);
            x_valid = true;
        }
        catch(const exception& e)
        {
            cout << "Not a valid integer. Please try again." << endl;
        }
    }
    
    string input_y;
    bool y_valid = false;
    int y;
    while (!y_valid)
    {
        cout << "Enter the y-coordinate: ";
        cin >> input_y;

        try
        {
            y = stoi(input_y);
            y_valid = true;
        }
        catch(const exception& e)
        {
            cout << "Not a valid integer. Please try again." << endl;
        }
    }

    string input_colour;
    bool colour_valid = false;
    while (!colour_valid)
    {
        cout << "Enter the colour: ";
        cin >> input_colour;

        colour_valid = true;

        if (input_colour.empty())
        {
            colour_valid = false;
        }

        for(int i = 0; i < input_colour.length(); i++)
        {
            if(!isalpha(input_colour[i]))
            {
                colour_valid = false;
                break;
            }
        }

        if (colour_valid == false)
        {
            cout << "Not a valid colour. Please try again." << endl;
        }
    }

    Shape* newRectangle = new Rectangle(x, y, l, w, input_colour);
    cout << "Shape created: " << newRectangle->shapeType() << endl;
    return newRectangle;
}

void RectangleFactory::toString()
{
    cout << "Rectangle created!" << endl;
}

RectangleFactory::~RectangleFactory()
{
    // TODO: Memory management!
}