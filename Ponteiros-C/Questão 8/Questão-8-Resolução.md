Esse primeiro programa utiliza o laço de repetição `for` e o `printf` para imprimir os
valores armazenados em cada posição do vetor.

```
int main()
{
  int vet[] = {4,9,13};
  int i;
  for(i=0;i<3;i++)
  {
      printf("%d ",*(vet+i));
  }
}
```

Esse primeiro programa utiliza o laço de repetição `for` e o `printf` para imprimir os
endereços de cada posição do vetor.
```
int main()
{
  int vet[] = {4,9,13};
  int i;
  for(i=0;i<3;i++)
  {
      printf("%X ",vet+i);
  }
}
```

Ambos os programas mostram como caminhar nas posições do array. A forma que é caminhada no
array é similar ao uso deponteiros.
