/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor(es): Ana Beatriz Fontes Ferreira
           Sidney Alves dos Santos Junior
Descricao: implementar uma funcao de ordenacao similar a qsort.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void coletar_dados(float *vetor, int n)
{
  for (int i = 0; i < n; i++) 
  {
    printf("%d valor: ",(i+1));
    scanf("%f",&vetor[i]);
  }
}

void imprime_dados(float *vetor, int n)
{
  for (int i = 0; i < n; i++) 
  {
    printf("%.2f ",vetor[i]);
  }
}

//funcao de comparacao
int compare (const void * a, const void * b)
{
  return ( *(float*)a - *(float*)b );
}

//funcao de ordenacao baseada na qsort
void Ssort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*))
{
  void *a, *b;
    
  for (int i = 0; i < num-1; i++) 
  {
    a = base + (size*i);
    b = base + (size*(i+1));
        
    if(compar(a,b) > 0)
    {
      float *pa = (float*)a;
	    float *pb = (float*)b;
	            
	    float aux = *pb;
	    *pb = *pa;
	    *pa = aux;
    }
    for(int j = num-1; j > 0 && j > i; j--) 
    {
      a = base + (size*j);
      b = base + (size*(j-1));
        
      if(compar(a,b) < 0)
      {
        float *pa = (float*)a;
	      float *pb = (float*)b;
	            
	      float aux = *pa;
	      *pa = *pb;
	      *pb = aux;
      }
    }
  }
}

int main()
{
  int n;
  float *vetor;
  printf("informe a quantidade de dados a serem alocados: ");
  scanf("%d",&n);

  vetor = malloc(n * sizeof(float));
  coletar_dados(vetor,n);
  printf("\nvalores coletados\n");
  imprime_dados(vetor,n);
  
  clock_t t;
    
  t = clock();
  Ssort(vetor,n, sizeof(float),compare);
  
  t = clock() - t;
    
  printf("\nvalores ordenados\n");
  imprime_dados(vetor,n);
  free(vetor);
  
  printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));
  return 0;
}
