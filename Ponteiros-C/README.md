# Ponteiros em C

## 1.Introdução

Exemplo de declaração de ponteiro: 

`int *ponteiro;` * é o operador unário.

para recuperar o endereço utilizamos `&`.
 

**Exemplo:**

`int *ponteiro, x;`
 
`ponteiro = &x;` & é o operador de endereço.

Esse exemplo mostra que, a variável ponteiro recebe o endereço de `x`.
 
Para adquirir o conteúdo da variável ponteiro usamos o `*` novamente.
 
`int *ponteiro, x, y;`
 
`x = 2.`
 
`ponteiro = &x;`
 
`y = *ponteiro;` nesse caso o * é o operador **dereferência**.
 
`int x, *pontx = &x;` pont aponta para x.
 
se eu fizer `printf("%p",pont)` será mostrado o endereço do ponteiro. `%p` mostra um hexadecimal.

## 2.Caminhando na memória

Um dos princípios dos ponteiros é percorrer a memória, a partir de um endereço base.

A cada increnento (++ ou +valor) ou decremento (-- ou -valor) o ponteiro caminha `N bytes` (referente ao tamanho do tipo de dado para o qual é apontado).

**Exemplo 1:**

endereço 1000 da memória e um ponteiro que aponta para um inteiro (4 bytes), ao incrementar mais um (ponteiro++) o endereço vai para 1001...

Errado! vai para 1004 pois depende para o qual o tipo de dado é apontado, no caso um inteiro (4 bytes) se fosse um char (1 byte) seria 1001.

**Exemplo 2:**

```
#include <stdio.h>

int main() 
{
    unsigned int x; //ocupa 4 bytes na memoria
    unsigned char *px; //ocupa 1 byte na memoria
    x = 289;
    px = &x; //px aponta/recebe a posicao de x na memoria
    printf("%d\n",*px); //33 -> quantidade de bits para completar 289 com o 256 do incremento
    px += 1; //caminha um passo na memoria por causa do unsigned char
    printf("%d\n",*px); // 1 -> 256
    return 0;
}
```

```
#include <stdio.h>

int main()
{
    unsigned int x; //ocupa 4 bytes na memoria
    unsigned char *px; //ocupa 1 byte na memoria
    x = 3;
    px = &x; //px aponta/recebe a posicao de x na memoria
    *px = 1; //primeiro byte
    *px++; //caminha um passo na memoria por causa do unsigned char
    printf("x = %d",x) //resultado 257
    return 0;
}
```
