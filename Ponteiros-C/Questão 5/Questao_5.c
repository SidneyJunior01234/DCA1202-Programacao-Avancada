/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor(es): Ana Beatriz Fontes Ferreira
           Sidney Alves dos Santos Junior
Descricao: determine o que sera mostrado pelo seguinte programa
*/
#include <stdio.h>

int main(void) 
{
  float vet[5] = {1.1,2.2,3.3,4.4,5.5};
  float *f;
  int i;
  f = vet;//nao eh necessario o operador de endereco o array ja eh referencia o endereco.
  printf("contador/valor/valor/endereco/endereco");
  for(i = 0 ; i <= 4 ; i++){
  printf("\ni = %d",i);//ira mostrar o indice pelo qual sera percorrido no array
  printf("vet[%d] = %.1f",i, vet[i]);//mostra o valor do elemento guardado no indice i do vetor
  printf("*(f + %d) = %.1f",i, *(f+i));//caminha pelo vetor de acordo com o indice que i incrementa, é similar ao vet[i]
  printf(" &vet[%d] = %X",i, &vet[i]);//mostra o endereco em hexadecimal do array no indice i
  printf("(f + %d) = %X",i, f+i);//mostra o endereco em hexadecimal do array no indice i
 }
 //esse codigo mostra as formas de caminhar pelo array.
 return 0;
}
