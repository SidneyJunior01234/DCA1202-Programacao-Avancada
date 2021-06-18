/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor: Sidney Alves dos Santos Junior
Descricao: reescrever o programa da questao 13
utilizando o qsort() e comentando os trechos de códigos.
*/
#include <stdio.h>
#include <stdlib.h>

/*função destinada a receber as entradas do usuário e 
 *preencher o vetor com os dados de entrada.
 *tem como parâmetros: ponteiro para int e um inteiro.
 o ponteiro para int serve para usar o vetor alocado dinâmicamente.
*/
void coletar_dados(float *vetor, int n)
{
  for (int i = 0; i < n; i++) 
  {
    printf("%d valor: ",(i+1));
    scanf("%f",&vetor[i]);
        
  }
  printf("\nvalores coletados\n");
}

/*imprime para o usuário os dados do vetor.
 *tem como parâmetros: ponteiro para int e um inteiro.
 *o ponteiro para int serve para usar o vetor alocado dinâmicamente.
*/
void imprime_dados(float *vetor, int n)
{
  for (int i = 0; i < n; i++) 
  {
    printf("%.2f ",vetor[i]);
  }
}
/*ponteiro para função que compara dois elementos, responável por
 *definir a ordem dos elementos.
*/
int compare (const void * a, const void * b)
{
  return ( *(float*)a - *(float*)b );
}

int main()
{
  int n;
  float *vet;
  printf("informe a quantidade de dados a serem alocados: ");
  scanf("%d",&n);

  vet = malloc(n * sizeof(float));//alocando um vetor de n lementos
  
  coletar_dados(vet,n);//preenchendo o vetor
  imprime_dados(vet,n);//imprimindo o vetor de entrada
  qsort(vet, n, sizeof(float), compare);//função de ordenação
  printf("\nvalores ordenados\n");
  imprime_dados(vet,n);//imprimeos dados ordenados
  free(vet);//liberando a memoria alocada pelo vetor
  return 0;
}
