/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor: Sidney Alves dos Santos Junior
Descricao: Considerando a declaração int mat[4], *p, x;, quais das seguintes expressões abaixo são válidas?
Justifique.
*/
#include <stdio.h>

int main()
{
  int mat[4]={0,1,2,3}, *p, x;
  p = mat + 1;//eh valido pois os vetores nao precisam usar o operador de endereco, vemos o incremento de uma posicao no vetor.

  printf("mat = %p\n",mat);
  printf("mat+1 = %p\n",p);

  p = mat++;//nao eh valido, pois essa expressao tenta incrementar um valor inteiro sendo que acontece incremento em int [], no caso um array.

  p = ++mat;//nao eh valido, pois essa expressao tenta incrementar um valor inteiro sendo que acontece incremento em int [], no caso um array.

  x = (*mat);//eh valido, x recebe o valor de mat[0] e depois incrementa o valor
  
  printf("x = %d\n",x);
  return 0;
}
