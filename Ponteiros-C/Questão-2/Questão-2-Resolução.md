`"%x\n",p` -> endereço em hexadecimal assumindo que, p aponta para um unsigned int, obtemos FFE para o endereço 4049.

`%d\n",*p+2` ->  `*p` mostra o valor guardado em i para o qual p aponta, com isso temos que o valor para o qual aponta + 2 resulta em 7.

`%d\n",**&p` -> ponteiro para ponteiro de um valor em um endereco, resulta em 5 que é o valor de i. 

`%d\n",3**p` -> operação onde o valor inteiro para o qual p aponta será multiplicado por 3, no caso resultando em 15.

`%d\n",**&p+4` -> ponteiro para ponteiro de um valor em um endereço, com isso é somado 4 resultando em 5 que eh o valorde i que p aponta +4 resultando em 9.
