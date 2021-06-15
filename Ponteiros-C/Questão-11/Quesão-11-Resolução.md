`aloha[2] = value;` -> é válido, está atribuindo um valor na posição 2 do vetor.

`scanf("%f", &aloha);` -> não é válido, vetores são referênciados e não precisa usar o &. Além disso um valor float deveria ser impresso e não um endereço.

`aloha = value";`  -> não é válido, aloha deve receber um valor float em uma posição e não valorcom abertura de uma string. Foi utilizado somente aspas
duplas para abrir a string ocasionando em tudo que vier depois se torne parte da string.

`printf("%f", aloha);` -> é esperado que o valor impresso fosse um float nao um vetor float. Logo não é válido.

`coisas[4][4] = aloha[3];` -> é válido, coisas em uma posição da matriz recebe um valor de uma posiçãoo do vetor e ambos são float.

`coisas[5] = aloha;` -> não é válidoo, o correto seria passar elemento por elemento em cada posição correspondente. 

`pf = value;` -> não é válido, pf não consegue apontar para value por não ter o operador de endereço.

`pf = aloha;` -> é válido, os vetores são referênciados, logo não precisam do operador de endereço para um ponteiro apontá-los.
