# Ponteiros em C
#### [Questão 1](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-1/Quest%C3%A3o-1-Resolu%C3%A7%C3%A3o.md)
#### [Questão 2](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-2/Quest%C3%A3o-2-Resolu%C3%A7%C3%A3o.md)
#### [Questão 3](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-3/Quest%C3%A3o-3-Resolu%C3%A7%C3%A3o.md)
#### [Questão 4](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-4/Quest%C3%A3o-4-Resolu%C3%A7%C3%A3o.md)
#### [Questão 5](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-5/Quest%C3%A3o-5-Resolu%C3%A7%C3%A3o.md)
#### [Questão 6](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-6/Quest%C3%A3o-6-Resolu%C3%A7%C3%A3o.md)
#### [Questão 7](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-7/Quest%C3%A3o-7-Resolu%C3%A7%C3%A3o.md)
#### [Questão 8](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-8/Quest%C3%A3o-8-Resolu%C3%A7%C3%A3o.md)
#### [Questão 9](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-9/Quest%C3%A3o-9-Resolu%C3%A7%C3%A3o.md)
#### [Questão 10](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-10/Quest%C3%A3o-10-Resolu%C3%A7%C3%A3o.md)
#### [Questão 11](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-11/Ques%C3%A3o-11-Resolu%C3%A7%C3%A3o.md)
#### [Questão 12](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-12/Quest%C3%A3o-12-Resolu%C3%A7%C3%A3o.md)
#### [Questão 13](https://github.com/SidneyJunior01234/DCA1202-Programacao-Avancada/blob/main/Ponteiros-C/Quest%C3%A3o-13/Quest%C3%A3o-13-Resolu%C3%A7%C3%A3o.md)
## 1.Introdução

Exemplo de declaração de ponteiro: 

`int *ponteiro;` * é o operador unário.

Para recuperar o endereço utilizamos `&`.
 

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
 
Se eu fizer `printf("%p",pont)` será mostrado o endereço do ponteiro. `%p` mostra um hexadecimal.

## 2.Caminhando na memória

Um dos princípios dos ponteiros é percorrer a memória, a partir de um endereço base.

A cada increnento (++ ou +valor) ou decremento (-- ou -valor) o ponteiro caminha `N bytes` (referente ao tamanho do tipo de dado para o qual é apontado).

**Exemplo 1:**

Endereço 1000 da memória e um ponteiro que aponta para um inteiro (4 bytes), ao incrementar mais um (ponteiro++) o endereço vai para 1001...

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

Representação de um array (vetor)

| Elementos | 1 | 2 | 3 | 4 | 5 |
|:---------:|:-:|---|---|---|---|
|  Índices  | 0 | 1 | 2 | 3 | 4 |

Array é uma estrutura indexada que nos permite guardar uma quantidade de informações. Uma vez que incrementamos e decrementamos seus índices, podemos estar acessando 
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

Preenchendo e imprimindo valores.

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
Imprimindo os valores e endereço, uma forma de observar o conteúdo anterior. Pois estamos lidando com inteiros que ocupam 4 bytes na memória,
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
## 4.Alocando arrays

Alocação dinâmica de memóri: são funções que permitem alocar e liberar memória em tempo de execução. Sendo assim,
permite para o programador gerenciar o uso de memória. Para alocar é necessário o uso de ponteiros para guardar os
endereços alocados.

A alocação é feita da seguinte maneira:
Importe da biblioteca stdlib.h `#inclide <stdlib.h>`.
e usando o malloc `void* malloc(size_t size);`

No malloc passamos a quantidade de elementos x(multiplicação) o tamanho do tipo do elemnto.
`int -> 4 bytes`

`quero 10 elentos inteiros`

`logo tenho 10 * 4 = 40`

`malloc(40) ou malloc(10 * sizeof(int))`

`sizeof(int) nos dá o tamanho do inteiro então não precisamos`

`calcular antes de adicionar no malloc, basta informar a`

`quantidade de elementos e multiplicar pelo sizeof do tipo do elemnto`

```
#include <stdio.h>
#include <stdlib.h>

int main() 
{
   int *x;
   x = malloc(10 * sizeof(int));//alocando o vetor
}
```
Após alocar e usar o array alocado, temos que liberar a memória. Para isso usamos o `free(ponteiro)`

**Exemplo de código:**

```
#include <stdio.h>
#include <stdlib.h>

/*malloc(size_t __size) aloca o bloco de memoria
 *free libera o bloco de memoria
 *sempre tem que liberar
 *evita o vazamento de memoria
*/
int main() 
{
  //malloc(int_tam * byte_type)
  int *x;
  x = malloc(10 * sizeof(int));//alocando o vetor

  for(int i = 0; i < 10; i++)
  {
    *(x + i) = i+1;
  }

  for(int i = 0; i < 10; i++)
  {
    printf("valor = %d, enderec = %p\n",*(x + i),x);
  }
  //free(ponteiro) libera a memoria usado pelo malloc
  free(x);
  //free(x);//alteracao duplicada, ja foi liberado. Aparece um erro! se tentar liberar novamente
  return 0;
}
```

## 5.Alocando matrizes

A alocação dinâmica das matrizes são operadas usando ponteiros multidimensionais.
`int **mat` é um ponteiro para ponteiro para inteiro.

**Exemplo:**

`int **x;`

Temo então o array auxiliar. Responsável por guardar os endereços de outros arrays, logo o array auxiliar
são as linhas da nosa matriz.
| int* A |
|:------:|
|    B   |
|    C   |
|    D   |

