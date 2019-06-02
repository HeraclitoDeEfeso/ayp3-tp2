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
    assert(arbol->derecha->clave == 7);
}

void testBuscarUnaClave()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 4);
    arbol = insertarArbol(arbol, 1);
    assert(buscarArbol(arbol,12) == NULL);
    assert(buscarArbol(arbol,1) != NULL);
}

void testBorrarLaRaizDeUnArbolConUnElemento(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    borrarArbol(arbol, 5);
    assert(arbol == NULL);
}

void testBorrarLaRaizDeUnArbolConMasDeUnElemento(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 8);
    borrarArbol(arbol, 5);
    assert(arbol->clave == 8);
}

void testBorrarUnElementoEnLaMitadDelArbol(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 8);
    arbol = insertarArbol(arbol, 18);
    borrarArbol(arbol, 8);
    assert(buscarArbol(arbol,8) == NULL);
    assert(buscarArbol(arbol,18) != NULL);
    assert(arbol->clave == 5);
}

void testInOrder(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 8);
    arbol = insertarArbol(arbol, 18);
    arbol = insertarArbol(arbol, 4);
    arbol = insertarArbol(arbol, 2);
    enordenArbol(arbol);
    Lista *lista ;
    lista = postordenArbol(arbol);
    Lista *ordenada = NULL;
    apilarLista(ordenada,(int *) 2);
    apilarLista(ordenada,(int *) 4);
    apilarLista(ordenada,(int *) 5);
    apilarLista(ordenada,(int *) 8);
    apilarLista(ordenada,(int *) 18);
    while(ordenada){
        assert(lista->dato == ordenada->dato);
        desapilarLista(ordenada);
        desapilarLista(lista);
    }
}
void testPreOrder(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 8);
    arbol = insertarArbol(arbol, 18);
    arbol = insertarArbol(arbol, 4);
    arbol = insertarArbol(arbol, 2);
    enordenArbol(arbol);
    Lista *lista ;
    lista = postordenArbol(arbol);
    Lista *ordenada = NULL;
    apilarLista(ordenada,(int *) 5);
    apilarLista(ordenada,(int *) 4);
    apilarLista(ordenada,(int *) 2);
    apilarLista(ordenada,(int *) 8);
    apilarLista(ordenada,(int *) 18);
    while(ordenada){
        assert(lista->dato == ordenada->dato);
        desapilarLista(ordenada);
        desapilarLista(lista);
    }
}void testPostOrder(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 8);
    arbol = insertarArbol(arbol, 18);
    arbol = insertarArbol(arbol, 4);
    arbol = insertarArbol(arbol, 2);
    enordenArbol(arbol);
    Lista *lista ;
    lista = postordenArbol(arbol);
    Lista *ordenada = NULL;
    apilarLista(ordenada,(int *) 2);
    apilarLista(ordenada,(int *) 4);
    apilarLista(ordenada,(int *) 18);
    apilarLista(ordenada,(int *) 8);
    apilarLista(ordenada,(int *) 5);
    while(ordenada){
        assert(lista->dato == ordenada->dato);
        desapilarLista(ordenada);
        desapilarLista(lista);
    }
}
void testArbolNuloEsAvl(){
    Arbol *arbol = NULL;
    assert(arbol->balance <= abs(1));
}
void testArbolConUnElementoEsAvl(){
    Arbol *arbol = NULL;
    insertarArbol(arbol,5);
    assert(arbol->balance <= abs(1));
}

void testBalanceoSimpleIzquierda(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 8);
    arbol = insertarArbol(arbol, 18);
    assert(arbol->clave == 8);
    assert(arbol->balance <= abs(1));
}
void testBalanceoSimpleDerecha(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    arbol = insertarArbol(arbol, 4);
    arbol = insertarArbol(arbol, 1);
    assert(arbol->clave == 4);
    assert(arbol->balance <= abs(1));
}

void testBalanceoDobleALaDerecha(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 18);
    arbol = insertarArbol(arbol, 14);
    arbol = insertarArbol(arbol, 15);
    assert(arbol->clave == 15);
    assert(arbol->balance <= abs(1));
}

void testBalanceoDobleALaIzquierda(){
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 8);
    arbol = insertarArbol(arbol, 4);
    arbol = insertarArbol(arbol, 6);
    assert(arbol->clave == 4);
    assert(arbol->balance <= abs(1));
}
int main(){
    testCrearUnArbol();
    testCrearUnArbolConDosNodosUnoADerecha();
    testBuscarUnaClave();
    testBorrarLaRaizDeUnArbolConMasDeUnElemento();
    testBorrarLaRaizDeUnArbolConUnElemento();
    testBorrarUnElementoEnLaMitadDelArbol();
    testInOrder();
    testPostOrder();
    testPreOrder();
    testArbolConUnElementoEsAvl();
    testArbolNuloEsAvl();
    testBalanceoDobleALaDerecha();
    testBalanceoDobleALaIzquierda();
    testBalanceoSimpleDerecha();
    testBalanceoSimpleIzquierda();
    return 0;
}
