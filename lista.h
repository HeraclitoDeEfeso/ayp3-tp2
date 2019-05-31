#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista {
    void *dato;
    struct Lista *siguiente;
} Lista;

Lista *agregarLista(Lista *lista, void *dato);

Lista *apilarLista(Lista *lista, void *dato);

Lista *desapilarLista(Lista *lista);

Lista *unirLista(Lista *destino, Lista *origen);

void borrarLista(Lista *lista);

/* Métodos privados */

Lista *crearLista(void *dato, Lista *lista);

#endif // LISTA_H_INCLUDED