Os endereços guardados no array auxiliar, nos permite acessar os array que se comportam como as colunas da nossa matriz.
| int A |   |   |   |   |
|:-----:|:-:|:-:|:-:|:-:|
|   B   |   |   |   |   |
|   C   |   |   | E |   |
|   D   |   |   |   |   |

Acessando o elemento `x[2][3]`

```
*(x + 2) -> int* C que aponta para outro array
*(x + 2) + 3 -> E endereço do inteiro.
*(*(x + 2) + 3) -> valor de x[2][3]
```

Alocando a matriz:

```
int nl = 3, nc = 3;
  int **x;

  //alocando a coluna auxiliar
  x = malloc(nl * sizeof(int*));
  //alocando as linhas
  for(int i = 0; i < nl; i++)
  {
    x[i] = malloc(nc * sizeof(int));
  }
  x[0][0] = 1;
  //liberando o espaco
  for(int i = 0; i < nl; i++)
  {
    free(x[i]);//liberando a memoria para cada array que esta sendo apontado
  }
  free(x);//liberando a memoria do array auxiliar
```

Um problema em relação a alocação dinâmica de matrizes, é a não continuidade das linhas quando alocadas no HEAP.

Isso oferece limitações de tempo e espaço na memória. Para isso é preciso garantir que os dados da matriz estejam agrupados.

**Solução:** alocar um único bloco de tamanho **m x n**

Matriz m x n
| A |  B | C | ... | n |
|:-:|:--:|:-:|:---:|:-:|

Vetor auxiliar: irá apontar endereços dos inícios das linhas, que serão alocadas em um bloco contínuos.
| A |  B | C | ... | n |
|:-:|:--:|:-:|:---:|:-:|

**Etapas:**

1.Criação do ponteiro e variáveis a serem utilizadas.
```
int **x, nl, nc, i;
```

2.Alocar o bloco auxiliar
```
x = malloc(nl * sizeof(int*));
```
| A |  B | C | ... | n |
|:-:|:--:|:-:|:---:|:-:|

3.Alocação das linhas

As linhas são alocadas no primeiro elemento do bloco auxiliar
```
z[0] = malloc(nc * nl * sizeof(int));
```
| A |  B | C | ... | n |
|:-:|:--:|:-:|:---:|:-:|

4.Fixar os ponteiros

Guardar os endereços desde o primeiro elemento ao último elemento da matriz.
`z[i - 1] + nc` vai para nc elementos adiantes, no caso o primeiro elemento da próxima linha.
```
for(i = 1; i < nl; i++)
{
    z[i] = z[i - 1] + nc;
}
```

5.Liberar a matriz
```
free(x[0]);
```

6.Liberar o bloco auxiliar
```
free(x);
```
## 6.Structs

Os structs permitem agregar características em uma variável, podemos dizer que estamos "criando um tipo de variável".

```
struct Imagem
{
    char formato[MAX_EXTEN];//ppm, jpg, png, jpeg
    int altura; //linhas
    int largura; //colunas
    int pixels[MAX_PIXELS][MAX_PIXELS];
};
```

Para acessar os atributos da estrutura, utilizamos `->`.

```
#include <stdio.h>

struct Discente
{
    char nome[200];
    char matricula[11];
    float notas[4];
    float media;
};

int main()
{
    struct Discente discente, *dis;
    
    dis = &discente;
    
    printf("Nome do discente: ");
    scanf("%s",dis->nome);
    
    dis->media = 6.9;
    printf("%s tem media %0.2f",dis->nome,dis->media);
    return 0;
}
```
| Enradas |         Saídas       |
|:-------:|:--------------------:|
|   João  |  João tem media 6.90 |
|  Pedro  | Pedro tem media 6.90 |

Podemos também **Alocar arrays de estruturas**.

```
#include <stdio.h>
#include <stdlib.h>

struct Discente
{
  char nome[200];
  char matricula[11];
  float notas[4];
  float media;
};

int main()
{
  struct Discente *dis;

  dis = malloc(10 * sizeof(struct Discente));
  
  dis[1].media = 5.0; // pode ser tambem (dis + 1)->media = 5.0 
  printf("media do discente 2: %.2f",(dis + 1)->media);
  free(dis);

  return 0;
}
```

## 7.Ponteiros para funções

Ponteiros para funções guardam os endereços para **áreas de códigos**.

temos a seguinte função:
```
int Funcao(int a)
{
    return a;
}
```

Agora será criado o ponteiro para a função, mas como?

Resposta: da seguinte maneira.
```
int (*pf)(int) = &Funcao;
```
A declaração do ponteiro precisa de um tipo de retorno `int`, um nome `(*nome_ponteiro)`, informar os parâmetros recebidos `(int)` e passo o endereço da função `&Funcao`. 

Mas como utilizamos o ponteiro?
```
printf("usamos assim...\n");
printf("numero %d", pf(1));
```

**Exemplos:**
```
#include <stdio.h>

int Soma(int a,int b)
{
    return a+b;
}

int main()
{
    int (*pf)(int,int) = &Soma;
    
    printf("valor = %d",pf(2,2));
    return 0;
}
```

```
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
```

Podemos passar também ponteiros para funções como parâmetro de outras funções.

```
#include <stdio.h>

int funcao(int a)
{
  return a;
}
void alo(int (*f)(int))
{
  printf("retorno = %d",f(3));
}

int main(void) 
{
  alo(funcao);
  return 0;
}
```

Podemos também criar funções genéricas.

```
float trapezio(float (*func)(float), float a, float b, int n);
```
