#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"

class FiguraGeometrica
{
    protected:
        float r, g, b, a;
    public:
        FiguraGeometrica();
        virtual ~FiguraGeometrica();
        virtual void draw(Sculptor &s)=0;
};

#endif // FIGURAGEOMETRICA_H
