# Programação em C++

## 1.Introdução

Iremos utilizar a linguagem C++, que é semelhante a linguagem C e aplicaremos os conceitos de 
Programação Orientada a Objetos (**POO**).

**Exemplo em C**

```
#include <stdio.h>

int main()
{
    printf("Programa em C\n");
    return 0;
}
```

**Exemplo em C++**

```
#include <iostream>

int main()
{
    std::cout << "Programa em C\n";
    return 0;
}
```

Os arquivos dos programas terão extensão **.cpp** que serão compilados e os de extensão **.hpp** que são os arquivos de header.

**Exemplo de como usaremos isso nas próximas aulas**

**func1.hpp**
```
void func1(void);
```

**func1.cpp**
```
#include "func1.hpp"
#include <iostream>

void func1(void)
{
  std::cout << "Funcao 1\n";
}
```

**func2.hpp**
```
void func2(void);
```

**func2.cpp**
```
#include "func2.hpp"
#include <iostream>

void func2(void)
{
  std::cout << "Funcao 2\n";
}
```

**main.cpp**
```
#include <iostream> 
#include "func1.hpp"
#include "func2.hpp"

int main()
{
    func1();
    func2();
    return 0;
}
```

## 2.Definição de uma Classe

O que é **classe** ?

Classe é um grupo formado por objetos que compartilham características em comum.

O que é **objeto**?

É a instância de uma classe.

Como funciona uma classe em C++?

As classes possuem propriedades e funcionalidades.

**Exemplo de uma classe:**

```
class nome_da_classe
{
    private:
        //atributo 1
        //atributo 2
        //método 1
    public:
        //atributo 3
        //atributo 4
        //método 2
};
```

Para definirmos a nossa classe usamos a palavra/comando reservado `class` e em seguida o `nome_da_classe` com
`{};`.

Entre as chaves temos os atributos e métodos, que são basicamente variáves e funções na programação estruturada.
Sendo que agora são categorizadas como:

`private` - apenas membros que herdam da classe e ela mesma podem utilizar, caso não informe os atributos e métodos são privado por padrão.

`public` - a classe atual e outras podem utilizar.

`protected` - classes derivadas também terão seus membros protegidos.

