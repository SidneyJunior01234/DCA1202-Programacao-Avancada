Para x um vetor: `TIPO x[4];` sua posição `x[0]` tem o endereço `4092`.

Assumindo que: `char` ocupa `1 byte`, `int` ocupa `2 bytes`, `float` ocupa `4 bytes` e `double` ocupa `8 bytes`.

Quais serão os valores de `x + 1`, `x + 2` e `x + 3` se:

como não está sendo usado o operador dereferência, será impresso o endereço de cada posição do vetor.

x for declarado como char?

Ao incrementar, caminharemos 1 byte na memória, valor referente ao quanto o char ocupa.
```
x[0] -> 4092
x + 1 -> 4093 
x + 2 -> 4094
x + 3 -> 4095
```

x for declarado como int?

Ao incrementar, caminharemos 2 bytes na memória, valor referente ao quanto o int ocupa.
```
x[0] -> 4092
x + 1 -> 4094
x + 2 -> 4096
x + 3 -> 4098
```

x for declarado como float?

Ao incrementar, caminharemos 4 bytes na memória, valor referente ao quanto o float ocupa.
```
x[0] -> 4092
x + 1 -> 4096
x + 2 -> 4100
x + 3 -> 4104
```

x for declarado como double?

Ao incrementar, caminharemos 8 bytes na memória, valor referente ao quanto o double ocupa.
```
x[0] -> 4092
x + 1 -> 4100
x + 2 -> 4108
x + 3 -> 4116
```
