#include <stdlib.h>
#include "avl.h"

Arbol *insertarArbol(Arbol *arbol, int clave)
{
    Arbol **destino = &arbol;
    Lista *camino = NULL;
    Camino *ultimo = NULL;
    if (arbol) {
        if (NULL == (camino = buscarArbolLista(arbol, clave, camino))) {
            ultimo = (Camino *) camino->dato;
            destino = &(ultimo->arbol->hijos[ultimo->hijo]);
        }
        if (NULL == *destino) {
            *destino = crearArbol(clave);
        }
        borrarArbolLista(camino);
    }
    return arbol;
}

Arbol *borrarArbol(Arbol *arbol, int clave)
{
    Arbol **destino = &arbol;
    Arbol *borrar = NULL;
    Lista *camino = NULL;
    Camino *ultimo = NULL;
    if (arbol) {
        if (NULL != (camino = buscarArbolLista(arbol, clave, camino))) {
            ultimo = (Camino *) camino->dato;
            destino = &(ultimo->arbol->hijos[ultimo->hijo]);
        }
        borrar = *destino;
        if (NULL == borrar->hijos[IZQUIERDA]) {
            *destino = borrar->hijos[DERECHA];
        } else if (NULL == borrar->hijos[DERECHA]) {
            *destino = borrar->hijos[IZQUIERDA];
        } else {
            camino = apilarLista(camino, crearCamino(arbol, IZQUIERDA));
            camino = buscarArbolLista(arbol->hijos[IZQUIERDA], clave, camino);
            ultimo = (Camino *) camino->dato;
            borrar->clave = ultimo->arbol->clave;
            borrar = ultimo->arbol;
            free(ultimo);
            desapilarLista(camino);
            ultimo = (Camino *) camino->dato;
            ultimo->arbol->hijos[DERECHA] = borrar->hijos[IZQUIERDA];
        }
        free(borrar);
        borrarArbolLista(camino);
    }
    return arbol;
}

Arbol *buscarArbol(Arbol *arbol, int clave)
{
    Lista *camino = buscarArbolLista(arbol, clave, NULL);
    Camino *ultimo = NULL;
    if (camino) {
        ultimo = (Camino *) camino->dato;
        arbol = ultimo->arbol->hijos[ultimo->hijo];
        borrarArbolLista(camino);
    }
    return arbol;
}

Lista *preordenArbol(Arbol *arbol)
{
    return arbol? unirLista(unirLista(agregarLista(NULL, arbol),
                                      preordenArbol(arbol->hijos[IZQUIERDA])),
                                      preordenArbol(arbol->hijos[DERECHA]))
                : NULL;
}

Lista *postordenArbol(Arbol *arbol)
{
    return arbol? unirLista(unirLista(postordenArbol(arbol->hijos[IZQUIERDA]),
                                      postordenArbol(arbol->hijos[DERECHA])),
                                      agregarLista(NULL, arbol))
                : NULL;
}


Lista *enordenArbol(Arbol *arbol)
{
    return arbol? unirLista(unirLista(enordenArbol(arbol->hijos[IZQUIERDA]),
                                      agregarLista(NULL, arbol)),
                                      enordenArbol(arbol->hijos[DERECHA]))
                : NULL;
}


Arbol *crearArbol(int clave)
{
    Arbol *arbol = malloc(sizeof(Arbol));
    arbol->clave = clave;
    arbol->balance = 0;
    arbol->hijos[IZQUIERDA] = NULL;
    arbol->hijos[DERECHA] = NULL;
    return arbol;
}

Lista *buscarArbolLista(Arbol *arbol, int clave, Lista *camino)
{
    Direccion direccion;
    while (arbol && arbol->clave != clave) {
        direccion = clave < arbol->clave ? IZQUIERDA : DERECHA;
        camino = apilarLista(camino, crearCamino(arbol, direccion));
        arbol = arbol->hijos[direccion];
    }
    return camino;
}

Camino *crearCamino(Arbol *arbol, Direccion hijo)
{
    Camino *camino = malloc(sizeof(Camino));
    camino->arbol = arbol;
    camino->hijo = hijo;
    return camino;
}

void borrarArbolLista(Lista *lista)
{
    while (lista) {
        free(lista->dato);
        lista = desapilarLista(lista);
    }
}
