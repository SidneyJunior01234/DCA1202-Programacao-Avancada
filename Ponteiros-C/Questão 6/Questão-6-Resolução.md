| Elementos |  1° |  2° |  3° |  4° |  5° |
|:---------:|:---:|-----|-----|-----|-----|
|  Índices  |  0  |  1  |  2  |  3  |  4  |

`*(pulo + 2);` -> essa expressão referencía o terceiro elemento do vetor, assumindo que o primeiro 
índice do vetor é 0, temos 2 como terceiro índice que é o terceiro elemento.

`*(pulo + 4);` -> 4 é o quinto elemento do vetor.

`pulo + 4;` -> novamente está sendo acessado o quinto elemento do vetor.

`pulo + 2;` -> o índice para acessar o terceiro elemento está correto. Mas não é possível obter
o valor do elemento por não ter o operador dereferência para apontar para o endereço do terceiro índice.
