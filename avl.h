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
    struct Arbol *izquierda;
    struct Arbol *derecha;
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
 * borrarArbol() - M�todo para borrar una clave existente en el �rbol.
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

/**
 * buscarArbol() - M�todo para buscar una clave existente en el �rbol.
 * @arbol: �rbol en el que se quiere buscar la clave.
 * @clave: una clave existente en el �rbol.
 *
 * M�todo para buscar una clave existente en el �rbol. Precondici�n: ninguna.
 * Postcondicion: ninguna.
 *
 * Return: un Arbol que contiene la clave en su raiz o el arbol nulo si no.
 */
Arbol *buscarArbol(Arbol *arbol, int clave);

/**
 * preordenArbol() - El m�todo genera una lista con recorrido pre orden del �rbol.
 * @arbol: �rbol que se desea recorrer.
 *
 * El m�todo genera una lista con recorrido pre orden del �rbol. Precondici�n: ninguna.
 * Postcondicion: se alocar� memoria para una lista con cada sublista apuntando cada
 * subarbol en recorrido "pre orden": la raiz se recorre antes que los hijos.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *preordenArbol(Arbol *arbol);

/**
 * postordenArbol() - El m�todo genera una lista con recorrido post orden del �rbol.
 * @arbol: �rbol que se desea recorrer.
 *
 * El m�todo genera una lista con recorrido post orden del �rbol. Precondici�n: ninguna.
 * Postcondicion: se alocar� memoria para una lista con cada sublista apuntando cada
 * subarbol en recorrido "post orden": la raiz se recorre despu�s de los hijos.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *postordenArbol(Arbol *arbol);

/**
 * preordenArbol() - El m�todo genera una lista con recorrido en orden del �rbol.
 * @arbol: �rbol que se desea recorrer.
 *
 * El m�todo genera una lista con recorrido en orden del �rbol. Precondici�n: ninguna.
 * Postcondicion: se alocar� memoria para una lista con cada sublista apuntando cada
 * subarbol en recorrido "en orden": la raiz se recorre despu�s del hijo con claves
 * menores y antes del hijo con claves mayores.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
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
