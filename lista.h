#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct Lista {
    void *dato;
    struct Lista *siguiente;
} Lista;

/**
 * agregarLista() - M�todo para agregar un dato al final de la lista.
 * @lista: lista a la que se desea agregar el dato.
 * @dato: dato que se desea agregar.
 *
 * M�todo para agregar un dato al final de la lista. Precondici�n: memoria
 * suficiente. Postcondicion: se alocar� memoria para una lista unitaria;
 * se inicializar�n sus atributos, la arista del �ltimo en la lista cambiar�.
 *
 * Return: la misma lista con el dato agregado.
 */
Lista *agregarLista(Lista *lista, void *dato);

/**
 * apilarLista() - M�todo para agregar un dato al principio de la lista.
 * @lista: lista a la que se desea agregar el dato.
 * @dato: dato que se desea agregar.
 *
 * M�todo para agregar un dato al principio de la lista. Precondici�n: memoria
 * suficiente. Postcondicion: se alocar� memoria para una lista unitaria;
 * se inicializar�n sus atributos.
 *
 * Return: una nueva lista con el dato agregado al principio.
 */
Lista *apilarLista(Lista *lista, void *dato);

/**
 * desapilarLista() - M�todo para eliminar de la lista el primer dato.
 * @lista: lista a la que se le desea eliminar el dato.
 *
 * M�todo para eliminar de la lista el primer dato. Precondici�n: ninguna.
 * Postcondicion: es posible que se desaloque memoria para una lista unitaria.
 *
 * Return: una nueva lista sin el primer dato que ten�a la lista original.
 */
Lista *desapilarLista(Lista *lista);

/**
 * unirLista() - M�todo para concatenar dos listas.
 * @destino: lista a la que se le desea concatenar al final otra lista.
 * @origen: lista que ser� concatenada al final de la otra lista.
 *
 * M�todo para concatenar dos listas. Precondici�n: ninguna.
 * Postcondicion: es posible que se modifique la arista del �ltimo
 * elemento de la lista destino; si una o ambas listas son nulas, el
 * resultado es inocuo;
 *
 * Return: la lista destino con la lista origen concatenada al final.
 */
Lista *unirLista(Lista *destino, Lista *origen);

/**
 * borrarLista() - M�todo para borrar una lista.
 * @lista: lista que se desea borrar.
 *
 * M�todo para borrar una lista. Precondici�n: ninguna.
 * Postcondicion: es posible que se desaloque memoria ocupada por la
 * lista; si la lista es nula el resultado es inocuo;
 */
void borrarLista(Lista *lista);

/* M�todos privados */

/**
 * crearLista() - M�todo para crear una lista unitaria.
 * @dato: dato de la lista.
 * @lista: arista a otro lista que ser� la continuaci�n.
 *
 * M�todo para crear una lista unitaria. Precondici�n: memoria suficiente.
 * Postcondicion: se alocar� memoria para una lista unitaria.
 *
 * Return: una nueva lista con el dato por elemento y la lista por continuaci�n
 */
Lista *crearLista(void *dato, Lista *lista);

#endif // LISTA_H_INCLUDED
