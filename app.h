#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

/**
 * solicitarClave() - Función auxiliar para solicitar al usuario un entero.
 *
 * Función auxiliar para solicitar al usuario un entero. Precondición: ninguna.
 * Postcondicion: se escribirá en la salida por defecto; no devolverá el
 * control hasta que la lectura de la entrada por defecto resulte en un entero.
 *
 * Return: un entero.
 */
int solicitarClave();

/**
 * mostrarRecorrido() - Muestra las claves de una lista de nodos.
 * @lista: lista de nodos de un árbol.
 *
 * Módulo para mostrar las claves de una lista de nodos. Precondición: no hay
 * datos nulos en la lista. Postcondicion: se escribirá en la salida por
 * defecto aún cuando la lista sea nula.
 */
void mostrarRecorrido(Lista *lista);

#endif // APP_H_INCLUDED
