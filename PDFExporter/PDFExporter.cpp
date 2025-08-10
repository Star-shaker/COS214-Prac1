#include "PDFExporter.h"

void PDFExporter::prepareCanvas()
{
    cout << "\033[1;33mPDF: Canvas prepared!\n\033[0m";
}  

void PDFExporter::renderElements()
{
    cout << "\033[1;33mPDF: Elements rendered!\n\033[0m";
}

void PDFExporter::saveToFile()
{
    cout << "\033[1;33mPDF: Saved to file!\n\033[0m";
}

PDFExporter::~PDFExporter() {}