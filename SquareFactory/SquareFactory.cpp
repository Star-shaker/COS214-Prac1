#include "SquareFactory.h"

#include <iostream>
#include <string>
using namespace std;

SquareFactory::SquareFactory() : ShapeFactory()
{
    cout << "SquareFactory created!\n";
}

Shape* SquareFactory::createShape()
{
    string input_s;
    bool s_valid = false;
    int s;
    while (s_valid)
    {
        cout << "Enter the length: ";
        cin >> input_s;

        try
        {
            s = stoi(input_s);
            s_valid = true;
        }
        catch(const exception& e)
        {
            cout << "Not a valid integer. Please try again." << endl;
        }
    }

    string input_x;
    bool x_valid = false;
    int x;
    while (x_valid)
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
    while (y_valid)
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

    Shape* newSquare = new Square(x, y, s, input_colour);
    cout << "Square will be created!\n";
}

void SquareFactory::toString()
{
    cout << "Square created!" << endl;
}

SquareFactory::~SquareFactory()
{
    // TODO: Memory management!
}