#include <stdlib.h>
#include "avl.h"

Arbol *insertarArbol(Arbol *arbol, int clave)
{
    Arbol **destino = &arbol;
    if (NULL != *destino) {
        if (clave < (*destino)->clave)
            destino = &((*destino)->izquierda);
        else if (clave > (*destino)->clave)
            destino = &((*destino)->derecha);
        *destino = insertarArbol(*destino, clave);
    } else {
        *destino = crearArbol(clave);
    }
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
            nuevaClave = buscarArbol((*destino)->izquierda, clave)->clave;
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
