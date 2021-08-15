# Escultor 3D - Parte II

### 1.Descrição

Nessa etapa do projeto, temos como objetivo criar uma classe abstrata `FiguraGeometrica` que será a classe base para a criação de classes que irão substituir os métodos do Sculptr. Além disso teremos que ler um arquivo `.txt` que dará comandos de criação da nossa escultura.

### 2.Classe FiguraGeometrica

A classe figura geometrica é responsável por guardar as cores da figura e por manter o método abstrato `draw` que é responsável por desenhar a figura no escultor. 

```cpp
#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "sculptor.h"
#include "sculptor.cpp"

class FiguraGeometrica
{
    protected:
        float r, g, b, a;
    public:
        FiguraGeometrica();
        virtual ~FiguraGeometrica();
        virtual void draw(Sculptor &s)=0;
};

#endif
```

### 3.Herdeiros

As classes que herdam de `FiguraGeometrica` acabam sendo similares entre si, a diferença é a quantidade de atributos e a forma que o `draw` será escrito.
O `draw` recebe como parâmetro o endereço de um `Sculptor` que é reponsável por ser a área de criação da escultura.

**putvoxel.h
```cpp
#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class PutVoxel : public FiguraGeometrica
{
    private:
        int x, y, z;
    public:
        PutVoxel(int x, int y, int z, float r,float g,float b,float a);
        ~PutVoxel();
        void draw(Sculptor &s);
};

#endif
```

**putvoxel.cpp**
```cpp
#include "putvoxel.h"

PutVoxel::PutVoxel(int x, int y, int z, float r,float g,float b,float a)
{
    this -> x = x;
    this -> y = y;
    this -> z = z;
    this -> r = r;
    this -> g = g;
    this -> b = b;
    this -> a = a;
}

PutVoxel::~PutVoxel()
{
}

void PutVoxel::draw(Sculptor &s)
{
    s.setColor(r,g,b,a);
    s.putVoxel(x,y,z);
}
```

**cutvoxel.h**
```cpp
#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"
#include "sculptor.h"

class CutVoxel : public FiguraGeometrica
{
    private:
        int x, y, z;
    public:
        CutVoxel(int x, int y, int z);
        ~CutVoxel();
        void draw(Sculptor &s);
};

#endif
```

**cutvoxel.cpp**
```cpp
#include "cutvoxel.h"

CutVoxel::CutVoxel(int x, int y, int z)
{
    this -> x = x;
    this -> y = y;
    this -> z = z;
}

CutVoxel::~CutVoxel()
{
}

void CutVoxel::draw(Sculptor &s)
{
    s.cutVoxel(x,y,z);
}
```

### 4.Interpretador

Comos sujestão foi criado um interpretador que é responsável por ler um arquivo `.txt` e retornar o seguinte:

**Dimensões da escultura**

**Container de FigurasGeometricas**

**interpretador.h**
```cpp
#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "figurageometrica.h"
#include "sculptor.h"
#include <iostream>
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

#endif
```

**interpretador.cpp**
```cpp
#include "interpretador.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

#include <iostream>
#include <fstream>
#include <sstream>

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
```

### 5.Main

A main é responsável por criar um ponteiro para Sculptor,um container de FigurasGeometrica e o interpretador. Após ler o arquivo, e retornar o container, temos que adicionar as figuras no Sculptor, após isso criar o arquivo `.OFF` e liberar o espaço alocado.

**main.cpp**
```cpp
#include "interpretador.h"
#include "interpretador.cpp"

#include "figurageometrica.h"
#include "figurageometrica.cpp"

#include "sculptor.h"
#include "sculptor.cpp"

#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    Sculptor *escultor;
    Interpretador interpretador;
    std::vector<FiguraGeometrica*> figs;
    
    figs = interpretador.parse("teste.txt");
    escultor = new Sculptor(interpretador.getDimX(),interpretador.getDimY(),interpretador.getDimZ());

    for (int index = 0; index < figs.size(); index++)
    {
        figs[index]->draw(*escultor);
    }
    
    escultor->writeOFF("figura.OFF");

    for (int index = 0; index < figs.size(); index++)
    {
        delete figs[index];
    }
    delete escultor;
    
    return 0;
}
```

### 6.Resultados

Para as seguintes figuras iremos obter

**creeper.txt**

```
dim 20 30 20
putbox 6 13 0 1 4 7 0.0 0.0 0.0 1.0
putbox 6 13 0 1 12 15 0.0 0.0 0.0 1.0
putbox 6 13 2 5 4 7 0.0 0.6 0.0 1.0
putbox 6 13 2 5 12 15 0.0 0.6 0.0 1.0
putbox 6 13 6 18 8 11 0.0 0.6 0.0 1.0
putbox 5 14 18 25 5 14 0.0 0.6 0.0 1.0
putbox 7 8 23 24 13 14 0.0 0.0 0.0 1.0
putbox 8 8 19 21 13 14 0.0 0.0 0.0 1.0
putbox 9 10 20 22 13 14 0.0 0.0 0.0 1.0
putbox 11 12 23 24 13 14 0.0 0.0 0.0 1.0
putbox 11 11 19 21 13 14 0.0 0.0 0.0 1.0
```

![creeper_front](https://user-images.githubusercontent.com/50020838/129486266-39cc0c98-0470-4636-8b04-fca9f7779d78.png)
![creeper_diago](https://user-images.githubusercontent.com/50020838/129486286-35c8b74f-5a03-4f5e-818d-174c9bf82ffe.png)
![creeper_later](https://user-images.githubusercontent.com/50020838/129486347-2731528e-6a66-4585-9c17-b864a0ece09c.png)
