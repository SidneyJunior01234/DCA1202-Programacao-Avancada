#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel
{
  float r,g,b;//cores: vermelho, verde e azul
  float a;//transparência
  bool isOn=false;//incluso ou nao incluso
};

class Sculptor
{
  protected:
    Voxel ***v;//matriz 3D
    int nx,ny,nz; //dimensoes
    float r,g,b,a; //cores: vermelho, verde e azul, transparencia
  public:
    Sculptor(int _nx, int _ny, int _nz);//construtor
    ~Sculptor();//destrutor
    void setColor(float r, float g, float b, float alpha);//adicionar cor
    void putVoxel(int x, int y, int z);//adicionar voxel
    void cutVoxel(int x, int y, int z);//retirar voxel
    void writeOFF(const char* filename);//gerar arquivo OFF
  };

#endif
