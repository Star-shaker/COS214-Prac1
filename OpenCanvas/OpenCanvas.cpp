#include "OpenCanvas.h"
#include "../UnitTester.h"

OpenCanvas::OpenCanvas(bool test)
{
    this->caretaker = new Caretaker();
    if (test)
    {
        this->testCanvas();
    }
    else
    {
        cout << "Welcome to OpenCanvas!\n";
        Canvas *newCanvas = createCanvas();
        while (true)
        {
            cout << "Press q to quit, a to add shape, u to undo action, l to list shapes, c to clone shape or e to export canvas\n";
            string input = "";
            cin >> input;

            if (input == "q")
            {
                cout << "Goodbye!\n";
                break;
            }

            // TODO: Input validation
            if (input == "a")
            {
                cout << "Select the shape you want to draw: \n";

                // Use listShapes here but idk how to do that with map so I'm using dumber version
                cout << "1: Square\n2: Rectangle\n3: Textbox\n";
                string shapeToDraw;
                cin >> shapeToDraw;
                this->storeCanvasState(newCanvas);
                if (shapeToDraw == "1")
                {
                    newCanvas->drawShape("Square");
                }
                else if (shapeToDraw == "2")
                {
                    newCanvas->drawShape("Rectangle");
                }
                else if (shapeToDraw == "3")
                {
                    newCanvas->drawShape("Textbox");
                }
            }

            if (input == "l") {
                newCanvas->listShapes();
            }

            if (input == "u") {
                Memento* prevMem = this->caretaker->retrieveMemento();
                if (prevMem == NULL) {
                    cout << "No actions to undo\n";
                } else {
                    newCanvas->undoAction(prevMem);
                    cout << "Action undid successfully.\nUpdated Shape list:\n";
                    newCanvas->listShapes();
                }
            }

            if (input == "c") {
                cout << "Please select the number of the shape to clone:\n";
                newCanvas->listShapes();
                string cloneNumString;
                cin >> cloneNumString;
                int cloneNum = stoi(cloneNumString);

                if (newCanvas->cloneShape(cloneNum)) {
                    cout << "Succesfully cloned shape.\nUpdated shapes list:\n";
                    newCanvas->listShapes();
                } else {
                    cout << "Failed to clone shape. Please make sure that you entered a valid index.\n";
                }
            }
        }
    }
}

void OpenCanvas::testCanvas()
{
    //----------Test shapes clone-----------------
    UnitTester<bool> *boolTester = new UnitTester<bool>();
    boolTester->newSection("Test shapes clone");
    // Create testing canvas
    Canvas *testingCanvas = new Canvas();

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

    //---------------Test Memento----------------
    boolTester->newSection("Test memento");
    this->caretaker->storeMemento(testingCanvas->captureCurrent());
    testingCanvas->clearCanvas();
    testingCanvas->undoAction(this->caretaker->retrieveMemento());
    boolTester->test(testingCanvas->listShapes() == expectedOut, true, "List shapes memento");

    // Test empty canvas
    testingCanvas->clearCanvas();
    this->caretaker->storeMemento(testingCanvas->captureCurrent());
    testingCanvas->undoAction(this->caretaker->retrieveMemento());
    expectedOut = "There are no shapes yet\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true, "Mem empty canvas");
    boolTester->endSection();

    // Mem management
    delete boolTester;
    delete testingCanvas;
}

void OpenCanvas::exportToFile(Canvas canvas)
{
}

Canvas *OpenCanvas::createCanvas()
{
    canvasses.push_front(new Canvas());
    cout << "New Canvas created!\n";

    return canvasses.front();
}

list<Canvas *> OpenCanvas::listCanvasses()
{
}

OpenCanvas::~OpenCanvas()
{
    // TODO: Memory management!
    delete caretaker;
}

void OpenCanvas::storeCanvasState(Canvas* canvas) {
    this->caretaker->storeMemento(canvas->captureCurrent());
}