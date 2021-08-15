#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"
#include "sculptor.h"

class CutBox : public FiguraGeometrica
{
    private:
        int x0, x1, y0, y1, z0, z1;
    public:
         CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
        ~CutBox();
        void draw(Sculptor &s);
};

#endif // CUTBOX_H
