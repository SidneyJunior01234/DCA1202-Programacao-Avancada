#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "figurageometrica.h"
#include "sculptor.h"

#include <string>
#include <vector>

class Interpretador
{
    private:
        int dimX, dimY, dimZ;
        float r, g, b, a;
    public:
        Interpretador();
        ~Interpretador();

        std::vector<FiguraGeometrica*> parse(std::string filename);

        int getDimX();
        int getDimY();
        int getDimZ();
};

#endif // INTERPRETADOR_H
