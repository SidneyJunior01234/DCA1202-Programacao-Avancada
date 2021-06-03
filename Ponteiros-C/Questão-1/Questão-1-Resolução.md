1.Seja o seguinte trecho de programa:

```
int i = 3, j = 5;
int *p, *q;
p = &i;
q = &j;
```

Determine o valor das seguintes expressões:

```
p == &i;
*p - *q;
**&p;
3 - *p/(*q) + 7;
```

Para determinar os valores das expressões, primeiro temos que saber o que está acontecendo antes.

Foram criadas as variáveis `i` e `j`, logo após os ponteiros `*p` e `*q`. `p` recebeu o endereço de
i (`&i`) e q recebeu o endereço de j (`&j`).

Agora podemos determinar os valores das expressões.

```p == &i;``` -> Utilizando o operador de igualdade, é verificado se o valor armazenado em
p é igual ao endereço de i. Isso é verdade, pois após a criação das variáveis e ponteiros, p 
recebe o endereço de i.

`Resposta: retorna true ou 1.`

```*p - *q;``` -> Nessa expressão, estamos realizando uma operação aritimética. e utilizamos
`*variavel_nome` para acesar o valor para o qual o ponteiro aponta e 
temos * como valor dereferência. Com isso, observamos que `*p` tem o valor de i = 3 
e `*q` o valor de j que é 5. A expressão nos resulta em `3 - 5 = -2`.

`Resposta: retorna -2`

```**&p;``` -> Essa expressão indica o seguinte, há um ponteiro que aponta para um ponteiro
que aponta para um endereço da memória. Logo, observa-se que está sendo pego oum valor de um endereço e 
que estamos apontando para esse endereço, ou seja, estamos apontando para o endereço armazenado em p que é o de i cujo valor é 3.

`Resposta: retorna o valor armazenado em i que é 3.`

```3 - *p/(*q) + 7;``` -> Aqui temos outra operação aritmética, mas agora utilizando divizão. Devido a precedência dos operadores
dividimos os valores armazenados na mémoria ao qual os ponteiros apontam e temos `*p/(*q) = 3/7` se considerarmos inteiro, temos o
resultado igual a 0. com isso resta somente `3 + 7 = 10` como resposta final.

`Resposta: retorna 10.`
