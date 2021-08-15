#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutSphere : public FiguraGeometrica
{
    private:
        int xcenter, ycenter, zcenter, radius;
    public:
        PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
        ~PutSphere();
        void draw(Sculptor &s);
};

#endif // PUTSPHERE_H
