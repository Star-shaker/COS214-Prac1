#include "OpenCanvas/OpenCanvas.h"

#define TEST false

int main()
{
    OpenCanvas* CanvasClient = new OpenCanvas(TEST);

    delete CanvasClient;
    
    return 0;
}