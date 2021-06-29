/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor(es): Ana Beatriz Fontes Ferreira
           Sidney Alves dos Santos Junior
Descricao: criar um programa que realiza a multiplicacao
de duas matrizes, onde a funcao que realiza a operacao
recebe as matrizes e suas dimensoes.
*/
#include <stdio.h>
#include <stdlib.h>

struct Matriz
{
  int **mat;
  int l;
  int c;
};

void preenche_matriz(struct Matriz *matriz)
{
  for(int i = 0; i < matriz->l; i++)
  {
    for(int j = 0; j < matriz->c; j++)
    {
      printf("a%d,%d: ",i,j);
      scanf("%d",&matriz->mat[i][j]);
    }
  }
}

void imprime_matriz(struct Matriz *matriz)
{
  for(int i = 0; i < matriz->l; i++)
  {
    for(int j = 0; j < matriz->c; j++)
    {
      printf("%d ",matriz -> mat[i][j]);
    }
    printf("\n");
  }
}

void multiplica_matriz(struct Matriz *A,struct Matriz *B,struct Matriz *C)
{
  int soma = 0;

  for(int i = 0; i < A->l; i++)
  {
    for(int j = 0; j < B->c; j++)
    {
      for(int x = 0; x < C->l; x++)
      {
        soma += A->mat[i][x] * B->mat[x][j];
      }
      C->mat[i][j] = soma;
      soma = 0;
    }
  }
}

int main() 
{
  struct Matriz A;
  struct Matriz B;
  struct Matriz C;

  printf("Quantidade de linhas da matriz A: ");
  scanf("%d",&A.l);
  printf("Quantidade de colunas da matriz A: ");
  scanf("%d",&A.c);

  A.mat = malloc(A.l * sizeof(int*));
  A.mat[0] = malloc(A.l * A.c * sizeof(int*));
  for(int i = 1; i < A.l; i++)
  {
    A.mat[i] = A.mat[i - 1] + A.c;
  }

  printf("\nPreencha a matriz A\n");
  preenche_matriz(&A);

  printf("\nQuantidade de linhas da matriz B: ");
  scanf("%d",&B.l);
  printf("Quantidade de colunas da matriz B: ");
  scanf("%d",&B.c);

  B.mat = malloc(B.l * sizeof(int*));
  B.mat[0] = malloc(B.l * B.c * sizeof(int*));
  for(int i = 1; i < B.l; i++)
  {
    B.mat[i] = B.mat[i - 1] + B.c;
  }

  printf("\nPreencha a matriz B\n");
  preenche_matriz(&B);

  C.l = A.l;
  C.c = B.c;

  C.mat = malloc(C.l * sizeof(int*));
  C.mat[0] = malloc(C.l * C.c * sizeof(int*));
  for(int i = 1; i < C.l; i++)
  {
    C.mat[i] = C.mat[i - 1] + C.c;
  }

  multiplica_matriz(&A, &B, &C);

  printf("\nMatriz A\n");
  imprime_matriz(&A);
  printf("\nMatriz B\n");
  imprime_matriz(&B);
  printf("\nMatriz C = A X B\n");
  imprime_matriz(&C);


  free(A.mat[0]);
  free(A.mat);
  free(B.mat[0]);
  free(B.mat);
  free(C.mat[0]);
  free(C.mat);
  return 0;
}
