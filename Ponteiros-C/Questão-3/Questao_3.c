/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor: Sidney Alves dos Santos Junior
Descricao: se i e j sao inteiros e p e q sao ponteiros para inteiros, informe se as atribuicoes sao legais.
  p = i;
  q = &j;
  p = &*&i;
  i = (*&)j;
  i = *&j;
  i = *&*&j;
  q = *p;
  i = (*p)++ + *q;
*/

#include <stdio.h>

int main() 
{
  int i = 3, j = 5;
  int *p, *q;

  p = i; //p nao consegue apontar para i, precisa do & que eh o operador de endereco. Logo eh uma atribuicao nao legal.

  q = &j;//atribuicao legal, q consegue apontar para j. Pois ha o operador de endereco.
  printf("q = &j; -> %d\n",*q);

  p = &*&i;//&(*(&i)) endereco do valor armazenado no endereco de i, basicamente o endereco de i que guarda o valor 3, atribuicao legal.
  printf("p = &*&i; -> %d\n",*p);

  i = (*&)j;//atribuicao nao legal, i nao consegue receber o valor do endereco, pois o j esta fora dos parenteses. 
  
  i = *&j;//atribuicao legal, i so esta recebendo o valor guardado no endereco de j que eh 5.
  printf("i = *&j; -> %d\n",i);

  i = *&*&j;//atribuicao legal, i recebe um valor em um endereco. Eh o mesmo que *&j = 5.
  printf("i = *&*&j; -> %d\n",i);

  q = *p;//atribuicao nao legal, deveria ser atribuido um endereco usando operador de endereco e nao um operador dereferencia.
  
  i = 3;
  j = 5;
  p = &i;
  q = &j;

  i = (*p)++ + *q;// atribuicao legal, o valor para o qual p aponta e somado com o que q aponta e depois incrementa o valor apontado por p.
  printf("i = (*p)++ + *q; -> %d\n",i);

  return 0;
}
