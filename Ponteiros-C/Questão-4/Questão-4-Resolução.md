a) Será impresso `10`, p1 aponta para valor = 10 e é sobrescrito por 20.
```
valor = 10;
p1 = &valor;
*p1 = 20;
printf("%d\n",valor);
```
b) Será impresso `26.5`, p2 aponta para temp = 26.5 e é sobrescrito por 29.0.
```
temp = 26.5;
p2 = &temp;
*p2 = 29.0;
printf("%.1f\n",temp);
```
c) Será impresso `P`, uma string é um array de caracteres, 
logo p3 aponta para o endereço do primeiro elemento de nome e aux recebe esse valor.
```
p3 = &nome[0];
aux = *p3;
printf("%c\n",aux);
```
d) Será impresso `e`, uma string é um array de caracteres, logo p3 aponta 
para o endereço do quinto elemento de nome que esta no índice 4 e aux recebe esse valor.
```
p3 = &nome[4];
aux = *p3;
printf("%c\n",aux);
```
e) Será impresso `P`, p3 aponta para o array de caracteres nome, mas não e informado 
o índice e por padrão o endereço é o do primeiro indice. 
```
p3 = nome;
printf("%c\n",*p3);
```
f) Será impresso `e`, o incremento no ponteiro nos permite caminhar pelo array 
indo para o índice 4, no caso o elemento 5 do array.
```
p3 = p3 + 4;
printf("%c\n",*p3);
```
g) Será impresso `t`, após caminhar para o elemento 5, é decrementado uma posição 
nos permitindo acessar o quarto elemento do array.
```
p3--;
printf("%c\n",*p3);
```
h) Será impresso `31`, assim como na questão (e), ao apontar para um array e não 
informar o índice, o endereço do primeiro elemento é adquirido.
```
vetor[0] = 31;
vetor[1] = 45;
vetor[2] = 27;
p4 = vetor;
idade = *p4;
printf("%d\n",idade);
```
i) Será impresso `45`, como p4 é o primeiro elemento do array, ao incrementar iremos 
para o próximo elemento que é o 45. Além disso p5 é um ponteiro que aponta para o ponteiro p4 que 
aponta para array de inteiros.
```
p5 = p4 + 1;
idade = *p5;
printf("%d\n",idade);
```
j) Será impresso `27`, como p5 aponta para array de inteiros e está no segundo índice, 
ao incrementar será recebido por p4 o último elemento de array que é 27. Além disso p4 aponta para o 
ponteiro p5 que aponta para o array de inteiros.
```
p4 = p5 + 1;
idade = *p4;
printf("%d\n",idade);
```
l) Será impresso `31`, como o último índice do array com 3 elementos é 2, ao decrementar 
2 posições, p4 caminha para o início do array.
```
p4 = p4 - 2;
idade = *p4;
printf("%d\n",idade);
```
m) Será impresso `45`, p5 aponta para o array no índice 2 e é decrementado.
```
p5 = &vetor[2] - 1;
printf("%d\n",*p5);
```
n) Será impresso `27`, apos ter sido decrementado, caminhamos para o índice 1. Ao incrementar p5,
caminhamos para o índice 2 que é o último elemento do array.
```
p5++;
printf("%d\n",*p5);
```
