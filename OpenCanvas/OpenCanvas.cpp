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
    string expectedOut = "0, Rectangle\n1, Rectangle\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true);
    testingCanvas->clearCanvas();

    // Test on square
    testingCanvas->drawShape("Square", 10, 10, 3, 4, "blue");
    boolTester->test(testingCanvas->cloneShape(0), true);
    expectedOut = "0, Square\n1, Square\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true);
    testingCanvas->clearCanvas();

    // Test on textbox
    testingCanvas->drawShape(10, 10, 3, 4, "blue", "SomeText");
    boolTester->test(testingCanvas->cloneShape(0), true);
    expectedOut = "0, Textbox\n1, Textbox\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true);
    testingCanvas->clearCanvas();
    boolTester->endSection();

    // Test on all shapes
    testingCanvas->drawShape("Rectangle", 10, 10, 3, 4, "blue");
    testingCanvas->drawShape("Square", 10, 10, 3, 4, "blue");
    testingCanvas->drawShape(10, 10, 3, 4, "blue", "SomeText");

    boolTester->test(testingCanvas->cloneShape(0), true);
    boolTester->test(testingCanvas->cloneShape(1), true);
    boolTester->test(testingCanvas->cloneShape(2), true);

    expectedOut = "0, Rectangle\n1, Square\n2, Textbox\n3, Rectangle\n4, Square\n5, Textbox\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true, "List shapes");

    // Test out of bounds cloning
    boolTester->test(testingCanvas->cloneShape(6), false);
    boolTester->test(testingCanvas->cloneShape(-1), false);

    boolTester->endSection();
    // Mem management
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