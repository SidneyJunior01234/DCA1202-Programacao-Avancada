# DCA1202-Programacao-Avancada

Nesse repositório estará armazenado os códigos fontes 

dos exercícios e projetos propostos na grade curricular do curso.

# Ponteiros em C

## 1.Caminhando na memória

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
