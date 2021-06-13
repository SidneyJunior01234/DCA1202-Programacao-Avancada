`p = i;` -> p nao consegue apontar para i, precisa do & que é o operador de endereço. Logo é uma atribuição não legal.

`q = &j;` -> atribuiçãoo legal, q consegue apontar para j. Pois há o operador de endereço.

`p = &*&i;` -> `&(*(&i))` endereço do valor armazenado no endereço de i, basicamente aponta para o endereço de i que tem valor 3, atribuiçãoo legal.

`i = (*&)j;` -> atribuição não legal, i não consegue receber o vaor do endereço, pois o j está fora dos parênteses. 
  
`i = *&j;` -> atribuição legal, i só está recebendo o valor guardado no endereço de j cujo o valor é 5.

`i = *&*&j;` -> atribuição legal, i recebe um valor em um endereço. É o mesmo que `*&j` = 5.

`q = *p;` -> atribuição não legal, deveria ser atribuído um endereço usando operador de endereço e não um operador dereferência.

`i = (*p)++ + *q;` -> atribuiçãoo legal, o valor para o qual p aponta é somado com o que q aponta e depois incrementa o valor apontado por p.
