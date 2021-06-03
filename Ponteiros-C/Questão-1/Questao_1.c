/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor: Sidney Alves dos Santos Junior
Descricao: determinar o valor das expressoes.
  p == &i;
  *p - *q;
  **&p;
  3 - *p/(*q) + 7;
*/
#include <stdio.h>
int main(void) 
{
  int i=3, j=5;
  int *p, *q;
  p = &i; //p recebe o endereco de i
  q = &j; //q recebe o endereco de j

  printf("p == &i -> %d\n",(p == &i)); //valor de p eh o endereco de i?
  printf("*p - *q -> %d\n",(*p - *q)); //valor de p menos o valor de q
  printf("**&p -> %d\n",(**&p)); //ponteiro para ponteiro para endereço
  printf("3 - *p/(*q) + 7 -> %d\n",(3 - *p/(*q) + 7)); //operacao aritimetica
  return 0;
}
