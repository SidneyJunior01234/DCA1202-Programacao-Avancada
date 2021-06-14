Comparando as saídas do programa feito em C, os valores esperados estão de acordo, assumindo que int ocupe 2 bytes na memória.

O inteiro ocupa 4 bytes e os endereços impressos são de 4 em 4 bytes. Por isso devemos assumir que int vale 2 bytes.

**Exemplos de saídas**

```
char = 0x7ffd194a6d64, int = 0x7ffd194a6d20, float = 0x7ffd194a6d30, double = 0x7ffd194a6d40
char = 0x7ffd194a6d65, int = 0x7ffd194a6d24, float = 0x7ffd194a6d34, double = 0x7ffd194a6d48
char = 0x7ffd194a6d66, int = 0x7ffd194a6d28, float = 0x7ffd194a6d38, double = 0x7ffd194a6d50
char = 0x7ffd194a6d67, int = 0x7ffd194a6d2c, float = 0x7ffd194a6d3c, double = 0x7ffd194a6d58
```

```
char = 0x7ffc6b9ddc98, int = 0x7ffc6b9ddc80, float = 0x7ffc6b9ddc70, double = 0x7ffc6b9ddc50
char = 0x7ffc6b9ddc99, int = 0x7ffc6b9ddc84, float = 0x7ffc6b9ddc74, double = 0x7ffc6b9ddc58
char = 0x7ffc6b9ddc9a, int = 0x7ffc6b9ddc88, float = 0x7ffc6b9ddc78, double = 0x7ffc6b9ddc60
char = 0x7ffc6b9ddc9b, int = 0x7ffc6b9ddc8c, float = 0x7ffc6b9ddc7c, double = 0x7ffc6b9ddc68
```
