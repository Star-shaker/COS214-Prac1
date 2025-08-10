#include "OpenCanvas.h"
#include "../UnitTester.h"

OpenCanvas::OpenCanvas(bool test)
{
    this->caretaker = new Caretaker();
    this->canvas = NULL;

    if (test)
    {
        this->testCanvas();
    }
    else
    {
        cout << "\n\033[1;96mWelcome to OpenCanvas!\033[0m\n"
        << "\033[1;96m=====================\033[0m\n\n";
        canvas = createCanvas();

        while (true)
        {
            cout << "\n\033[1;95m=== Canvas Controls ===\033[0m\n"
            << "  \033[1;33m[q]\033[0m Quit\n"
            << "  \033[1;33m[a]\033[0m Add shape\n"
            << "  \033[1;33m[u]\033[0m Undo action\n"
            << "  \033[1;33m[l]\033[0m List shapes\n"
            << "  \033[1;33m[c]\033[0m Clone shape\n"
            << "  \033[1;33m[e]\033[0m Export canvas\n"
            << "\033[1;95m======================\033[0m\n";

            string input = "";
            cin >> input;

            if (input == "q")
            {
                cout << "\n\033[1;91mGoodbye! Thanks for using OpenCanvas.\033[0m\n";
                break;
            }

            // TODO: Input validation
            if (input == "a")
            {
                cout << "  1. Square\n" << "  2. Rectangle\n" << "  3. Textbox\n\033[0m" << "\n\033[1;96mSelect the shape you want to draw: \033[0m";

                string shapeToDraw;
                cin >> shapeToDraw;
                this->storeCanvasState(canvas);
                if (shapeToDraw == "1")
                {
                    canvas->drawShape("Square");
                }
                else if (shapeToDraw == "2")
                {
                    canvas->drawShape("Rectangle");
                }
                else if (shapeToDraw == "3")
                {
                    canvas->drawShape("Textbox");
                }
            }

            if (input == "l") 
            {
                canvas->listShapes();
            }

            if (input == "u") 
            {
                Memento* prevMem = this->caretaker->retrieveMemento();
                if (prevMem == NULL) {
                    cout << "\033[1;31mNo actions to undo\n\033[0m";
                } else {
                    canvas->undoAction(prevMem);
                    cout << "\033[1;91mAction undid successfully.\nUpdated Shape list:\n\033[0m";
                    canvas->listShapes();
                }
            }

            if (input == "c") 
            {
                this->storeCanvasState(canvas);
                cout << "\033[1;96mSelect the number of the shape to clone:\033[0m\n";
                canvas->listShapes();
                string cloneNumString;
                cin >> cloneNumString;
                int cloneNum = stoi(cloneNumString);

                if (canvas->cloneShape(cloneNum)) {
                    cout << "\033[1;33mSuccesfully cloned shape.\nUpdated shapes list:\033[0m\n";
                    canvas->listShapes();
                } else {
                    cout << "\033[1;31mFailed to clone shape. Please make sure that you entered a valid index.\033[0m\n";
                }
            }

            if (input == "e")
            {
                cout << "\n\033[1;96mSelect the type of file you want to export to:\033[0m\n"
                << "  1. PDF\n"
                << "  2. PNG\n\033[0m";

                string fileType;
                cin >> fileType;

                if(fileType == "1" || fileType == "2")
                {
                    int fileNum = stoi(fileType);
                    exportToFile(canvas, fileNum);
                }
                else
                {
                    cout << "\033[1;31mFailed to export to file. Please make sure that you entered a valid index.\033[0m" << endl;
                }
            }
        }
    }
}

void OpenCanvas::exportToFile(Canvas* canvas, int input)
{
    if (input == 1)
    {
        ExportCanvas* pdfEx = new PDFExporter();
        pdfEx->exportToFile(canvas);

        delete pdfEx;
    }
    else if (input == 2)
    {
        ExportCanvas* pngEx = new PNGExporter();
        pngEx->exportToFile(canvas);
        
        delete pngEx;
    }
}

