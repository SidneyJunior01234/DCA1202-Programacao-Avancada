/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor(es): Ana Beatriz Fontes Ferreira
           Sidney Alves dos Santos Junior
Descricao: exemplo de uso de ponteiros
para funcoes
*/
#include <stdio.h>
void soma(int a, int b)
{
  printf("soma = %d", (a+b));
}

void subtracao(int a, int b)
{
  printf("subtracao = %d", (a-b));
}
void multiplicacao(int a, int b)
{
  printf("multiplicacao = %d", (a*b));
}

void divisao(int a, int b)
{
  printf("divisao = %.2f", ((a*1.0)/b));
}

int main() 
{
  void (*pf_array[])(int,int) = {soma,subtracao,multiplicacao,divisao};
  int opcao = 3, a = 4, b = 3;
  (*pf_array[opcao])(a,b);
  return 0;
}
