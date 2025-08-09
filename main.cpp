#include "OpenCanvas/OpenCanvas.h"

/*
Constant flag for running tests or otherwise test client interaction
If rely on client input fitchfork will time out
*/ 
#define TEST false

int main()
{
    OpenCanvas* CanvasClient = new OpenCanvas(TEST); // Client is created
    delete CanvasClient;
    return 0;
}