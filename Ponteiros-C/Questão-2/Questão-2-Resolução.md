`printf("p -> %x\n",p)`endereco em hexadecimal assumindo p apontando para um unsigned int.
`printf("*p = %d\n",*p)`mostra o valor guardado em i para o qual p aponta, com isso temos que:
`printf("*p+2 = %d\n",(*p+2))`mostra o valor para o qual aponta + 2 resultando em 7.
`printf("**&p = %d\n",**&p)`ponteiro para ponteiro de um valor em um endereco, resulta em 5 que eh o valor de i. 
`printf("3**p = %d\n",(3**p))`operacao onde o valor inteiro para o qual p aponta sera multiplicado por 3, no caso resultando em 15.
`printf("**&p+4 = %d\n",(**&p+4))`ponteiro para ponteiro de um valor em um endereco, com isso eh somado 4 resultando em 5 que eh o valorde i que p aponta +4 resultando em 9.
