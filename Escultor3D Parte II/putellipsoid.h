#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutEllipsoid : public FiguraGeometrica
{
    private:
        int xcenter, ycenter, zcenter, rx, ry, rz;
    public:
        PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a);
        ~PutEllipsoid();
        void draw(Sculptor &s);
};

#endif // PUTELLIPSOID_H
