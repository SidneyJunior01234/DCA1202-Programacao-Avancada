/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor: Sidney Alves dos Santos Junior
Descricao: demonstrar o que sera impresso pelos itens do codigo abaixo.
*/
#include <stdio.h>

int main() 
{
  int valor;
  int *p1;
  float temp;
  float *p2;
  char aux;
  char *nome = "Ponteiros";
  char *p3;
  int idade;
  int vetor[3];
  int *p4;
  int *p5;

  /*(a)*/
  valor = 10;
  p1 = &valor;
  *p1 = 20;
  printf("%d\n",valor);//sera impresso 20, p1 aponta para valor = 10 e sobrescreve por 20.

  /*(b)*/
  temp = 26.5;
  p2 = &temp;
  *p2 = 29.0;
  printf("%.1f\n",temp);//sera impresso 29.0, p2 aponta para temp = 26.5 e sobrescreve por 29.0.

  /*(c)*/
  p3 = &nome[0];
  aux = *p3;
  printf("%c\n",aux);//sera impresso P, uma string é um array de caracteres, 
  //logo p3 aponta para o endereco do primeiro elemento de nome e aux recebe esse valor.

  /*(d)*/
  p3 = &nome[4];
  aux = *p3;
  printf("%c\n",aux);//sera impresso e, uma string é um arrat de caracteres, logo p3 aponta 
  //para o endereco do quinto elemento de nome que esta no indice 4 e aux recebe esse valor.

  /*(e)*/
  p3 = nome;
  printf("%c\n",*p3);//sera impresso P, p3 aponta para o array de caracteres nome, mas nao fala 
  //o indice e por padrao o endereco do primeiro indice e o que e apontado. 

  /*(f)*/
  p3 = p3 + 4;
  printf("%c\n",*p3);////sera impresso e, o incremento no ponteiro nos permite caminhar pelo array 
  //indo para 4 indices a frente, no caso o elemento 5 do array.

  /*(g)*/
  p3--;
  printf("%c\n",*p3);//sera impresso t, apos caminhar para o elemento 5, eh decrementado uma posicao 
  //nos permitindo acessar o quarto elemento do array.

  /*(h)*/
  vetor[0] = 31;
  vetor[1] = 45;
  vetor[2] = 27;
  p4 = vetor;
  idade = *p4;
  printf("%d\n",idade);//sera impresso 31, assim como na questao (e), ao apontar para um array e nao 
  //informar o indice, o endereco do primeiro elemento eh adquirido.

  /*(i)*/
  p5 = p4 + 1;
  idade = *p5;
  printf("%d\n",idade);//sera impresso 45, como p4 eh o primeiro elemento do array, ao incementar iremos 
  //para o proximo elemento que eh o 45. Alem disso p5 eh um ponteiro que aponta para o ponteiro p4 que 
  //aponta para array de inteiros.

  /*(j)*/
  p4 = p5 + 1;
  idade = *p4;
  printf("%d\n",idade);//sera impresso 27, como p5 aponta para array de inteiros e esta no segundo indice, 
  //ao incrementar sera recebido por p4 o ultimo elemento de array que eh 27. Alem disso p4 aponta para o 
  //ponteiro p5 que aponta para o array de inteiros.

  /*(l)*/
  p4 = p4 - 2;
  idade = *p4;
  printf("%d\n",idade);//sera impresso 31, como o ultimo indice do array com 3 elementos eh 2, ao deccrementar 
  //2 posicoes, p4 caminha para o inicio do array.

  /*(m)*/
  p5 = &vetor[2] - 1;
  printf("%d\n",*p5);//sera impresso 45, p5 aponta para o array no indice 2 e eh decrementado.

  /*(n)*/
  p5++;
  printf("%d\n",*p5);//sera impresso 27, apos ter sid decrementado e caminhado para o indice 1, ao incrementar p5,
  //caminhamos para o indice 2 que eh o ultimo elemento do array.
  return 0;
}
