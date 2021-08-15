#include "figurageometrica.h"
#include "interpretador.h"
#include "sculptor.h"

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Sculptor *escultor;

       Interpretador interpretador;

       vector<FiguraGeometrica*>figs;

       figs = interpretador.parse("creeper.txt");

       escultor = new Sculptor(interpretador.getDimX(), interpretador.getDimY(), interpretador.getDimZ());

       for(size_t index=0;index<figs.size();index++){
           figs[index]->draw(*escultor);
       }

       escultor->writeOFF((char*) "creeper.off");
       for(size_t index=0;index<figs.size();index++){
           delete figs[index];
       }
       delete escultor;
       return 0;
}
