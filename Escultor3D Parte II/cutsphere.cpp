#include "cutsphere.h"
#include <cmath>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> radius = radius;
}

CutSphere::~CutSphere()
{
}

void CutSphere::draw(Sculptor &s)
{
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
                    s.cutVoxel(px,py,pz);
                }
            }
        }
    }
}
