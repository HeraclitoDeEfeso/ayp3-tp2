#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "lista.h"

/**
 * typedef Arbol: TAD de un arbol AVL
 * @clave: clave de ordenamiento
 * @balance: factor de balance entre altura izquierda y derecha
 * @hijos: vector arista hacia los hijos
 *
 * Este TAD ser� utilizado para representar el �rbol Binario de
 * B�squeda Balanceado AVL. Existe el arbol nulo, el �rbol unitario
 * es asimilable a un nodo y cada hijo de un nodo es un sub�rbol,
 * por lo que se omite la definici�n de nodo.
 */
typedef struct Arbol {
    int clave;
    int balance;
    struct Arbol *hijos[2];
} Arbol;

/**
 * insertarArbol() - M�todo para insertar una nueva clave en el �rbol.
 * @arbol: �rbol al que se quiere insertar la nueva clave.
 * @clave: una nueva clave.
 *
 * M�todo para insertar una nueva clave en el �rbol. Precondici�n: ninguna.
 * Postcondicion: si la clave no existe en el �rbol se aloca memoria para
 * un nuevo �rbol unitario con la clave a insertar; la raiz del �rbol puede
 * haber cambiado; un enlace del �rbol puede haber cambiado para incluir el
 * �rbol unitario con la nueva clave.
 *
 * Return: un Arbol que contiene la clave.
 */
Arbol *insertarArbol(Arbol *arbol, int clave);

/**
 * insertarArbol() - M�todo para borrar una clave existente en el �rbol.
 * @arbol: �rbol al que se quiere borrar la clave.
 * @clave: una clave existente en el �rbol.
 *
 * M�todo para borrar una clave existente en el �rbol. Precondici�n: ninguna.
 * Postcondicion: si la clave existe en el �rbol se liberar� la memoria de
 * un �rbol unitario; la raiz del �rbol puede haber cambiado; un enlace del
 * �rbol puede haber cambiado para saltear el arbol unitario eliminado; el
 * �rbol unitario que conten�a la clave originalmente puede haber cambiado
 * la clave ahora.
 *
 * Return: un Arbol que no contiene la clave.
 */
Arbol *borrarArbol(Arbol *arbol, int clave);

Arbol *buscarArbol(Arbol *arbol, int clave);

Lista *preordenArbol(Arbol *arbol);

Lista *postordenArbol(Arbol *arbol);

Lista *enordenArbol(Arbol *arbol);

/* Tipos y m�todos privados */

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
