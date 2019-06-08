#include <stdlib.h>
#include "avl.h"

Arbol *insertarArbol(Arbol *arbol, int clave)
{
    insertarArbolBalanceado(&arbol, clave);
    return arbol;
}

Arbol *eliminarArbol(Arbol *arbol, int clave)
{
    eliminarArbolBalanceado(&arbol, clave);
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
        balancearArbol(destino);
        /* Cambio de altura si me desbalancea un hijo */
        cambioAltura = (*destino)->balance != 0 && cambioAltura != 0;
    } else {
        *destino = crearArbol(clave);
        cambioAltura = 1;
    }
    return cambioAltura;
}

int eliminarArbolBalanceado(Arbol **destino, int clave)
{
    int cambioAltura = 0;
    int nuevaClave;
    if (NULL != *destino) {
        if ((*destino)->clave != clave) {
            /* Modifico mi balance con el cambio de altura pero de mi hijo */
            if ((*destino)->clave > clave) {
                cambioAltura = eliminarArbolBalanceado(&((*destino)->izquierda), clave);
                (*destino)->balance += cambioAltura;
            } else {
                cambioAltura = eliminarArbolBalanceado(&((*destino)->derecha), clave);
                (*destino)->balance -= cambioAltura;
            }
            balancearArbol(destino);
            /* Cambio de altura si me balanceo por mi hijo */
            cambioAltura = -((*destino)->balance == 0 && cambioAltura != 0);
        } else if (NULL == (*destino)->derecha) {
            *destino = (*destino)->izquierda;
            cambioAltura = -1;
        }
        else if (NULL == (*destino)->izquierda) {
            *destino = (*destino)->derecha;
            cambioAltura = -1;
        } else {
            nuevaClave = buscarMaximo((*destino)->izquierda);
            cambioAltura = eliminarArbolBalanceado(destino, nuevaClave);
            (*destino)->clave = nuevaClave;
        }
    }
    return cambioAltura;
}

void balancearArbol(Arbol **destino)
{
    if ((*destino)->balance == -2) {
        if ((*destino)->derecha->balance == 1) {
            (*destino)->derecha->balance += 1;
            rotarIzquierda(&((*destino)->derecha));
        }
        rotarDerecha(destino);
    } else if ((*destino)->balance == 2) {
        if ((*destino)->izquierda->balance == -1) {
            (*destino)->derecha->balance -= 1;
            rotarDerecha(&((*destino)->izquierda));
        }
        rotarIzquierda(destino);
    }
}

void rotarDerecha(Arbol **arbol)
{
    Arbol *nuevaRaiz = (*arbol)->derecha;
    (*arbol)->derecha = nuevaRaiz->izquierda;
    (*arbol)->balance += 2;
    nuevaRaiz->izquierda = *arbol;
    nuevaRaiz->balance += 1;
    *arbol = nuevaRaiz;
}

void rotarIzquierda(Arbol **arbol)
{
    Arbol *nuevaRaiz = (*arbol)->izquierda;
    (*arbol)->izquierda = nuevaRaiz->derecha;
    (*arbol)->balance -= 2;
    nuevaRaiz->derecha = *arbol;
    nuevaRaiz->balance -= 1;
    *arbol = nuevaRaiz;
}

int buscarMaximo(Arbol *arbol)
{
    while (NULL != arbol->derecha)
        arbol = arbol->derecha;
    return arbol->clave;
}
