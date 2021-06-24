/*
Instituicao: Universidade Federal do Rio Grande do Norte
Disciplina: DCA1202 - Programacao Avancada
Autor(es): Ana Beatriz Fontes Ferreira
           Sidney Alves dos Santos Junior
Descricao: Implemente um programa de computador para testar estas suposições e compare as respostas
oferecidas pelo programa com as respostas que você idealizou.
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
        printf("int = %p, ",(x_int + i));       //considere que caminha de 2 em 2 bytes
        printf("float = %p, ",(x_float + i));
        printf("double = %p\n",(x_double + i));
    }
    return 0;
}
