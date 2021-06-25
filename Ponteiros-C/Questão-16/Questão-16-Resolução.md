Foi utilizada a biblioteca `time.h`.

Importamos a biblioteca `#include <time.h>`, declaramos a variável `clock_t t;`, usamos o trecho de código que queremos 
verificar o tempo de execução entre `t = clock();` e `t = clock() - t;`, e imprimir usando `printf("\nTempo de execucao: %lf", ((double)t)/((CLOCKS_PER_SEC/1000)));`.

Execução do programa com o tempo de execução em [qsort](https://replit.com/@SidneyAlves1/Questao-14#main.c)

Execução do programa com o tempo de execução em [Ssort](https://replit.com/@SidneyAlves1/Questao-15#main.c)

Foram coletados dados sobre os tempos de execução que podem ser observados nas tabelas abaixo:

**qsort**

| qnt de Entradas |       Entradas      |                  Saídas                 | Tempo de Execução |
|:---------------:|:-------------------:|:---------------------------------------:|:-----------------:|
|        3        |       15 -1 0       |             -1.0 0.0 15.00              |      0.004000     |
|        5        |    33 -51 1 -5 2    |       -51.00 -5.00 1.00 2.00 33.00      |      0.006000     |
|        7        | 98 12 -5 3 -22 -1 1 | -22.00 -5.0 -1.00 1.00 3.00 12.00 98.00 |      0.004000     |

**Ssort**

| qnt de Entradas |       Entradas      |                  Saídas                 | Tempo de Execução |
|:---------------:|:-------------------:|:---------------------------------------:|:-----------------:|
|        3        |       15 -1 0       |             -1.0 0.0 15.00              |      0.003000     |
|        5        |    33 -51 1 -5 2    |       -51.00 -5.00 1.00 2.00 33.00      |      0.003000     |
|        7        | 98 12 -5 3 -22 -1 1 | -22.00 -5.0 -1.00 1.00 3.00 12.00 98.00 |      0.006000     |

**Média de tempo de execução**

|      Função      |    Média de Tempo    |
|:----------------:|:--------------------:|
|      qsort       |       0.004666       |
|      Ssort       |       0.004000       |

Comparando o tempo de execução das duas funçõe, a Ssort obteve um tempo de execução mais eficiente. Mas não podemos 
afirmar que seja a mais eficiente, a IDE utilizada ou o processamento do computador pode interfirir no tempo de execução.
