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
    struct Arbol *izquierda;
    struct Arbol *derecha;
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
 * borrarArbol() - Método para borrar una clave existente en el árbol.
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

/**
 * buscarArbol() - Método para buscar una clave existente en el árbol.
 * @arbol: árbol en el que se quiere buscar la clave.
 * @clave: una clave existente en el árbol.
 *
 * Método para buscar una clave existente en el árbol. Precondición: ninguna.
 * Postcondicion: ninguna.
 *
 * Return: un Arbol que contiene la clave en su raiz o el arbol nulo si no.
 */
Arbol *buscarArbol(Arbol *arbol, int clave);

/**
 * preordenArbol() - El método genera una lista con recorrido pre orden del árbol.
 * @arbol: árbol que se desea recorrer.
 *
 * El método genera una lista con recorrido pre orden del árbol. Precondición: ninguna.
 * Postcondicion: se alocará memoria para una lista con cada sublista apuntando cada
 * subarbol en recorrido "pre orden": la raiz se recorre antes que los hijos.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *preordenArbol(Arbol *arbol);

/**
 * postordenArbol() - El método genera una lista con recorrido post orden del árbol.
 * @arbol: árbol que se desea recorrer.
 *
 * El método genera una lista con recorrido post orden del árbol. Precondición: ninguna.
 * Postcondicion: se alocará memoria para una lista con cada sublista apuntando cada
 * subarbol en recorrido "post orden": la raiz se recorre después de los hijos.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *postordenArbol(Arbol *arbol);

/**
 * preordenArbol() - El método genera una lista con recorrido en orden del árbol.
 * @arbol: árbol que se desea recorrer.
 *
 * El método genera una lista con recorrido en orden del árbol. Precondición: ninguna.
 * Postcondicion: se alocará memoria para una lista con cada sublista apuntando cada
 * subarbol en recorrido "en orden": la raiz se recorre después del hijo con claves
 * menores y antes del hijo con claves mayores.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *enordenArbol(Arbol *arbol);

/* Tipos y métodos privados */

Arbol *crearArbol(int clave);

int insertarArbolBalanceado(Arbol **destino, int clave);

int balancearArbol(Arbol **destino);

#endif // AVL_H_INCLUDED
