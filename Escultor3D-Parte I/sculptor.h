#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel
{
  float r,g,b;//cores: vermelho, verde e azul
  float a;//transparência
  bool isOn;//incluso ou nao incluso
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
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);//adicionar cubo
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);//retirar cubo
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);//adicionar esfera
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);//remover esfera
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);//adicionar elipsoide
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);//remover elipsoid
    void writeOFF(const char* filename);//gerar arquivo OFF
  };

#endif
