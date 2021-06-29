/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor(es): Ana Beatriz Fontes Ferreira
           Sidney Alves dos Santos Junior
Descricao: O que faz o seguinte programas em C?
*/
#include <stdio.h>

int main() 
{
  int vet[] = {4,9,13};//criado o vetor com tamanho 3
  int i;//indice
  for(i=0;i<3;i++)
  {
    printf("%X ",vet+i);//imprimir os enderecos das posicoes do vetor de acordo com o indice
  }
  return 0;
}
