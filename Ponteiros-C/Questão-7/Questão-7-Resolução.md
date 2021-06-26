`p = mat + 1;` -> é válido pois os vetores nao precisam usar o operador de endereço, vemos o incremento de uma posicao no vetor 
e p recebe o endereço dessa posição encrementada.

`p = mat++;` -> não é válido, pois essa expressão tenta incrementar um valor inteiro: mat[0]++, mas não é possível incrementar o tipo array.
OBS: int = 4 bytes, o vetor não pode incrementar 1 byte

`p = ++mat;` -> não é válido, pois essa expressão tenta incrementar um valor inteiro: ++mat[0], mas não é possível incrementar o tipo array.
OBS: int = 4 bytes, o vetor não pode incrementar 1 byte

`x = (*mat);` -> é válido, x recebe o valor de mat[0] e depois incrementa o valor, mas não armazena no próprio x.
