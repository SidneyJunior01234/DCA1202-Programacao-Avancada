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
