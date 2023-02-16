# Motor
## Autores
- Simona Antonova Mihaylova [(Usuario GitHub: ssimoanto)](https://github.com/ssimoanto)
- Javier Comas de Frutos [(Usuario GitHub: javixxu)](https://github.com/javixxu)
- Sara Isabel García Moral [(Usuario GitHub: sarais02)](https://github.com/sarais02)
- Miguel González Pérez [(Usuario GitHub: miggon23)](https://github.com/miggon23)
- Adrián Montero Castrillo [(Usuario GitHub: admont02)](https://github.com/admont02)
- Antonio Povedano Ortiz [(Usuario GitHub: AntonioPove)](https://github.com/AntonioPove)
- Raúl Saavedra de la Riera [(Usuario GitHub: RaulSaavedraRiera)](https://github.com/RaulSaavedraRiera)
- Elisa Todd Rodríguez [(Usuario GitHub: elisatodd)](https://github.com/elisatodd)

# DOCUMENTO DE GUÍAS DE ESTILO DE CÓDIGO 

Reglas sacadas de : https://lefticus.gitbooks.io/cpp-best-practices/content/03-Style.html

Consultar la web en caso de duda o conflicto.


## 0.- Versión y Compatibilidad

Para el desarrollo del proyecto se utilizará la versión de Visual Studio 17 2022 . Ver instalador de Visual Studio para asegurarse de que se tiene la extensión 17.X.X (Se recomienda la 17.4.4 como la más actual a fecha de esta edición del documento).


## 1- Nombrado


* Clases : comienzan con mayúscula y llevan mayúscula en cada palabra nueva. Si hubiese tílde se omite. Esto se llama Pascal case: (InputIterator, PascalCase, HelloWorld...)

 MyClass  Jugador EnemigoAzul Obstaculo ObstaculoPlatano  etc.


* Funciones : comienzan con minúscula, pero ponemos mayúscula en el cambio de palabra. Esto se llama camel case: (myMethod, camelCase, helloWorld...)

myMethod() jump() chase() followPlayer() addHighScore()


* Variables : (AQUÍ SE CAMBIA RESPECTO A LA WEB PARA DISTINGUIR MEJOR ENTRE FUNCIONES Y VARIABLES)

Se escribirán todas en minúscula, separándo con guión bajo el cambio de palabra. Esto se llama snake case: (unordered\_map, snake\_case, hello\_world...)

int high\_score; int n\_enemies; int gravity;


* Constantes : Todo en mayúscula. (Intentar que sea una sóla palabra, pero en caso de que sean más separar con \_)

const double PI=3.14159265358979323; const double NUM\_PI=...


* Macros : Todo en mayúscula, guión bajo si es necesario separar palabras.

INT\_MAX


→ En todos los casos anteriores los nombres deben ser descriptivos y precisos. Evitar redundancias.

→ n\_enemies\_left --> enemies\_left (aquí sobra decir "n" porque si la variable es un int, ya sabemos que es el nº de enemigos)

→ aux / temp --> evitar salvo casos muy concretos en los que se vea muy claro su uso.


→ Podemos nombrar variables como i, j, k, n cuando vayan a ser contadores o similar en un bucle o momento concreto. Si son variables que se van a utilizar más no se puede hacer esto.

→ Si es una palabra en inglés (o español...) y no estamos seguros de cómo se escribe, comprobarlo primero y evitar erratas.

HEIGHT (ojo con esa que la solemos escribir mal siempre)


→ NUNCA DEFINIR NADA QUE EMPIECE POR "\_" GUIÓN BAJO. (you risk colliding with names reserved for compiler and standard library implementation use)


### 1.1- Nombres de variables especiales


* Variables privadas y protected : se distinguirán de las públicas añadiendo m\_ delante: "member" data.

m\_player; m\_patatas; m\_hello\_world;

* Parámetros : llevarán delante un prefijo t\_ (se refiere a "the\_").

t\_width; t\_height; t\_hello\_world;


## 2- Clases

Tendrán la siguiente estructura:


#include <...>

#include "..."

/\*\*

doxygen-style comment (ver 4- Documentación)

\*/

class MyClass

{

public:

MyClass(int t\_data)

: m\_data(t\_data)

{

}


int getData() const

{

return m\_data;

}


protected:

...


private:

int m\_data;

};


* Inicializaremos las variables de clase con el "member initializer list", tal y como se ve en el ejemplo de arriba: usando los dos puntos después del nombre de la clase y antes de los corchetes. Esto se hará en una línea nueva entre el nombre del constructor y los corchetes.

Es decir:

MyClass(int t\_value)

{

m\_value = t\_value; --> NO

}


MyClass(int t\_value) : m\_value(t\_value) --> NO

{

}


* También inicializaremos todos los objetos de las clases, y lo haremos usando {}:

private:

int m\_value{0};

unsigned m\_value\_2{-1};

MyClass m\_referencia\_clase{nullptr};


## 3- Comentarios

- Se debe comentar usando // y no /\*\*/
- Usaremos /\*\*/ cuando, mientras programamos, queremos dejar comentada una determinada función o parte del código,

pero sólo momentaneamente.


/\*

// this function does something

int myFunc()

{

}

\*/


* /\*\*/ queda reservado para comentarios relacionados con la documentación.






## 4- Documentación

Usaremos comentarios "Doxygen-style" para documentar el código: https://doxygen.nl/manual/index.html

Es imprescindible que el comentario comience con /\*\* y acabe con \*/

Documentación de una función:

/\*\*

* @brief Descripción corta de la función

\*

* Descripción detallada de la función, su propósito y cualquier
* información relevante.

\*

* @param[in] param\_name Description of the first parameter
* @param[in] param\_name Description of the second parameter
* @return Description of the return value

\*/

return\_type function\_name(param\_type param\_name, param\_type param\_name)

: m\_var(param\_name), ...

{

// ...

}


Documentación de una clase:

/\*\*

* A test class. A more elaborate class description.

\*/

class Class\_Test

{ ...


Documentación de una variable:

int var; /\*!< Detailed description after the member \*/


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


#pragma once

#ifndef \_\_CAMARA\_H\_\_

#define \_\_CAMARA\_H\_\_


… //Código del archivo de encabezado


#endif


* Siempre usar "---" para incluir archivos propios (como siempre hemos hecho).
* Usar espacios de nombres:


namespace my\_namespace {

int x = 5;

int y = 10;

}


int main() {

std::cout << my\_namespace::x << std::endl;

std::cout << my\_namespace::y << std::endl;

return 0;

}


* Cuando declaremos variables que inicializamos mediante el retorno de llamadas a métodos de las librerías, usaremos AUTO para evitar cambiar el tipo. Si no usamos auto, comprobar qué devuelve exactamente ese método para evitar confusión (size\_t en lugar de int, para llamadas a vector.size()). Es igualmente aconsejable hacerlo para nuestros propios métodos.


* SIEMPRE poner {} para los bucles. Aunque sea un for de una línea, no cuesta nada poner los corchetes y servirá de ayuda más adelante además de ayudar a la legibilidad del código.


* Si una línea se está alargando mucho (eg: un if con varias condiciones anidadas) inserta un salto de línea en una posición adecuada.


* NUNCA hacer overload del operador "," (la coma).


* Antes de sobrecargar un operador, comprobar si es realmente necesario y si la sintaxis es clara.


* No escribir líneas demasiado largas: Tratar de no superar los 80-100 caracteres

(120 extraordinariamente).


### 6.1 Restricciones peligrosas (Resumen)


→ NUNCA DEFINIR NADA QUE EMPIECE POR "\_" GUIÓN BAJO. (you risk colliding with names reserved for compiler and standard library implementation use)


→NUNCA hacer overload del operador "," (la coma).


























Ejemplo de buen código:

/\*\*

* @brief foo() escribe i por consola y devuelve i+1

\*

* Lo hace usando la función cout del espacio de nombres std,
* y devolviendo el número insertado por parámetro + 1

\*

* @param[in] t\_i número que se muestra
* @return t\_i aumentado en 1

\*/

int foo(int t\_i)

{

std::cout(i);

return i + 1;

}
