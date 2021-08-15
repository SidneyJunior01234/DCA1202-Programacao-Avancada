#include "putbox.h"

PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a)
{
    this -> x0 = x0;
    this -> x1 = x1;
    this -> y0 = y0;
    this -> y1 = y1;
    this -> z0 = z0;
    this -> z1 = z1;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

PutBox::~PutBox()
{
}

void PutBox::draw(Sculptor &s)
{
    s.setColor(r,g,b,a);
    for (int px = x0; px <= x1; px++)
    {
        for (int py = y0; py <= y1; py++)
        {
            for (int pz = z0; pz <= z1; pz++)
            {
                s.putVoxel(px,py,pz);
            }
        }
    }
}
