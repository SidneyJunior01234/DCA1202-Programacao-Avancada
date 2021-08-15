#include "sculptor.h"

#include <iostream>
#include <fstream>
#include <cmath>

Sculptor::Sculptor(int _nx, int _ny, int _nz)//construtor
{
    //dimensoes
    nx = _nx;
    ny = _ny;
    nz = _nz;

    v = new Voxel**[nx];
    v[0] = new Voxel*[nx*ny];
    v[0][0] = new Voxel[nx*ny*nz];

    //v[1] = v[0] + ny*sizeof(Voxel**);

    ///alocando em 2 dimensoes
    for(int i=1; i<nz; i++)
    {
        v[i] = v[i-1] + ny;
    }

    //alocando em 3 dimensoes
    for(int i=1; i<nz*ny; i++)
    {
        v[0][i] = v[0][i-1] + nx;
    }
    std::cout << "Area da escultura criada!" << std::endl;
}

Sculptor::~Sculptor()//destrutor
{
    //esvaizando a memoria
    delete v[0][0];
    delete v[0];
    delete v;
}

void Sculptor::setColor(float r, float g, float b, float alpha)//selecionar cor
{
    if(r>=0 && r<=1)
    {
        //usando o this para mostrar que a variavel da classe recebe o valor do parametro da funcao
        this -> r = r;
    }
    if(g>=0 && g<=1)
    {
        this -> g = g;
    }
    if(b>=0 && b<=1)
    {
        this -> b = b;
    }
    if(alpha>=0 && alpha<=1)
    {
        a = alpha;
    }
}

void Sculptor::putVoxel(int x, int y, int z)//adicionar voxel
{
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
}

void Sculptor::cutVoxel(int x, int y, int z)//retirar voxel
{
      v[x][y][z].isOn = false;
}

void Sculptor::writeOFF(const char* filename)//gerar arquivo OFF
{
    std::ofstream fileOutput;//responsavel por gerar o arquivo

    fixed(fileOutput);//precisao das casas decimais, melhor que multiplicar as cores por 255

    int vertices = 0;//quantidade de vertices
    int faces = 0;//quantidade de faces
    int position = 0;//posicoes das faces

    fileOutput.open(filename);//abrir arquivo com o nome especificado

    //verificar se foi possivel abrir o arquivo, caso contrario encerra o programa
    if(fileOutput.is_open())
    {
        std::cout << "Arquivo aberto com sucesso...\nAguarde enquanto o arquivo esta sendo escrito..." << std::endl;
    }
    else
    {
        std::cout << "Nao foi possível abrir o arquivo." << std::endl;
        exit(EXIT_FAILURE);
    }

    fileOutput << "OFF" << std::endl;//escrevendo o formato do arquivo

    //calculando a quantidade de vertices e faces dos voxels
    for (int px = 0; px < nx; px++)
    {
        for (int py = 0; py < ny; py++)
        {
            for (int pz = 0; pz < nz; pz++)
            {
                if (v[px][py][pz].isOn)
                {
                    vertices += 8;
                    faces += 6;
                }
            }
        }
    }

    fileOutput << vertices << ' ' << faces << ' ' << 0 << std::endl;//escrevendo quantidade de vertices e faces

    //escrevendo as posicoes dos vertices
    for (int px = 0; px < nx; px++)
    {
        for (int py = 0; py < ny; py++)
        {
            for (int pz = 0; pz < nz; pz++)
            {
                if (v[px][py][pz].isOn)
                {
                    fileOutput << (px - 0.5) << ' ' << (py + 0.5) << ' ' << (pz - 0.5) << std::endl;
                    fileOutput << (px - 0.5) << ' ' << (py - 0.5) << ' ' << (pz - 0.5) << std::endl;
                    fileOutput << (px + 0.5) << ' ' << (py - 0.5) << ' ' << (pz - 0.5) << std::endl;
                    fileOutput << (px + 0.5) << ' ' << (py + 0.5) << ' ' << (pz - 0.5) << std::endl;
                    fileOutput << (px - 0.5) << ' ' << (py + 0.5) << ' ' << (pz + 0.5) << std::endl;
                    fileOutput << (px - 0.5) << ' ' << (py - 0.5) << ' ' << (pz + 0.5) << std::endl;
                    fileOutput << (px + 0.5) << ' ' << (py - 0.5) << ' ' << (pz + 0.5) << std::endl;
                    fileOutput << (px + 0.5) << ' ' << (py + 0.5) << ' ' << (pz + 0.5) << std::endl;
                }
            }
        }
    }

    //escrevendo a conexao dos vertices para formar as faces e suas cores
    for (int px = 0; px < nx; px++)
    {
        for (int py = 0; py < ny; py++)
        {
            for (int pz = 0; pz < nz; pz++)
            {
                if (v[px][py][pz].isOn)
                {
                    fileOutput << 4 << ' ' << position + 0 << ' ' << position + 3 << ' ' << position + 2 << ' ' << position + 1 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;

                    fileOutput << 4 << ' ' << position + 4 << ' ' << position + 5 << ' ' << position + 6 << ' ' << position + 7 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;

                    fileOutput << 4 << ' ' << position + 0 << ' ' << position + 1 << ' ' << position + 5 << ' ' << position + 4 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;

                    fileOutput << 4 << ' ' << position + 0 << ' ' << position + 4 << ' ' << position + 7 << ' ' << position + 3 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;

                    fileOutput << 4 << ' ' << position + 3 << ' ' << position + 7 << ' ' << position + 6 << ' ' << position + 2 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;

                    fileOutput << 4 << ' ' << position + 1 << ' ' << position + 2 << ' ' << position + 6 << ' ' << position + 5 << ' ' << v[px][py][pz].r << ' ' << v[px][py][pz].g << ' ' << v[px][py][pz].b << ' ' << v[px][py][pz].a << std::endl;

                    position += 8;
                }
            }
        }
    }

    //fechando o arquivo
    fileOutput.close();
    std::cout << filename << " foi criado com sucesso!" << std::endl;
}
