# Programação em C++

## 1.Introdução

Iremos utilizar a linguagem C++, que é semelhante a linguagem C e aplicaremos os conceitos de 
Programação Orientada a Objetos (**POO**).

**Exemplo em C**

```cpp
#include <stdio.h>

int main()
{
    printf("Programa em C\n");
    return 0;
}
```

**Exemplo em C++**

```cpp
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
```cpp
void func1(void);
```

**func1.cpp**
```cpp
#include "func1.hpp"
#include <iostream>

void func1(void)
{
  std::cout << "Funcao 1\n";
}
```

**func2.hpp**
```cpp
void func2(void);
```

**func2.cpp**
```cpp
#include "func2.hpp"
#include <iostream>

void func2(void)
{
  std::cout << "Funcao 2\n";
}
```

**main.cpp**
```cpp
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

```cpp
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

```cpp
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
```cpp
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

```cpp
tipo classe :: nome(parametros)
{
    //trecho de código
}
```

**ponto2D.cpp**
```cpp
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

```cpp
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
```cpp
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
```cpp
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

```cpp
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
```cpp
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
```cpp
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

```cpp
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

```cpp
void alterar_valor_5(int x)
{
  std :: cout << "x(entrada) = " << x << std :: endl;
  x = 5;
  std :: cout << "x(saida) = " << x << std :: endl;
}
```

**Passagem de parâmetro por referência**

```cpp
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

```cpp
Ponto2D :: Ponto2D(const Ponto2D &p2d)
{
    x = p2d.x;
    y = p2d.y;
    std :: cout << "construtor de copia" << std :: endl;
}
```

## 7.Sobrecarga de Funções e Métodos

A aplicação dessa funcionalidade nos dá uma forma que os métodos e funções tenham mais de uma forma específica de uso.
Temos como exemplo uma função que imprime uma `string`, mas eu gostaria de imprimir um `int` usando a mesma função. Com a sobrecarga
eu posso fazer isso.

**Exemplo**

```cpp
//imprimir usando string
void imprimir(char *c)
{
    std :: cout << "string: " << c << std :: endl;
}
//imprimir usando string
void imprimir(int i)
{
    std :: cout << "int: " << i << std :: endl;
}
```

Acontece o mesmo ao adicionar parâmetros nos construtores, temos como exemplo os construtores de Ponto2D e nos métodos
X e Y.

**ponto2D.h**
```cpp
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
```cpp
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

## 8.Funções Amigas

Essas funções são externas a classe, têm acesso aos atributos privados e protegidos da classe.

Temos como exemplo o operador binário `*` que nos permite multiplicar valores, mas par aum Vetor2D temos:

```cpp
class Vetor2D
{
    private:
        float x;
        float y;
    public:
        Vetor2D(float _x, float _y)
        {
            x = _x;
            y = _y;
        }
        Vetor2D operator* (float a)
        {
            Vetor2D ret;
            ret.x = x*a;
            ret.y = y*a;
            return ret;
        }
};
```

Utilizando esse método.

```cpp
Vetor2D v1(2,6), v2;
v2 = v1 * 4;
```

Esse exemplo é válido, mas e se...

```cpp
Vetor2D v1(2,6), v2;
v2 = 4 * v1;
```

Esse exemplo dá errado, por isso usamos funções amigas para suprir a duncionalidade que precisamos.
Para isso usamos `friend` antes da definição do método e adicionamos um parâmetro objeto após o valor escalar por assim dizer.

```cpp
class Vetor2D
{
    private:
        float x;
        float y;
    public:
        Vetor2D(float _x, float _y)
        {
            x = _x;
            y = _y;
        }
        //adicionado friend e Vetor2D
        friend Vetor2D operator* (float a, Vetor2D vet)
        {
            Vetor2D ret;
            ret.x = vet.x*a;
            ret.y = vet.y*a;
            return ret;
        }
};
```

Agora podemos usar

```cpp
Vetor2D v1(2,6), v2;
v2 = 4 * v1;
```

Ou podemos usar

```cpp
Vetor2D v1(2,6), v2;
v2 = operator(4,v1);
```

## 9.Herança Simples

Temos como herança, algo herdado de um outro. Compartilhando uma estrutura em comum, Dizemos então que há
uma relação de herança quando por exemplo `A É UM` com um objeto da classe `B`.

Usamos a heranã da seguinte maneira: ao criar a classe derivada escrevemos em sua declaração.

`class nome_classe_derivada : public classe_base {};`

B é a subclasse ou classe derivada e A é a superclasse ou classe base.

**Exemplo**

**equipamento.h**
```cpp
class Equipamento
{
    char nome[100];
    char fabricante[100];
    float preco;
    public:
        void setNome(const char *_nome);
        void setFabricante(const char *_fabricante);
        void setPreco(float _preco);
        char* getNome(void);
        char* getFabricante(void);
        float getPreco(void);
};
```
**equipamento.cpp**
```cpp
#include "equipamento.h"

void Equipamento::setNome(const char *_nome)
{
    nome = _nome;
}
void Equipamento::setFabricante(const char *_fabricante)
{
    fabricante = _fabricante;
}
void Equipamento::setPreco(float _preco)
{
    preco = _preco;
}
char* Equipamento::getNome(void)
{
    return nome;
}
char* Equipamento::getFabricante(void)
{
    return fabricante;
}
float Equipamento::getPreco(void)
{
    return preco;
}
```

