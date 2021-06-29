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
