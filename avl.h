#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "lista.h"

/**
 * typedef Arbol: TAD de un arbol AVL
 * @clave: clave de ordenamiento
 * @balance: factor de balance entre altura izquierda y derecha
 * @hijos: vector arista hacia los hijos
 *
 * Este TAD será utilizado para representar el Árbol Binario de
 * Búsqueda Balanceado AVL. Existe el arbol nulo, el árbol unitario
 * es asimilable a un nodo y cada hijo de un nodo es un subárbol,
 * por lo que se omite la definición de nodo.
 */
typedef struct Arbol {
    int clave;
    int balance;
    struct Arbol *hijos[2];
} Arbol;

/**
 * insertarArbol() - Método para insertar una nueva clave en el árbol.
 * @arbol: árbol al que se quiere insertar la nueva clave.
 * @clave: una nueva clave.
 *
 * Método para insertar una nueva clave en el árbol. Precondición: ninguna.
 * Postcondicion: si la clave no existe en el árbol se aloca memoria para
 * un nuevo árbol unitario con la clave a insertar; la raiz del árbol puede
 * haber cambiado; un enlace del árbol puede haber cambiado para incluir el
 * árbol unitario con la nueva clave.
 *
 * Return: un Arbol que contiene la clave.
 */
Arbol *insertarArbol(Arbol *arbol, int clave);

/**
 * insertarArbol() - Método para borrar una clave existente en el árbol.
 * @arbol: árbol al que se quiere borrar la clave.
 * @clave: una clave existente en el árbol.
 *
 * Método para borrar una clave existente en el árbol. Precondición: ninguna.
 * Postcondicion: si la clave existe en el árbol se liberará la memoria de
 * un árbol unitario; la raiz del árbol puede haber cambiado; un enlace del
 * árbol puede haber cambiado para saltear el arbol unitario eliminado; el
 * árbol unitario que contenía la clave originalmente puede haber cambiado
 * la clave ahora.
 *
 * Return: un Arbol que no contiene la clave.
 */
Arbol *borrarArbol(Arbol *arbol, int clave);

Arbol *buscarArbol(Arbol *arbol, int clave);

Lista *preordenArbol(Arbol *arbol);

Lista *postordenArbol(Arbol *arbol);

Lista *enordenArbol(Arbol *arbol);

/* Tipos y métodos privados */

typedef enum {IZQUIERDA, DERECHA} Direccion;

typedef struct {
    Arbol *arbol;
    Direccion hijo;
} Camino;

Arbol *crearArbol(int clave);

Lista *buscarArbolLista(Arbol *arbol, int clave, Lista *camino);

Camino *crearCamino(Arbol *arbol, Direccion hijo);

void borrarArbolLista(Lista *lista);

#endif // AVL_H_INCLUDED