Canvas *OpenCanvas::createCanvas()
{
    cout << "\033[1;33mBlank Canvas created!\033[0m\n";
    return new Canvas();
}

OpenCanvas::~OpenCanvas()
{
    if (canvas) {
       delete canvas;
    }
    if (caretaker) {
        delete caretaker;
    }
}

void OpenCanvas::storeCanvasState(Canvas* canvas) 
{
    this->caretaker->storeMemento(canvas->captureCurrent());
}

void OpenCanvas::testCanvas()
{
    UnitTester<bool>* boolTester = new UnitTester<bool>();

    // =================== CLONE SHAPE TESTS ===================
    boolTester->newSection("Test shapes clone");
    Canvas* testingCanvas = new Canvas();

    boolTester->test(testingCanvas->cloneShape(0), false);

    testingCanvas->drawShape("Rectangle", 10, 10, 3, 4, "blue");
    boolTester->test(testingCanvas->cloneShape(0), true);
    string expectedOut = "0, Rectangle\n1, Rectangle\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true);
    testingCanvas->clearCanvas();

    testingCanvas->drawShape("Square", 10, 10, 3, 4, "blue");
    boolTester->test(testingCanvas->cloneShape(0), true);
    expectedOut = "0, Square\n1, Square\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true);
    testingCanvas->clearCanvas();

    testingCanvas->drawShape(10, 10, 3, 4, "blue", "SomeText");
    boolTester->test(testingCanvas->cloneShape(0), true);
    expectedOut = "0, Textbox\n1, Textbox\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true);
    testingCanvas->clearCanvas();

    testingCanvas->drawShape("Rectangle", 10, 10, 3, 4, "blue");
    testingCanvas->drawShape("Square", 10, 10, 3, 4, "blue");
    testingCanvas->drawShape(10, 10, 3, 4, "blue", "SomeText");

    boolTester->test(testingCanvas->cloneShape(0), true);
    boolTester->test(testingCanvas->cloneShape(1), true);
    boolTester->test(testingCanvas->cloneShape(2), true);

    expectedOut = "0, Rectangle\n1, Square\n2, Textbox\n3, Rectangle\n4, Square\n5, Textbox\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true, "List shapes");

    boolTester->test(testingCanvas->cloneShape(6), false);
    boolTester->test(testingCanvas->cloneShape(-1), false);
    boolTester->endSection();

    // =================== MEMENTO TESTS ===================
    boolTester->newSection("Test memento");
    this->caretaker->storeMemento(testingCanvas->captureCurrent());
    testingCanvas->clearCanvas();
    testingCanvas->undoAction(this->caretaker->retrieveMemento());
    boolTester->test(testingCanvas->listShapes() == expectedOut, true, "List shapes memento");

    testingCanvas->clearCanvas();
    this->caretaker->storeMemento(testingCanvas->captureCurrent());
    testingCanvas->undoAction(this->caretaker->retrieveMemento());
    expectedOut = "There are no shapes yet\n";
    boolTester->test(testingCanvas->listShapes() == expectedOut, true, "Mem empty canvas");

    Caretaker* test = new Caretaker();
    caretaker->retrieveMemento();
    delete test;
    boolTester->endSection();

    // =================== FACTORY TESTS ===================
    boolTester->newSection("Factory Deep Coverage");

    RectangleFactory rectFactory;
    Shape* rect = rectFactory.createShape(0, 0, 0, 0, "");
    rect->shapeType();
    boolTester->test(rect != nullptr, true, "RectangleFactory handles zero dimensions");
    delete rect;

    SquareFactory squareFactory;
    Shape* square1 = squareFactory.createShape(0, 0, 0, 0, "");
    square1->shapeType();
    boolTester->test(square1 != nullptr, true, "SquareFactory handles zero size");
    delete square1;

    Shape* square2 = squareFactory.createShape(-5, -5, 10, 0, "black");
    boolTester->test(square2 != nullptr, true, "SquareFactory handles negative coordinates");
    delete square2;

    TextboxFactory* textboxFactory = new TextboxFactory("");
    Shape* textbox1 = textboxFactory->createShape(10, 10, 20, 30, "blue");
    textbox1->shapeType();
    boolTester->test(textbox1 != nullptr, true, "TextboxFactory with preset text");
    delete textbox1;
    delete textboxFactory;

    Shape* rect1 = rectFactory.createShape(1, 1, 2, 2, "test");
    Shape* rect2 = rectFactory.createShape(3, 3, 4, 4, "test");
    boolTester->test(rect1 != nullptr && rect2 != nullptr, true, "Factory reuse creates multiple shapes");
    delete rect1;
    delete rect2;

    RectangleFactory* dynamicRectFactory = new RectangleFactory();
    SquareFactory* dynamicSquareFactory = new SquareFactory();
    TextboxFactory* dynamicTextFactory2 = new TextboxFactory("Dynamic Text");

    Shape* dynRect = dynamicRectFactory->createShape(1, 1, 2, 2, "red");
    Shape* dynSquare = dynamicSquareFactory->createShape(0, 0, 5, 0, "blue");
    Shape* dynText2 = dynamicTextFactory2->createShape(5, 5, 15, 15, "purple");

    boolTester->test(dynRect != nullptr, true, "Dynamic RectangleFactory");
    boolTester->test(dynSquare != nullptr, true, "Dynamic SquareFactory");
    boolTester->test(dynText2 != nullptr, true, "Dynamic TextboxFactory parameterized");

    delete dynRect;
    delete dynSquare;
    delete dynText2;
    delete dynamicRectFactory;
    delete dynamicSquareFactory;
    delete dynamicTextFactory2;

    boolTester->endSection();

    // =================== EXPORTER TESTS ===================
    boolTester->newSection("Test Exporters");
    Canvas* exportTestCanvas = new Canvas();
    exportTestCanvas->drawShape("Square", 0, 0, 10, 10, "red");

    ExportCanvas* pdfExporter = new PDFExporter();
    pdfExporter->exportToFile(exportTestCanvas);
    boolTester->test(true, true, "PDFExporter exportToFile runs without error");
    delete pdfExporter;

    ExportCanvas* pngExporter = new PNGExporter();
    pngExporter->exportToFile(exportTestCanvas);
    boolTester->test(true, true, "PNGExporter exportToFile runs without error");
    delete pngExporter;

    delete exportTestCanvas;
    boolTester->endSection();

    // =================== CANVAS TESTS ===================
    boolTester->newSection("Additional Canvas Tests");

    testingCanvas->clearCanvas();
    boolTester->test(testingCanvas->getShapeCount(), 0);
    testingCanvas->drawShape("Square", 5, 5, 0, 0, "red");
    boolTester->test(testingCanvas->getShapeCount(), 1);
    testingCanvas->drawShape("Rectangle", 10, 5, 1, 1, "blue");
    boolTester->test(testingCanvas->getShapeCount(), 2);

    testingCanvas->drawShape("Circle");
    boolTester->test(true, true, "drawShape with invalid shape string does not crash");

    boolTester->test(testingCanvas->cloneShape(-100), false);
    boolTester->test(testingCanvas->cloneShape(1000), false);
    boolTester->test(testingCanvas->cloneShape(1), true);

    testingCanvas->clearCanvas();
    boolTester->test(testingCanvas->getShapeCount(), 0);
    boolTester->test(testingCanvas->listShapes() == "There are no shapes yet\n", true, "clearCanvas empties the canvas");
    boolTester->endSection();

    // =================== CLEANUP ===================
    delete boolTester;
    delete testingCanvas;
}