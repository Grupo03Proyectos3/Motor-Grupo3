# Motor
## Autores
- Javier Comas de Frutos [(Usuario GitHub: javixxu)](https://github.com/javixxu)
- Elisa Todd Rodríguez [(Usuario GitHub: elisatodd)](https://github.com/elisatodd)
- Miguel González Pérez [(Usuario GitHub: miggon23)](https://github.com/miggon23)
- Raúl Saavedra de la Riera [(Usuario GitHub: RaulSaavedraRiera)](https://github.com/RaulSaavedraRiera)
- Sara Isabel García Moral [(Usuario GitHub: sarais02)](https://github.com/sarais02)
- Antonio Povedano Ortiz [(Usuario GitHub: AntonioPove)](https://github.com/AntonioPove)
- Adrián Montero Castrillo [(Usuario GitHub: admont02)](https://github.com/admont02)
- Simona Antonova Mihaylova [(Usuario GitHub: ssimoanto)](https://github.com/ssimoanto)


# PROBLEMAS CONOCIDOS
## Memory Leaks
Por el uso de la librería CEGUI, obtenemos una serie de memory leaks que nos es imposible eliminar. 
Estos memory leaks consisten en:
- 2 leaks por la inicialización de FlamingoDefaultUI.scheme, para obtener los elementos que crearemos de UI. Aun eliminando su contenido en el método eraseContext() del UISystem, éste sigue provocando fugas de memoria.
- 2 leaks por cada vez que se añade una imagen como propiedad a un elemento de UI. La imagen es añadida usando addFromImageFile() del ImageManager de CEGUI. Cuando hacemos su destrucción en el eraseContext() del UISystem, no borra sus elementos correctamente, provocando 2 fugas por cada imagen que ha sido añadida.

# DOCUMENTO DE ARQUITECTURA DE LA APLICACIÓN
Disponible en el siguiente [enlace](https://docs.google.com/document/d/1QyVL74zdQPN7MQIYyo73qdJAATZfBXgCr_v5fXanyeg/edit?usp=sharing).

# DOCUMENTO DE GUÍAS DE ESTILO DE CÓDIGO 

Reglas sacadas de : https://lefticus.gitbooks.io/cpp-best-practices/content/03-Style.html

Consultar la web en caso de duda o conflicto.


## 0.- Versión y Compatibilidad

Para el desarrollo del proyecto se utilizará la versión de Visual Studio 17 2022 . Ver instalador de Visual Studio para asegurarse de que se tiene la extensión 17.X.X (Se recomienda la 17.4.4 como la más actual a fecha de esta edición del documento).


## 1- Nombrado


* Clases : comienzan con mayúscula y llevan mayúscula en cada palabra nueva. Si hubiese tílde se omite. Esto se llama Pascal case: (InputIterator, PascalCase, HelloWorld...)

```
 MyClass  Jugador EnemigoAzul Obstaculo ObstaculoPlatano etc..
```

* Funciones : comienzan con minúscula, pero ponemos mayúscula en el cambio de palabra. Esto se llama camel case: (myMethod, camelCase, helloWorld...)
```
myMethod() jump() chase() followPlayer() addHighScore()
```

* Variables : (AQUÍ SE CAMBIA RESPECTO A LA WEB PARA DISTINGUIR MEJOR ENTRE FUNCIONES Y VARIABLES)

Se escribirán todas en minúscula, separándo con guión bajo el cambio de palabra. Esto se llama snake case: (unordered_map, snake_case, hello_world...)
```
int high_score; int n_enemies; int gravity;
```

* Constantes : Todo en mayúscula. (Intentar que sea una sóla palabra, pero en caso de que sean más separar con \_)
```
const double PI=3.14159265358979323; const double NUM\_PI=...
```

* Macros : Todo en mayúscula, guión bajo si es necesario separar palabras.
```
INT_MAX
```

→ En todos los casos anteriores los nombres deben ser descriptivos y precisos. Evitar redundancias.

→ n_enemies_left --> enemies_left (aquí sobra decir "n" porque si la variable es un int, ya sabemos que es el nº de enemigos)

→ aux / temp --> evitar salvo casos muy concretos en los que se vea muy claro su uso.


→ Podemos nombrar variables como i, j, k, n cuando vayan a ser contadores o similar en un bucle o momento concreto. Si son variables que se van a utilizar más no se puede hacer esto.

→ Si es una palabra en inglés (o español...) y no estamos seguros de cómo se escribe, comprobarlo primero y evitar erratas.

HEIGHT (ojo con esa que la solemos escribir mal siempre)

→ NUNCA DEFINIR NADA QUE EMPIECE POR "_" GUIÓN BAJO. (you risk colliding with names reserved for compiler and standard library implementation use)

### 1.1- Nombres de variables especiales

* Variables privadas y protected : se distinguirán de las públicas añadiendo m\_ delante: "member" data.
```
m_player; m_patatas; m_hello_world;
```
* Parámetros : llevarán delante un prefijo t_ (se refiere a "the_").
```
t_width; t_height; t_hello_world;
```

## 2- Clases

Tendrán la siguiente estructura:

```
#include <...>
#include "..."

/**

doxygen-style comment (ver 4- Documentación)

*/

class MyClass
{

public:

MyClass(int t_data)
: m_data(t_data)
{

}

int getData() const
{
  return m_data;
}

protected:

...

private:

int m_data;

};
```

* Inicializaremos las variables de clase con el "member initializer list", tal y como se ve en el ejemplo de arriba: usando los dos puntos después del nombre de la clase y antes de los corchetes. Esto se hará en una línea nueva entre el nombre del constructor y los corchetes.

Es decir:

```
MyClass(int t_value)
{
  m_value = t_value; --> NO
}

MyClass(int t_value) : m_value(t_value) --> NO
{

}
```

* También inicializaremos todos los objetos de las clases, y lo haremos usando {}:
```
private:

int m_value{0};

unsigned m_value_2{-1};

MyClass m_referencia_clase{nullptr};
```

## 3- Comentarios

- Se debe comentar usando // y no /\*\*/
- Usaremos /\*\*/ cuando, mientras programamos, queremos dejar comentada una determinada función o parte del código, pero sólo momentaneamente.

```
/*
// this function does something
int myFunc()
{

}
*/
```


* /\*\*/ queda reservado para comentarios relacionados con la documentación.

## 4- Documentación

Usaremos comentarios "Doxygen-style" para documentar el código: https://doxygen.nl/manual/index.html

Es imprescindible que el comentario comience con /\*\* y acabe con \*/

Documentación de una función:
```

/**
* @brief Descripción corta de la función
*
* Descripción detallada de la función, su propósito y cualquier
* información relevante.
*
* @param[in] param\_name Description of the first parameter
* @param[in] param\_name Description of the second parameter
* @return Description of the return value
*/

return_type function_name(param_type param_name, param_type param_name)
: m_var(param_name), ...
{
// ...
}

```
Documentación de una clase:
```
/**
* A test class. A more elaborate class description.
*/

class Class_Test
{ 
  ...
}
```
Documentación de una variable:
```
int var; /*!< Detailed description after the member*/
```

## 5- Indentación y espaciado

Para la indentación, espaciado, sangría, nuevas líneas, y aspectos similares del formato del código, se seguirán las restricciones impuestas en el archivo ‘.clang-format’, situado en la raíz del proyecto. Este archivo permitirá formatear el código usando el atajo de teclado ‘Ctrl + K’ + ‘Ctrl + D’.

Para asegurar su correcto funcionamiento iremos Herramientas → Opciones → Editor de texto → C/C++ → Estilo de código → Formato → Y marcar la casilla “Habilita la compatibilidad con ClangFormat”.

Para consultar el significado de los diferentes aspectos definidos, ir a la documentación de clang-format: https://clang.llvm.org/docs/ClangFormatStyleOptions.html


## 6- Otros

* Uso de nullptr en lugar de 0 o NULL.
* NUNCA poner un using en un .h!! Causa que se implemente dicho namespace en todos los ficheros que incluyan dicho .h
* Siempre poner #pragma-once al principio de un .h
* Además del pragma-once, usaremos IFNDEF ENDIF:

Las definiciones de este tipo comienzan y cierran con doble guión bajo, usa el nombre del archivo de encabezado, sustituyendo la terminación .h por \_H (por convenio), ver ejemplo para un archivo Camara.h:

```
#pragma once

#ifndef __CAMARA_H__
#define __CAMARA_H__

… //Código del archivo de encabezado


#endif
```

* Siempre usar "---" para incluir archivos propios (como siempre hemos hecho).
* Usar espacios de nombres:

```
namespace my_namespace {
  int x = 5;
  int y = 10;
}


int main() {
  std::cout << my\_namespace::x << std::endl;

  std::cout << my\_namespace::y << std::endl;

  return 0;
  
}
```

* Cuando declaremos variables que inicializamos mediante el retorno de llamadas a métodos de las librerías, usaremos AUTO para evitar cambiar el tipo. Si no usamos auto, comprobar qué devuelve exactamente ese método para evitar confusión (size\_t en lugar de int, para llamadas a vector.size()). Es igualmente aconsejable hacerlo para nuestros propios métodos.


* SIEMPRE poner {} para los bucles. Aunque sea un for de una línea, no cuesta nada poner los corchetes y servirá de ayuda más adelante además de ayudar a la legibilidad del código.


* Si una línea se está alargando mucho (eg: un if con varias condiciones anidadas) inserta un salto de línea en una posición adecuada.


* NUNCA hacer overload del operador "," (la coma).


* Antes de sobrecargar un operador, comprobar si es realmente necesario y si la sintaxis es clara.


* No escribir líneas demasiado largas: Tratar de no superar los 80-100 caracteres (120 extraordinariamente).


### 6.1 Restricciones peligrosas (Resumen)

→ NUNCA DEFINIR NADA QUE EMPIECE POR "_" GUIÓN BAJO. (you risk colliding with names reserved for compiler and standard library implementation use)

→NUNCA hacer overload del operador "," (la coma).

Ejemplo de buen código:
```
/**
* @brief foo() escribe i por consola y devuelve i+1
*
* Lo hace usando la función cout del espacio de nombres std,
* y devolviendo el número insertado por parámetro + 1
*
* @param[in] t\_i número que se muestra
* @return t\_i aumentado en 1
*/

int foo(int t_i)
{
 std::cout(i);
 return i + 1;
}
```
