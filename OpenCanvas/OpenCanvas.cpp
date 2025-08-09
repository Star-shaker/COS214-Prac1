#include "OpenCanvas.h"
#include "../UnitTester.h"

OpenCanvas::OpenCanvas(bool test)
{
    if (test) {
        this->testCanvas();
    } else {
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
}

void OpenCanvas::testCanvas() {
    //----------Test shapes clone-----------------
    UnitTester<bool>* boolTester = new UnitTester<bool>();
    boolTester->newSection("Test shapes clone");
    // Create testing canvas
    Canvas* testingCanvas = new Canvas();

    // Test clone on empty canvas, should return false
    boolTester->test(testingCanvas->cloneShape(0), false);

    // Test on Rectangle, assumes drawShape works
    testingCanvas->drawShape("Rectangle", 10, 10, 3, 4, "blue");
    boolTester->test(testingCanvas->cloneShape(0), true);
    
    boolTester->endSection();

    UnitTester<std::string>* stringTester = new UnitTester<std::string>();
    stringTester->newSection("List shapes and canvasses tests");

    stringTester->endSection();

    // Mem management
    delete stringTester;
    delete boolTester;
    delete testingCanvas;
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