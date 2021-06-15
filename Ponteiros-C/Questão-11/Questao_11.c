#include <stdio.h>

int main()
{
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;
    
    aloha[2] = value;//eh valido, esta atribuindo um valor na posicao 2 do vetor
    scanf("%f", &aloha);//nao eh valido, vetores sao referenciados e para usar o & aloha deveria ser um ponteiro
    
    //nao eh valido, aloha deve receber um valor float em uma posicao e nao uma string. Alem disso foi utilizado somente aspas duplas para abrir a string ocasionando em tudo que vier depois na linha se torne parte da string
    aloha = value";
    printf("%f", aloha);//eh esperado que o valor impresso fosse um float nao um vetor float
    coisas[4][4] = aloha[3];//eh valido, coisas em uma posicao da matriz recebe um valor de uma posicao do vetor
    coisas[5] = aloha;//nao eh valido, o correto seria passar elemento por elemento em cada posicao 
    pf = value;//nao eh valido, pf nao consegue apontar para value por nao ter o operador de endereco
    pf = aloha;//eh valido, os vetores sao referenciados, logo nao precisam do operador de endereco

    return 0;
}
