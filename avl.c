#include <stdlib.h>
#include "avl.h"

Arbol *insertarArbol(Arbol *arbol, int clave)
{
    if (NULL != arbol) {
        if (clave < arbol->clave)
            arbol->izquierda = insertarArbol(arbol->izquierda, clave);
        else if (clave > arbol->clave)
            arbol->derecha = insertarArbol(arbol->derecha, clave);
    } else {
        arbol = crearArbol(clave);
    }
    return arbol;
}

Arbol *borrarArbol(Arbol *arbol, int clave)
{
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
