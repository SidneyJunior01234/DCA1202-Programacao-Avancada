#include "interpretador.h"

#include "putvoxel.h"
#include "cutvoxel.h"

#include "putbox.h"
#include "cutbox.h"

#include "putsphere.h"
#include "cutsphere.h"

#include "putellipsoid.h"
#include "cutellipsoid.h"

#include <fstream>
#include <sstream>
#include <iostream>

Interpretador::Interpretador()
{
    std::cout << "Interpretador iniciado!" << std::endl;
}

Interpretador::~Interpretador()
{
}

std::vector<FiguraGeometrica*> Interpretador::parse(std::string filename)
{
    std::vector<FiguraGeometrica*> figs;
    std::ifstream fileInput;
    std::stringstream ss;
    std::string s, token;

    fileInput.open(filename.c_str());

    if(!fileInput.is_open())
    {
        std::cout << "Nao foi possível abrir o arquivo." << std::endl;
        exit(EXIT_FAILURE);
    }

    while (fileInput.good())
    {
        std::getline(fileInput,s);
        ss.clear();
        ss.str(s);

        ss >> token;

        if (token.compare("dim") == 0)
        {
            ss >> dimX >> dimY >> dimZ;
        }
        else if(token.compare("putvoxel")==0)
        {
            int x, y, z;
            ss >> x >> y >> z >> r >> g >> b >> a;
            figs.push_back(new PutVoxel(x,y,z,r,g,b,a));
        }
        else if(token.compare("cutvoxel")==0)
        {
            int x, y, z;
            ss >> x >> y >> z;
            figs.push_back(new CutVoxel(x,y,z));
        }
        else if(token.compare("putbox")==0)
        {
            int x0,x1,y0,y1,z0,z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figs.push_back(new PutBox(x0,x1,y0,y1,z0,z1,r,g,b,a));
        }
        else if(token.compare("cutbox")==0)
        {
            int x0,x1,y0,y1,z0,z1;
            ss >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 ;
            figs.push_back(new CutBox(x0,x1,y0,y1,z0,z1));
        }
        else if(token.compare("putsphere")==0)
        {
            int xcenter, ycenter, zcenter, radius;
            ss >> xcenter >> ycenter >> zcenter >> radius >> r >> g >> b >> a;
            figs.push_back(new PutSphere(xcenter,ycenter,zcenter,radius,r,g,b,a));
        }
        else if(token.compare("cutsphere")==0)
        {
            int xcenter, ycenter, zcenter, radius;
            ss >> xcenter >> ycenter >> zcenter >> radius;
            figs.push_back(new CutSphere(xcenter,ycenter,zcenter,radius));
        }
        else if(token.compare("putellipsoid")==0)
        {
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figs.push_back(new PutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz,r,g,b,a));
        }
        else if(token.compare("cutellipsoid")==0)
        {
            int xcenter, ycenter, zcenter, rx, ry, rz;
            ss >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            figs.push_back(new CutEllipsoid(xcenter,ycenter,zcenter,rx,ry,rz));
        }
    }
    return figs;
}

int Interpretador::getDimX()
{
    return dimX;
}

int Interpretador::getDimY()
{
    return dimY;
}

int Interpretador::getDimZ()
{
    return dimZ;
}