**motor.h**
```cpp
#include "equipamento.h"
class Motor : public Equipamento
{
    float potencia;
    float velocidade;
    public:
        void setPotencia(float _potencia);
        void setVelocidade(float _velocidade);
        float getPotencia(void);
        float getVelocidade(void);
};
```
**motor.cpp**
```cpp
void setPotencia(float _potencia)
{
    potencia = _potencia;
}
void setVelocidade(float _velocidade)
{
    velocidade = _velocidade;
}
float getPotencia(void)
{
    return potencia;
}
float getVelocidade(void)
{
    return velocidade;
}
```

**main.cpp**
```cpp
int main()
{
    Motor m;
    m.setFabricante("Chevrolet");
    m.setNome("Corsa");
    m.setPreco(21890.00);
    m.setPotencia(1216);
    m.setVelocidade(280);
    std::cout << m.getFabricante() << '\n'
              << m.getnome() << '\n'
              << m.getFabricante() << '\n'
              << m.getpreco() << '\n'
              << m.getpotencia() << '\n'
              << m.getvelocidade() << '\n'
    return 0;
}
```
## 10.Efeitos da Herança

```cpp
class nome_classe
{
    private:
        char nome[100];
    protected:
        float preco:
};
```

Os atributos `private` são somente acessíveis a propria classe e a classes amigas.
Os atributos `protected` são acessíveis também por herdeiras e amigas.

Mas o que é o `public` em ```cpp class classe_herdeira :: public classe_herdada```?

o `public` representa a forma que a classe herdeira irá herdar de sua super classe.

![image](https://user-images.githubusercontent.com/50020838/126913698-e6b8a18e-4bba-430e-9aa4-01ebf40dd537.png)

Todos os métodos criados na super classe são herdados pela subclasse, menos os construtores e destrutores. Ao criar o objeto, primeiro é criado 
o construtor da super classe e depois é criado o da sub classe. Logo após ao finalizar o destrutor da sub classe é chamado e por fim o da super classe.

Caso queira usar construtorres passando valores, podemos fazer isso.

**Exemplo**

**equipamento.h**
```cpp
class Equipamento
{
    char nome[100];
    char fabricante[100];
    float preco;
    public:
        Equipamento(char *nome, char *fabricante, float preco);
        void setNome(const char *_nome);
        void setFabricante(const char *_fabricante);
        void setPreco(float _preco);
        char* getNome(void);
        char* getFabricante(void);
        float getPreco(void);
};
```
**equipamento.cpp**
```cpp
#include "equipamento.h"

Equipamento::Equipamento(char *nome, char *fabricante, float preco)
{
    this -> nome = nome;
    this -> fabricante = fabricante;
    this -> preco = preco;
}
void Equipamento::setNome(const char *_nome)
{
    nome = _nome;
}
void Equipamento::setFabricante(const char *_fabricante)
{
    fabricante = _fabricante;
}
void Equipamento::setPreco(float _preco)
{
    preco = _preco;
}
char* Equipamento::getNome(void)
{
    return nome;
}
char* Equipamento::getFabricante(void)
{
    return fabricante;
}
float Equipamento::getPreco(void)
{
    return preco;
}
```

**motor.h**
```cpp
#include "equipamento.h"
class Motor : public Equipamento
{
    float potencia;
    float velocidade;
    public:
        void setPotencia(float _potencia);
        void setVelocidade(float _velocidade);
        float getPotencia(void);
        float getVelocidade(void);
};
```
**motor.cpp**
```cpp
Motor::Motor(float potencia, float velocidade, char *nome, char *fabricante, float preco) : Equipamento(nome,fabricante,preco)
{
    this -> potencia = potencia;
    this -> velocidade = velocidade;
}
void setPotencia(float _potencia)
{
    potencia = _potencia;
}
void setVelocidade(float _velocidade)
{
    velocidade = _velocidade;
}
float getPotencia(void)
{
    return potencia;
}
float getVelocidade(void)
{
    return velocidade;
}
```

**main.cpp**
```cpp
int main()
{
    Motor m(1216,280,"Corsa","Chevrolet",21890.00);
    //m.setFabricante("Chevrolet");
    //m.setNome("Corsa");
    //m.setPreco(21890.00);
    //m.setPotencia(1216);
    //m.setVelocidade(280);
    std::cout << m.getFabricante() << '\n'
              << m.getnome() << '\n'
              << m.getFabricante() << '\n'
              << m.getpreco() << '\n'
              << m.getpotencia() << '\n'
              << m.getvelocidade() << '\n'
    return 0;
}
```

O que pode dar errado?

```cpp
class Base
{
    protected:
        int a, b;
};
class Derivada : public Base
{
    int c;
};

int main()
{
    Base b;
    Derivada d;
    b = d;
    d = b; // ERRO: d possui partes indefinidas
}
```

Como Derivada herda de Base, há componentes de Base em Derivada, mas não o contrário. Para corrigir isso, basta criar uma sobrecarga no `operator=`.

```cpp
class Base
{
    protected:
        int a, b;
};
class Derivada : public Base
{
    int c;
    public:
        void operator=(Base &x)
        {
            a = x.getA();
            b = x.getB();
            c = ;
        }
};

int main()
{
    Base b;
    Derivada d;
    b = d;
    d = b; // Agora sim...
}
```
