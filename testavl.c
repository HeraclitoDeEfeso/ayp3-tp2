#include <assert.h>
#include <stdlib.h>
#include "avl.h"

void testCrearUnArbol(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(arbol->clave == 5);
}

void testCrearUnArbolConDosNodosUnoADerecha(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 7);
    assert(arbol->clave == 5);
    assert(arbol->hijos[DERECHA] != NULL);
}

void testBuscarUnaClave()
{
    Arbol *arbol = NULL;
//    Lista *borrar;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 4);
    arbol = insertarArbol(arbol, 1);
    assert(buscarArbol(arbol,12) == NULL);
    assert(buscarArbol(arbol,1) != NULL);
//    borrar = postordenArbol(arbol);
//    while (borrar) {
//        free((Arbol *) borrar->dato);
//        borrar = desapilarLista(borrar);
//    }
}

int main(){
    testCrearUnArbol();
    testCrearUnArbolConDosNodosUnoADerecha();
    return 0;
}
