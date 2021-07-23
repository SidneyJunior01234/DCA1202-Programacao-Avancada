# Escultor 3D - Parte I

### 1.Descrição

O projeto tem como objetivo desenvolver um escultor 3D utilizando Voxel, que são blocos similares aos utilizados
no jogo do minecraft e PixARK.

### 2.Ferramentas

As ferramentas utilizadas foram: linguagem de programação **C++** com as bibliotecas iostream, fstream e cmath; Visual Code e Qt Creator como IDE no desenvolvimento do programa, 
além de usarmos o Meshlab para visualizar.

### 3.Estrutura Voxel

A estrutura Voxel é responsável por guardar as informações do Voxel.

```cpp
struct Voxel 
{
  float r,g,b;//cores: vermelho, verde e azul
  float a;//transparência
  bool isOn = false;//incluso ou nao incluso na estrutura
};
```

### 4.Sculptor

A classe Sculptor é responsável por conter as funcionalidades do Escultor 3D.

```cpp
class Sculptor 
{
  protected:
    Voxel ***v;//ponteiro para matriz 3D
    int nx,ny,nz; //dimensoes x y z
    float r,g,b,a; //cores: vermelho, verde e azul, transparencia
  public:
    Sculptor(int _nx, int _ny, int _nz);//construtor
    ~Sculptor();//destrutor
    void setColor(float r, float g, float b, float alpha);//seleciona cor
    void putVoxel(int x, int y, int z);//adicionar voxel
    void cutVoxel(int x, int y, int z);//retirar voxel
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);//adicionar cubo de voxels
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);//retirar cubo de voxels
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);//adicionar esfera de voxels
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);//remover esfera de voxels
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);//adicionar elipsoide de voxels
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);//remover elipsoid de voxels
    void writeOFF(const char* filename);//gerar arquivo OFF
  };
```

A estrutura Voxel e a classe Sculptor são escritas em um header chamado [sculptor.h](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Escultor3D-Parte%20I/sculptor.h)

No arquivo [sculptor.cpp](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Escultor3D-Parte%20I/sculptor.cpp) atribuimos como irá funcionar cada método da classe Sculptor.

### 5.Resultados

Incluimos o header e o cpp em um arquivo [main.cpp](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Escultor3D-Parte%20I/main.cpp) e executamos, obtendo o seguinte resultado:

```cpp
#include <iostream>
#include <fstream>
#include <cmath>

#include "sculptor.h"

using namespace std;

int main()
{
    Sculptor escultor(10,10,10);//tamanho da escultura 10x10x10
        escultor.setColor(0.5,0,1.0,1);//cor - roxo
        escultor.putBox(2,3,0,2,2,3);//perna esquerda
        escultor.putBox(2,3,0,2,4,5);//perna direita
        escultor.putBox(2,4,2,6,2,5);//tronco
        escultor.putBox(2,3,3,6,1,2);//braço esquerdo
        escultor.putBox(2,3,3,6,5,6);//braço esquerdo
        escultor.putBox(2,3,6,8,2,5);//cabeça
        escultor.writeOFF("figura.OFF");//nome da escultura e extensao
    return 0;
}
```

![Imagem1](https://user-images.githubusercontent.com/50020838/126728147-e44e1845-4ffa-4b3b-8bb5-b45043ea04e8.png)
![Imagem2](https://user-images.githubusercontent.com/50020838/126728160-8804e1cc-a7d0-42ad-b33c-ecc5f545599d.png)
