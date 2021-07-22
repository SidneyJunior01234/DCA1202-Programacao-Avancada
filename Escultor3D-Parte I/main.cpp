#include <iostream>
#include <fstream>
#include <cmath>

#include "sculptor.h"

using namespace std;

int main()
{
    Sculptor escultor(10,10,10);
        escultor.setColor(0.5,0,1.0,1);
        escultor.putBox(2,3,0,2,2,3);//perna esquerda
        escultor.putBox(2,3,0,2,4,5);//perna direita
        escultor.putBox(2,4,2,6,2,5);//tronco
        escultor.putBox(2,3,3,6,1,2);//braço esquerdo
        escultor.putBox(2,3,3,6,5,6);//braço esquerdo
        escultor.putBox(2,3,6,8,2,5);//cabeça
        escultor.writeOFF("figura.OFF");
    return 0;
}
