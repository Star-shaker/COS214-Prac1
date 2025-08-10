#include "OpenCanvas.h"

#define TEST true

int main()
{
    OpenCanvas* CanvasClient = new OpenCanvas(TEST);

    delete CanvasClient;
    
    return 0;
}