**[Exemplo](https://replit.com/@SidneyAlves1/Primeira-Classe#main.cpp):**

```
class Ponto2D
{
    private:
        float x, y;
    public:
        void X(float _x)
        {
            x = _x;
        }
        float X(void)
        {
            return x;
        }
        void Y(float _y)
        {
            y = _y;
        }
        float Y(void)
        {
            return y;
        }
};
#include <iostream>

int main()
{
    Ponto2D p;
    p.X(2);
    p.Y(2);
    std::cout << "(x,y) = (" << p.X << ',' << p.Y << ")\n"; 
    return 0;
}
```


Para acessar os atributos e métodos das classes, usamos o `.`(ponto).

**Getter e Setter** São responsáveis por pegar ou adicionar valores aos atributos. Esses métodos devem ser públicos para que outras classes
possam adicionar ou recuperar valores. Além disso esses métodos são uma forma de proteção dos atributos.

Chamamos essa proteção de **Encapsulamento**, um dos pilares da **POO**. 

## 3.Programando em Módulos

Para modularizar, devemos ter os arquivos `.cpp` e `.h ou .hpp`. Usando o exemplo anterior:

**ponto2D.h**
```
#ifndef PONTO2D_H
#define PONTO2D_H

class Ponto2D
{
    private:
        float x, y;
    public:
        void X(float _x);
        float X(void);
        void Y(float _y);
        float Y(void);
};

#endif
```

Para definir os métodos da classe, usamos o operador de escopo `::` da seguinte maneira.

`tipo` de retorno do método, `classe` ao qual pertence, `::` operador de escopo, `nome` da função e `parâmetros` da função.

```
tipo classe :: nome(parametros)
{
    //trecho de código
}
```

**ponto2D.cpp**
```
#include "ponto2D.h"

void Ponto2D :: X(float _x)
{
    x = _x;
}
float Ponto2D :: X(void)
{
    return x;
}
void Ponto2D :: Y(float _y)
{
    y = _y;
}
float Ponto2D :: Y(void)
{
    return y;
}
```

**main.cpp**

```
#include <iostream>
#include "ponto2D.h"

int main()
{
    Ponto2D p;
    p.X(2);
    p.Y(2);
    std::cout << "(x,y) = (" << p.X << ',' << p.Y << ")\n"; 
    return 0;
}
```

As diretivas `#ifndef`,`#define` e `#endif` auxiliam na compilação do programa. Ao compilar é criado algo similar a um simbolo referente ao programa,
`#ifndef` - se o simbolo não existir, `#define` - o simbolo é criado e `#endif` - finaliza a condição. Sendo que se o simbolo já existir, o programa não precisa compilar
novamente.

## 4.Construtores e Destrutores

Os métodos construtores são chamados automaticamentes para inicializar o objeto quando criados.

Criando um método construtor.

**ponto2D.h**
```
#ifndef PONTO2D_H
#define PONTO2D_H

class Ponto2D
{
    private:
        float x, y;
    public:
        //metodo construtor
        Ponto2D();
        void X(float _x);
        float X(void);
        void Y(float _y);
        float Y(void);
};

#endif
```

Implementando/Inicializando o método construtor.

**ponto2D.cpp**
```
#include "ponto2D.h"

//construtor padrao
Ponto2D :: Ponto2D(){}
//construtor inicializando com os pontos x e y em 0
Ponto2D :: Ponto2D()
{
    x = 0;
    y = 0;
}
//construtor inicializando com os pontos x e y com entradas escolhidas pelo programador
Ponto2D :: Ponto2D(float _x, float _y)
{
    x = _x;
    y = _y;
}
void Ponto2D :: X(float _x)
{
    x = _x;
}
float Ponto2D :: X(void)
{
    return x;
}
void Ponto2D :: Y(float _y)
{
    y = _y;
}
float Ponto2D :: Y(void)
{
    return y;
}
```

**main.cpp**

```
#include <iostream>
#include "ponto2D.h"

int main()
{
    Ponto2D p(2,2);
    std::cout << "(x,y) = (" << p.X << ',' << p.Y << ")\n";
    p.X(2);
    p.Y(2);
    std::cout << "(x,y) = (" << p.X << ',' << p.Y << ")\n"; 
    return 0;
}
```

Ao finalizar o uso do objeto um método é usado, o método destrutor.

**ponto2D.h**
```
#ifndef PONTO2D_H
#define PONTO2D_H

class Ponto2D
{
    private:
        float x, y;
    public:
        //metodo construtor
        Ponto2D();
        //metodo destrutor
        ~Ponto2D();
        void X(float _x);
        float X(void);
        void Y(float _y);
        float Y(void);
};

#endif
```

**ponto2D.cpp**
```
#include "ponto2D.h"

//construtor padrao
Ponto2D :: Ponto2D(){}
//construtor inicializando com os pontos x e y em 0
Ponto2D :: Ponto2D()
{
    x = 0;
    y = 0;
}
//construtor inicializando com os pontos x e y com entradas escolhidas pelo programador
//caso so passe o valor de x, y recebe 0
Ponto2D :: Ponto2D(float _x, float _y = 0)
{
    x = _x;
    y = _y;
}
Ponto2D :: ~Ponto2D()
{
    std :: cout << "Destrutor da classe." << endl;
}
void Ponto2D :: X(float _x)
{
    x = _x;
}
float Ponto2D :: X(void)
{
    return x;
}
void Ponto2D :: Y(float _y)
{
    y = _y;
}
float Ponto2D :: Y(void)
{
    return y;
}
```

**main.cpp**

```
#include <iostream>
#include "ponto2D.h"

int main()
{
    Ponto2D p(2,2);
    std::cout << "(x,y) = (" << p.X << ',' << p.Y << ")\n";
    p.X(2);
    p.Y(2);
    std::cout << "(x,y) = (" << p.X << ',' << p.Y << ")\n"; 
    return 0;
}
```

## 5.Uso de Referências

Ao utilizar os parâmetros de uma função, estamos utilizando os valores por cópia da variável que os armazena.
A passagem de parâmetro por referência, utiliza o endereço da variável passada, alterando assim o valor em determinado
endereço da memória.

Para isso usamos `&` antes do nome do parâmetro.

**Passagem de parâmetro por valor**

```
void alterar_valor_5(int x)
{
  std :: cout << "x(entrada) = " << x << std :: endl;
  x = 5;
  std :: cout << "x(saida) = " << x << std :: endl;
}
```

**Passagem de parâmetro por referência**

```
void alterar_valor_7(int &x)
{
  std :: cout << "x(entrada) = " << x << std :: endl;
  x = 7;
  std :: cout << "x(saida) = " << x << std :: endl;
}
```

## 6.Construtor de Cópia

Uma vez que você imprime uma informação ao criar um construtor e/ou um destrutor, pode ser observado nas saídas
a quantidade de vezes que os objetos foram utilizados.
Algo bastante interessante é quando é criada uma função e um objeto é passado como parâmetro, ao observar as saídas, pode se notar
que há um destrutor a mais. Esse destrutor pertence ao parâmetro, lembrando que a passagem de parâmetro é feota por valor.

Com isso podemos utilizar um construtor de cópia para nos auxiliar, onde ele é escrito dessa forma:

`tipo_retorno :: nome_classe(const classe &nome)`

**Exemplo**

```
Ponto2D :: Ponto2D(const Ponto2D &p2d)
{
    x = p2d.x;
    y = p2d.y;
    std :: cout << "construtor de copia" << std :: endl;
}
```
