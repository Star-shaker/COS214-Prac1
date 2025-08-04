#ifndef ExportCanvas_H
#define ExportCanvas_H

class ExportCanvas : public Canvas
{
    private:
        Canvas* canvas;

        virtual void prepareCanvas() = 0;
        virtual void renderElements() = 0;
        virtual void saveToFile() = 0;
    
    public:
        virtual ~ExportCanvas();
        void _export(Canvas* canvas); //Template method
};

#endif