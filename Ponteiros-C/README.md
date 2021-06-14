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

## 3.Caminhando em arrays

representação de um array (vetor)

| Elementos | 1 | 2 | 3 | 4 | 5 |
|:---------:|:-:|---|---|---|---|
|  Índices  | 0 | 1 | 2 | 3 | 4 |

array é uma estrutura indexada que nos permite guardar uma quantidade de informações. Uma vez que incrementamos e decrementamos seus índices, podemos estar acessando 
os elementos guardados no array.

criando o array e o ponteiro que aponta para ele.
```
int x[10]; //array com capacidade para 10 elementos
  int *px; //ponteiro que aponta para o array nao precisa de &
  //array ja eh referenciado
  int i; // indexador

  px = x; //ponteiro que aponta para o array nao, precisa de & array ja eh referenciado
  //aqui o px aponta para x[0]
```

preenchendo e imprimindo valores.

```
//adicionando elementos no array
  for(i = 0; i < 10; i++)
  {
    //x[i] = i + 1;
    //*(px+i) = i + 1;
    px[i] = i + 1; // tambem funciona
  }
  //mostrando na tela os valores do arrray
  for(i = 0; i < 10; i++)
  {
    printf("%d ",x[i]);
  }
  
  Saída: 1 2 3 4 5 6 7 8 9 10
```
imprimindo os valores e endereço, uma forma de observar o conteúdo anterior. Pois estamos lidando com inteiros que ocupam 4 bytes na memória,
logo observamos que para cada espaço alocado temos uma diferença de 4 bytes no endereço.

```
for(i = 0; i < 10; i++)
  {
    //printf("*p = %d, enderec = %p\n",*(px + 1 + i),(px + 1 + i)); // imprimindo o valor que px aponta e seu endereco
    //altero a posicao *(px+1+i),px+1+i) sem alterar o array
    //px = px + 1;//incrementando uma posicao
    printf("*p = %d, enderec = %p\n",px[i+1],(px + 1 + i)); //tambem funciona
  }
  
  Saída:
        *p = 1, enderec = 0x7ffc316e3c60
        *p = 2, enderec = 0x7ffc316e3c64
        *p = 3, enderec = 0x7ffc316e3c68
        *p = 4, enderec = 0x7ffc316e3c6c
        *p = 5, enderec = 0x7ffc316e3c70
        *p = 6, enderec = 0x7ffc316e3c74
        *p = 7, enderec = 0x7ffc316e3c78
        *p = 8, enderec = 0x7ffc316e3c7c
        *p = 9, enderec = 0x7ffc316e3c80
        *p = 10, enderec = 0x7ffc316e3c84
```

## 4.Caminhando em matrizes
