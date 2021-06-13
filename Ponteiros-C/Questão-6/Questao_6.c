/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor: Sidney Alves dos Santos Junior
Descricao: Assumindo que pulo[] é um vetor do tipo int, quais das seguintes 
expressões referenciam o
valor do terceiro elemento do vetor?
*/
#include <stdio.h>

int main() 
{
  int pulo[5] = {1,2,3,4,5};
  
  *(pulo + 2);//esta expressao referencia o terceiro elemento, assumindo que o primeiro 
  //indice do vetor eh 0, temos 2 como terceiro indice que eh o terceiro elemnto.
  printf("%d\n",*(pulo + 2));//impresso 3
  *(pulo + 4);//4 eh o quinto elemento do vetor.
  printf("%d\n",*(pulo + 4));//impresso 5
  pulo + 4;//novamente esta sendo acessado o quinto elemento do vetor.
  printf("%d\n",pulo + 4);//endereco do vetor
  pulo + 2;//o indice para acessar o terceiro elemento esta correto. Mas nao eh possivel obter
  //o valor do elemento por nao ter o operador dereferencia para apontar para o endereco do terceiro indice.
  printf("%d\n",pulo + 4);//endereco do vetor
  return 0;
}
