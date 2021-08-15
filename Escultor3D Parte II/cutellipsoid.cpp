#include "cutellipsoid.h"
#include <cmath>

CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    this -> xcenter = xcenter;
    this -> ycenter = ycenter;
    this -> zcenter = zcenter;
    this -> rx = rx;
    this -> ry = ry;
    this -> rz = rz;
}

CutEllipsoid::~CutEllipsoid()
{
}

void CutEllipsoid::draw(Sculptor &s)
{
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
                    s.cutVoxel(xcenter,py,pz);
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
                    s.cutVoxel(px,ycenter,pz);
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
                    s.cutVoxel(px,py,zcenter);
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
                        s.cutVoxel(px,py,pz);
                    }
                }
            }
        }
    }
}
