#include <stdlib.h>
#include "lista.h"

/**
 * Implementación iterativa del TAD Lista
 */

Lista *agregarLista(Lista *lista, void *dato)
{
    Lista **enlace = &lista;
    while (*enlace != NULL)
        enlace = &(*enlace)->siguiente;
    *enlace = crearLista(dato, NULL);
    return lista;
}

Lista *apilarLista(Lista *lista, void *dato)
{
    return crearLista(dato, lista);
}

Lista *desapilarLista(Lista *lista)
{
    Lista *nuevaLista = lista != NULL ? lista->siguiente : NULL;
    free(lista);
    return nuevaLista;
}

void borrarLista(Lista *lista)
{
    Lista *actual;
    while (lista != NULL) {
        actual = lista;
        lista = lista->siguiente;
        free(actual);
    }
}

Lista *crearLista(void *dato, Lista *lista)
{
    Lista *nuevaLista = malloc(sizeof(Lista));
    nuevaLista->dato = dato;
    nuevaLista->siguiente = lista;
    return nuevaLista;
}
