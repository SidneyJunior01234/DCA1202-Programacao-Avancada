Ponteiro para função serve para definir qual função será executada durante o código, dessa forma o ponteiro guarda otrechos de código.

temos como exemplo de código:

```
#include <stdio.h>

void soma(int a, int b)
{
  printf("soma = %d", (a+b));
}

int main() 
{
  void *pf(int,int) = &soma;
  pf(a,b);
  return 0;
}
```

[Questao_12.c](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-12/Questao_12.c)
