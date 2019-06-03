#include <stdlib.h>
#include "avl.h"

Arbol *insertarArbol(Arbol *arbol, int clave)
{
    insertarArbolBalanceado(&arbol, clave);
    return arbol;
}

Arbol *borrarArbol(Arbol *arbol, int clave)
{
    Arbol **destino = &arbol;
    int nuevaClave;
    while (NULL != *destino && (*destino)->clave != clave)
        destino = clave < (*destino)->clave ? &((*destino)->izquierda)
                                          : &((*destino)->derecha);
    if (NULL != *destino) {
        if (NULL == (*destino)->derecha) {
            *destino = (*destino)->izquierda;
        }
        else if (NULL == (*destino)->izquierda) {
            *destino = (*destino)->derecha;
        } else {
            nuevaClave = buscarMaximo((*destino)->izquierda)->clave;
            borrarArbol(*destino, nuevaClave);
            (*destino)->clave = nuevaClave;
        }
    }
    return arbol;
}

Arbol *buscarArbol(Arbol *arbol, int clave)
{
    if (arbol && arbol->clave != clave) {
        if (clave < arbol->clave)
            arbol = buscarArbol(arbol->izquierda, clave);
        else if (clave > arbol->clave)
            arbol = buscarArbol(arbol->derecha, clave);
    }
    return arbol;
}

Lista *preordenArbol(Arbol *arbol)
{
    return arbol? unirLista(unirLista(agregarLista(NULL, arbol),
                                      preordenArbol(arbol->izquierda)),
                                      preordenArbol(arbol->derecha))
                : NULL;
}

Lista *postordenArbol(Arbol *arbol)
{
    return arbol? unirLista(unirLista(postordenArbol(arbol->izquierda),
                                      postordenArbol(arbol->derecha)),
                                      agregarLista(NULL, arbol))
                : NULL;
}


Lista *enordenArbol(Arbol *arbol)
{
    return arbol? unirLista(unirLista(enordenArbol(arbol->izquierda),
                                      agregarLista(NULL, arbol)),
                                      enordenArbol(arbol->derecha))
                : NULL;
}

Arbol *crearArbol(int clave)
{
    Arbol *arbol = malloc(sizeof(Arbol));
    arbol->clave = clave;
    arbol->balance = 0;
    arbol->izquierda = NULL;
    arbol->derecha = NULL;
    return arbol;
}

int insertarArbolBalanceado(Arbol **destino, int clave)
{
    int cambioAltura = 0;
    if (NULL != *destino) {
        /* Modifico mi balance con el cambio de altura pero de mi hijo */
        if (clave < (*destino)->clave) {
            cambioAltura = insertarArbolBalanceado(&((*destino)->izquierda), clave);
            (*destino)->balance += cambioAltura;
        }
        else if (clave > (*destino)->clave) {
            cambioAltura = insertarArbolBalanceado(&((*destino)->derecha), clave);
            (*destino)->balance -= cambioAltura;
        }
        /* Calculo mi propio cambio de altura con mi balance actual:
         * Si me balancearon, ahora destino apunta a otro nodo y perdí altura;
         * sino y mi hijo ganó altura, yo también sólo si me desestabilicé;
         * si en cambio mi hijo perdío altura, yo también sólo si me estabilicé
         */
        cambioAltura = balancearArbol(destino) ? -1                          :
                       cambioAltura ==  1      ? (*destino)->balance != 0    :
                       cambioAltura == -1      ? -((*destino)->balance == 0) : 0;
    } else {
        *destino = crearArbol(clave);
        cambioAltura = 1;
    }
    return cambioAltura;
}

int balancearArbol(Arbol **destino)
{
    int balanceado = 1;
    if ((*destino)->balance == -2) {
        if ((*destino)->derecha->balance == 1) {
            rotarIzquierda(&((*destino)->derecha));
        }
        rotarDerecha(destino);
    } else if ((*destino)->balance == 2) {
        if ((*destino)->izquierda->balance == -1) {
            rotarDerecha(&((*destino)->izquierda));
        }
        rotarIzquierda(destino);
    } else {
        balanceado = 0;
    }
    return balanceado;
}

void rotarDerecha(Arbol **arbol)
{
    Arbol *nuevaRaiz = (*arbol)->derecha;
    (*arbol)->derecha = nuevaRaiz->izquierda;
    (*arbol)->balance++;
    nuevaRaiz->izquierda = *arbol;
    nuevaRaiz->balance++;
    *arbol = nuevaRaiz;
}

void rotarIzquierda(Arbol **arbol)
{
    Arbol *nuevaRaiz = (*arbol)->izquierda;
    (*arbol)->izquierda = nuevaRaiz->derecha;
    (*arbol)->balance--;
    nuevaRaiz->derecha = *arbol;
    nuevaRaiz->balance--;
    *arbol = nuevaRaiz;
}

Arbol *buscarMaximo(Arbol *arbol)
{
    while (NULL != arbol->derecha)
        arbol = arbol->derecha;
    return arbol;
}
