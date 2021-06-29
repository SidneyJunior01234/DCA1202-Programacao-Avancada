#include "gc.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  clock_t t;

  GC_INIT();

  t = clock();
  int **p = GC_MALLOC(sizeof *p);
  GC_FREE(p);
  t = clock() - t;
  printf("\nTempo de execucao(gc): %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));

  t = clock();
  int *q = malloc(sizeof(int));
  free(q);
  t = clock() - t;
  printf("\nTempo de execucao(dinamicamente): %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));

  return 0;
}
