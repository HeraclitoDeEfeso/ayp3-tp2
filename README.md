![UNTREF](http://untref.edu.ar/assets/img/logo_mobile.png)

# Ingeniería en Computación

## Algoritmos y Programación 3

### Árboles Binarios de Búsqueda

#### Grupo
  * Monti Matías - matiasmonti@hotmail.com
  * Araneda Alejandro - eloscurodeefeso@gmail.com

Trabajo Práctico entregado el:  
DIA de MES, HORA Hs.  
1ro Cuatrimestre de 2019

#### Docentes:
  * Aciti, Claudio Gustavo
  * Rodríguez, Martín Joel 

## Enunciado

> TP final parte 1: árboles BST (Binary Search Tree)
> ---
> Implemente un árbol BST balanceado en C. El nodo del árbol debería tener solamente valor y referencias a sus dos hijos. Investigue la teoría relacionada. Funciones para:
>  - Insertar elemento, eliminar elemento, recorrer árbol (pre-order, in-order, post-order) y búsqueda.
>  - Menú para las operaciones del árbol.
>
> *Observaciones:* El trabajo es grupal y se solicita utilizar `git`. Los commits deben ser pequeños y no uno solo con todo el trabajo. No son necesarios tests unitarios de cada función pero si incluir un ejemplo que pruebe todas las funcionalidades. Este trabajo no requiere informe. Se considera buena práctica tener el código comentado.

## Indice General
1. [Introducción](#1-introducción)
2. [Recursos utilizados](#2-recursos-utilizados)
3. [Detalles de implementación](#3-detalles-de-implementación)
   1. [Diagrama de clases](#3i-diagrama-de-clases)
4. [Conclusiones](#4-conclusiones)

[Referencias](#referencias)

## 1. Introducción

Un árbol AVL, denominado así por el nombre de sus creadores<a name="cita-1" href="#ref-1"><sup>[1]</sup></a>, es un tipo de árbol binario balanceado cuyas operaciones de búsqueda, inserción y borrado tienen complejidad logarítmica.

De acuerdo a la descripción de Knuth<a name="cita-2" href="#ref-2"><sup>[2]</sup></a>, a cada nodo o subárbol le corresponde una propiedad llamada factor de equilibrio o balance equivalente a la diferencia de altura entre el subárbol con las claves menores y el subárbol con las claves mayores. Mientras su valor absoluto sea menor o igual a la unidad, el árbol se considera AVL.

Como las operaciones de inserción o eliminación pueden modificar el factor de equilibrio y romper las condiciones del árbol AVL, es necesario realizar en los subárboles cuyo factor de equilibrio supere en valor absoluto a la unidad unos intercambios en las aristas del subárbol que resulten en cambio o "rotación" de la raiz por el nodo o subárbol a izquierda o a derecha.

Todas estas mejoras con respecto a los árboles de búsqueda sin balancear tienen por consecuencia que el árbol mantenga su altura, y por lo tanto el peor caso de búsqueda, entre el logaritmo en base dos de la cantidad claves y una vez y media dicho logaritmo. 

## 2. Recursos utilizados

Para nuestro desarrollo hemos utilizida el Entorno de Desarrollo Integrado (IDE) Code::Blocks<a name="cita-3" href="#ref-3"><sup>[3]</sup></a>
para el sistema operativo Windows y con un compilador portado del GCC de GNU aportado por el proyecto de entorno de desarrollo MinGW<a name="cita-4" href="#ref-4"><sup>[4]</sup></a>. 

En cuanto al lenguage C propiamente, hemos utilizado sólo las características y sintaxis del ANSI C89/ ISO C90 adhiriendo en lo posible al estilo de codificación del kernel de Linux<a name="cita-5" href="#ref-5"><sup>[5]</sup></a> 
y su guía para la documentación<a name="cita-6" href="#ref-6"><sup>[6]</sup></a>. 

## 3. Detalles de implementación

### 3.i. Diagrama de clases

![Diagrama de Clases](http://www.plantuml.com/plantuml/proxy?cache=no&src=https://raw.githubusercontent.com/HeraclitoDeEfeso/ayp3-tp2/master/diagrama.puml)

TODO: guía para compilar y ejecutar la aplicación. Guía para compilar y ejecutar las pruebas. 
TODO: por cada archivo "header" detallar los tipos definidos y la interfaz. Por cada "source" hacer un resumen de la implementación sólo con detalles relevantes de código.

## 4. Conclusiones

TODO: Crítica sobre las herramientas utilizadad. Detallar particularidades de la implementación del Arbol B+ en C (posibilidad de comparación con nuestra implementación en python)

## Referencias

<a name="ref-1" href="#cita-1"><sup>[1]</sup></a> Adelson-Velsky, Georgy; Landis, Evgenii (1962). "An algorithm for the organization of information". Proceedings of the USSR Academy of Sciences (in Russian). 146: 263–266

<a name="ref-2" href="#cita-2"><sup>[2]</sup></a> Knuth, Donald E. (2000). Sorting and searching (2. ed., 6. printing, newly updated and rev. ed.). Boston [u.a.]: Addison-Wesley. pp. 458–481

<a name="ref-3" href="#cita-3"><sup>[3]</sup></a> "The open source, cross platform, free C, C++ and Fortran IDE", recuperado de www.codeblocks.org

<a name="ref-4" href="#cita-4"><sup>[4]</sup></a> "Minimalist GNU for Windows", recuperado de www.mingw.org

<a name="ref-5" href="#cita-5"><sup>[5]</sup></a> "Linux kernel coding style", recuperado de http://www.kernel.org/doc/html/v4.10/process/coding-style.html

<a name="ref-6" href="#cita-6"><sup>[6]</sup></a> "Writing kernel-doc comments", recuperado de http://www.kernel.org/doc/html/v4.10/doc-guide/kernel-doc.html