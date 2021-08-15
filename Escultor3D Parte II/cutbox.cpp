#include "cutbox.h"

CutBox::CutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    this -> x0 = x0;
    this -> x1 = x1;
    this -> y0 = y0;
    this -> y1 = y1;
    this -> z0 = z0;
    this -> z1 = z1;
}

CutBox::~CutBox()
{
}

void CutBox::draw(Sculptor &s)
{
    for (int pz = z0; pz <= z1; pz++)
    {
        for (int py = y0; py <= y1; py++)
        {
            for (int px = x0; px <= x1; px++)
            {
                s.cutVoxel(px,py,pz);
            }
        }
    }
}
