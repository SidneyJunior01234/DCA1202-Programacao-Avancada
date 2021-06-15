/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor: Sidney Alves dos Santos Junior
Descricao: Seja x um vetor de 4 elementos, declarado da forma TIPO x[4];. Suponha que depois da
declaração, x esteja armazenado no endereço de memória 4092 (ou seja, o endereço de x[0]).
Suponha também que na máquina seja usada uma variável do tipo char ocupa 1 byte, do tipo
int ocupa 2 bytes, do tipo float ocupa 4 bytes e do tipo double ocupa 8 bytes. Quais serão os
valores de x+1, x+2 e x+3 se:
◦ x for declarado como char?
◦ x for declarado como int?
◦ x for declarado como float?
◦ x for declarado como double?
*/
#include <stdio.h>

int main()
{
  char x_char[4] = {'a','b','c','d'};         //1 byte
  int x_int[4] = {1,2,3,4};                   //4 bytes, considerar como 2 bytes
  float x_float[4] = {0.1,0.2,0.3,0.4};       //4 bytes
  double x_double[4] = {1.0,2.0,3.0,4.0};     //8 bytes
    
  for (int i = 0; i < 4; i++) 
  {
    printf("char = %p, ",(x_char + i));
    printf("int = %p, ",(x_int + i));         //considere que caminha de 2 em 2 bytes
    printf("float = %p, ",(x_float + i));
    printf("double = %p\n",(x_double + i));
  }
  return 0;
}
