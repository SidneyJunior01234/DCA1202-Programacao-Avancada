#include "putellipsoid.h"
#include <cmath>

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a)
{
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> rx = rx;
    this -> ry = ry;
    this -> rz = rz;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

PutEllipsoid::~PutEllipsoid()
{
}

void PutEllipsoid::draw(Sculptor &s)
{
    s.setColor(r,g,b,a);

    double equation;

    if(rx == 0)
    {
        for (int pz = zcenter-rx; pz <= zcenter+rz; pz++)
        {
            for (int py = ycenter-ry; py <= ycenter+ry; py++)
            {
                equation = ( pow(py - ycenter,2) / pow(ry,2) ) + ( pow(pz - zcenter,2) / pow(rz,2) );
                if (equation <= 1)
                {
                    s.putVoxel(xcenter,py,pz);
                }
            }
        }
    }
    else if(ry == 0)
    {
        for (int pz = zcenter-rx; pz <= zcenter+rz; pz++)
        {
            for (int px = xcenter-rx; px <= xcenter+rx; px++)
            {
                equation = ( pow(px - xcenter,2) / pow(rx,2) ) + ( pow(pz - zcenter,2) / pow(rz,2) );
                if (equation <= 1)
                {
                    s.putVoxel(px,ycenter,pz);
                }
            }
        }
    }
    else if(rz == 0)
    {
        for (int py = ycenter-ry; py <= ycenter+ry; py++)
        {
            for (int px = xcenter-rx; px <= xcenter+rx; px++)
            {
                equation = ( pow(px - xcenter,2) / pow(rx,2) ) + ( pow(py - ycenter,2) / pow(ry,2) );
                if (equation <= 1)
                {
                    s.putVoxel(px,py,zcenter);
                }
            }
        }
    }
    else
    {
        for (int pz = zcenter-rz; pz <= zcenter+rz; pz++)
        {
            for (int py = ycenter-ry; py <= ycenter+ry; py++)
            {
                for (int px = xcenter-rx; px <= xcenter+rx; px++)
                {
                    equation = ( pow(px - xcenter,2) / pow(rx,2) ) + ( pow(py - ycenter,2) / pow(ry,2) ) + ( pow(pz - zcenter,2) / pow(rz,2) );
                    if (equation <= 1)
                    {
                        s.putVoxel(px,py,pz);
                    }
                }
            }
        }
    }
}
