#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

/**
 * solicitarClave() - Funci�n auxiliar para solicitar al usuario un entero.
 *
 * Funci�n auxiliar para solicitar al usuario un entero. Precondici�n: ninguna.
 * Postcondicion: se escribir� en la salida por defecto; no devolver� el
 * control hasta que la lectura de la entrada por defecto resulte en un entero.
 *
 * Return: un entero.
 */
int solicitarClave();

/**
 * mostrarRecorrido() - Muestra las claves de una lista de nodos.
 * @lista: lista de nodos de un �rbol.
 *
 * M�dulo para mostrar las claves de una lista de nodos. Precondici�n: no hay
 * datos nulos en la lista. Postcondicion: se escribir� en la salida por
 * defecto a�n cuando la lista sea nula.
 */
void mostrarRecorrido(Lista *lista);

#endif // APP_H_INCLUDED
