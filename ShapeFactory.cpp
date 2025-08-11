#include "ShapeFactory.h"

Shape* ShapeFactory::userInShape()
{
    string input_s;
    bool s_valid = false;
    int s;
    while (!s_valid)
    {
        cout << "\033[1;92mEnter the length: \033[0m";
        cin >> input_s;

        try
        {
            s = stoi(input_s);
            s_valid = true;
        }
        catch(const exception& e)
        {
            cout << "\033[1;31mNot a valid integer. Please try again.\033[0m" << endl;
        }
    }

    string input_w;
    bool w_valid = false;
    int w;
    while (!w_valid)
    {
        cout << "\033[1;92mEnter the width: \033[0m";
        cin >> input_w;

        try
        {
            w = stoi(input_w);
            w_valid = true;
        }
        catch(const exception& e)
        {
            cout << "\033[1;31mNot a valid integer. Please try again.\033[0m" << endl;
        }
    }

    string input_x;
    bool x_valid = false;
    int x;
    while (!x_valid)
    {
        cout << "\033[1;92mEnter the x-coordinate: \033[0m";
        cin >> input_x;

        try
        {
            x = stoi(input_x);
            x_valid = true;
        }
        catch(const exception& e)
        {
            cout << "\033[1;31mNot a valid integer. Please try again.\033[0m" << endl;
        }
    }
    
    string input_y;
    bool y_valid = false;
    int y;
    while (!y_valid)
    {
        cout << "\033[1;92mEnter the y-coordinate: \033[0m";
        cin >> input_y;

        try
        {
            y = stoi(input_y);
            y_valid = true;
        }
        catch(const exception& e)
        {
            cout << "\033[1;31mNot a valid integer. Please try again.\033[0m" << endl;
        }
    }

    string input_colour;
    bool colour_valid = false;
    while (!colour_valid)
    {
        cout << "\033[1;92mEnter the colour: \033[0m";
        cin >> input_colour;

        colour_valid = true;

        if (input_colour.empty())
        {
            colour_valid = false;
        }

        for(std::size_t i = 0; i < input_colour.length(); i++)
        {
            if(!isalpha(input_colour[i]))
            {
                colour_valid = false;
                break;
            }
        }

        if (colour_valid == false)
        {
            cout << "\033[1;31mNot a valid colour. Please try again.\033[0m" << endl;
        }
    }

    Shape* newShape = createShape(s, w, x, y, input_colour);
    cout << "\033[1;33mShape created:\033[0m " << newShape->shapeType() << endl;
    return newShape;  
}

Shape* ShapeFactory::newShape(int w, int l, int x, int y, string colour) {
	return createShape(w, l, x, y, colour);
}
