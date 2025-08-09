#include "OpenCanvas.h"

OpenCanvas::OpenCanvas()
{
    cout << "Welcome to OpenCanvas!\n";
    Canvas* newCanvas = createCanvas();

    cout << "Select the shape you want to draw: \n"; 

    // Use listShapes here but idk how to do that with map so I'm using dumber version
    cout << "1: Square\n2: Rectangle\n3: Textbox\n";

    string input = "";
    cin >> input;

    // TODO: Input validation
    if(input == "1")
    {
        newCanvas->drawShape("Square");
    }
    else if(input == "2")
    {
        newCanvas->drawShape("Rectangle");
    }
    else if(input == "3")
    {
        newCanvas->drawShape("Textbox");
    }
}

void OpenCanvas::exportToFile(Canvas canvas)
{
    
}

Canvas* OpenCanvas::createCanvas()
{
    canvasses.push_front(new Canvas());
    cout << "New Canvas created!\n";

    return canvasses.front();
}

list<Canvas*> OpenCanvas::listCanvasses()
{

}

OpenCanvas::~OpenCanvas()
{
    // TODO: Memory management!
}