/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor(es): Ana Beatriz Fontes Ferreira
           Sidney Alves dos Santos Junior

coletar_dados preenche o vetor com dados inseridos pelo usuario,
tem como parametro um ponteiro que aponta para um vetor de inteiros e
um inteiro referente ao tamanho do vetor.

imprime_dados ira imprimir os valores armazenados no vetor,
tem como parametro um ponteiro que aponta para um vetor de inteiros e
um inteiro referente ao tamanho do vetor.

ordenar_crescente eh responsavel por ordenar o vetor em ordem crescente,
tem como parametro: dois ponteiros para funcoes do tipo void com parametros 
inteiros sendo um deles ponteiro tambem. Um ponteiro para vetor do tipo inteiro
e um inteiro referente ao tamanho do vetor.

na funcao main, um vetor esta sendo alocado, com isso podemos preencher, ordenar 
e liberar o espaco alocado.
*/

#include <stdio.h>
#include <stdlib.h>

void coletar_dados(float *vetor, int n)
{
  for (int i = 0; i < n; i++) 
  {
    printf("%d valor: ",(i+1));
    scanf("%f",&vetor[i]);
        
  }
  printf("\nvalores coletados\n");
}

void imprime_dados(float *vetor, int n)
{
  for (int i = 0; i < n; i++) 
  {
    printf("%.2f ",vetor[i]);
  }
}

void ordenar_crescente(void (*f)(float*,int),float *vetor, int n, void (*i)(float*,int))
{
  int aux = 0;
    
  f(vetor,n);
    
  i(vetor,n);
  
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if(vetor[i] < vetor[j])
      {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  }
  printf("\nvalores ordenados\n");
  i(vetor,n);
}

int main()
{
  int n;
  float *vet;
  printf("informe a quantidade de dados a serem alocados: ");
  scanf("%d",&n);

  vet = malloc(n * sizeof(float));
    
  ordenar_crescente(coletar_dados,vet,n,imprime_dados);

  free(vet);
  return 0;
}
