#include "PNGExporter.h"

void PNGExporter::prepareCanvas()
{
    cout << "\033[1;33mPNG: Canvas prepared!\n\033[0m";
}  

void PNGExporter::renderElements()
{
    cout << "\033[1;33mPNG: Elements rendered!\n\033[0m";
}

void PNGExporter::saveToFile()
{
    cout << "\033[1;33mPNG: Saved To file!\n\033[0m";
}

PNGExporter::~PNGExporter() {}