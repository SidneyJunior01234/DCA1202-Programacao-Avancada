/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor: Sidney Alves dos Santos Junior
Descricao: criar uma funcao que soma dois vetores e armazena a soma em um terceiro vetor. 
*/
#include <stdio.h>
#include <stdlib.h>

void preenche_vetor(int *vetor, int n)
{
  for (int i = 0; i < n; i++) 
  {
    printf("%d valor: ",(i+1));
    scanf("%d",&vetor[i]);
  }
}

void imprime_vetor(int *vetor, int n)
{
  for (int i = 0; i < n; i++) 
  {
    printf("%d valor: %d\n",(i+1),vetor[i]);
  }
}

void soma_vetor(int *va, int *vb, int *vr, int n)
{
  for(int i = 0; i < n; i++)
  {
    vr[i] = va[i] + vb[i];
  }
}

int main() 
{
  int n = 3;
  int *va, *vb, *vc;

  void (*sv)(int*,int*,int*,int) = &soma_vetor;

  printf("Tamanho do vetor: ");
  scanf("%d",&n);

  va = malloc(n * sizeof(int));
  vb = malloc(n * sizeof(int));
  vc = malloc(n * sizeof(int));

  printf("\npreencha o primeiro vetor:\n");
  preenche_vetor(va,n);

  printf("\npreencha o segundo vetor:\n");
  preenche_vetor(vb,n);

  sv(va,vb,vc,n);

  printf("\nSoma dos vetores\n");
  imprime_vetor(vc,n);
  
  free(va);
  free(vb);
  free(vc);
  return 0;
}
