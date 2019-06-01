#include <assert.h>
#include <stdlib.h>
#include "avl.h"
#include <stdio.h>

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
// }
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





int main(){
    printf("asadas");
    testCrearUnArbol();
    testCrearUnArbolConDosNodosUnoADerecha();
    testBuscarUnaClave();
    testBorrarLaRaizDeUnArbolConMasDeUnElemento();
    testBorrarLaRaizDeUnArbolConUnElemento();
    testBorrarUnElementoEnLaMitadDelArbol();
    testInOrder();
    testPostOrder();
    testPreOrder();
    return 0;
}
