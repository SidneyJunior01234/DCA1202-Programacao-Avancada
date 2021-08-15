#include "putsphere.h"
#include <cmath>

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a)
{
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> radius = radius;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

PutSphere::~PutSphere()
{
}

void PutSphere::draw(Sculptor &s)
{
    s.setColor(r,g,b,a);

    double equation;

    for (int pz = zcenter-radius; pz <= zcenter+radius; pz++)
    {
        for (int py = ycenter-radius; py <= ycenter+radius; py++)
        {
            for (int px = xcenter-radius; px <= xcenter+radius; px++)
            {
                equation = pow(px - xcenter,2) + pow(py - ycenter,2) + pow(pz - zcenter,2);
                if (equation <= pow(radius,2))
                {
                    s.putVoxel(px,py,pz);
                }
            }
        }
    }
}
