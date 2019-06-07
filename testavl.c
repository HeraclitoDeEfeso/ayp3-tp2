#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

void mostrarArbol(Arbol *arbol, int level)
{
    if (arbol) {
        printf("%.4i(%2i)\n", arbol->clave, arbol->balance);
        if (arbol->izquierda) {
            printf("%*s", 4 * level + 4, "izq:" );
            mostrarArbol(arbol->izquierda, level + 1);
        }
        if (arbol->derecha) {
            printf("%*s", 4 * level + 4, "der:" );
            mostrarArbol(arbol->derecha, level + 1);
        }
    } else {
        printf("\n");
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int altura(Arbol *arbol)
{
    return (arbol != NULL)
           ? 1 + max(altura(arbol->izquierda), altura(arbol->derecha))
           : 0;
}

int esAVL(Arbol *arbol)
{
    return  arbol == NULL
            || (abs(altura(arbol->izquierda) - altura(arbol->derecha)) <= 1
                && esAVL(arbol->izquierda)
                && esAVL(arbol->derecha));
}

void testCrearUnArbol()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    assert(arbol->clave == 5);
}

void testCrearUnArbolConDosNodosUnoADerecha()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 7);
    assert(esAVL(arbol));
    assert(arbol->clave == 5);
    assert(arbol->derecha->clave == 7);
}

void testBuscarUnaClave()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 1);
    assert(esAVL(arbol));
    assert(buscarArbol(arbol,12) == NULL);
    assert(buscarArbol(arbol,1) != NULL);
}

void testBorrarLaRaizDeUnArbolConUnElemento()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, 5);
    assert(esAVL(arbol));
    assert(arbol == NULL);
}

void testBorrarLaRaizDeUnArbolConMasDeUnElemento()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, 5);
    assert(esAVL(arbol));
    assert(arbol->clave == 8);
}

void testBorrarUnElementoEnLaMitadDelArbol()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 18);
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, 8);
    assert(esAVL(arbol));
    assert(buscarArbol(arbol, 8) == NULL);
    assert(buscarArbol(arbol, 18) != NULL);
    assert(arbol->clave == 5);
}

void testInOrder()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 18);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 2);
    assert(esAVL(arbol));
    Lista *lista = enordenArbol(arbol);
    Lista *ordenada = NULL;
    apilarLista(ordenada,(int *) 2);
    apilarLista(ordenada,(int *) 4);
    apilarLista(ordenada,(int *) 5);
    apilarLista(ordenada,(int *) 8);
    apilarLista(ordenada,(int *) 18);
    while(ordenada) {
        assert(lista->dato == ordenada->dato);
        desapilarLista(ordenada);
        desapilarLista(lista);
    }
}

void testPreOrder()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 18);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 2);
    assert(esAVL(arbol));
    Lista *lista = preordenArbol(arbol);
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
}

void testPostOrder()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 18);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 2);
    assert(esAVL(arbol));
    Lista *lista = postordenArbol(arbol);
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

void testArbolConUnElementoEsAvl()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol,5);
    assert(esAVL(arbol));
}

void testBalanceoSimpleIzquierda()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 18);
    assert(esAVL(arbol));
    assert(arbol->clave == 8);
}

void testBalanceoSimpleDerecha()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 5);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 1);
    assert(arbol->clave == 4);
    assert(esAVL(arbol));
}

void testBalanceoDobleALaDerecha()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 18);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 14);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 15);
    assert(arbol->clave == 15);
    assert(esAVL(arbol));
}

void testBalanceoDobleALaIzquierda()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 6);
    assert(arbol->clave == 6);
    assert(esAVL(arbol));
}

void testBalanceoaLaDerechaDespuesDeBorrar()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 9);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 3);/*hasta aca esta balanceado*/
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, 9);
    assert(arbol->clave == 4);
    assert(arbol->derecha->clave == 8);
    assert(arbol->izquierda->clave == 3);
    assert(esAVL(arbol));
}

void testBalanceoaLaIzquierdaDespuesDeBorrar()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 9);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 11);/*hasta aca esta balanceado*/
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, 4);
    assert(arbol->clave == 9);
    assert(arbol->derecha->clave == 11);
    assert(arbol->izquierda->clave == 8);
    assert(esAVL(arbol));
}

void testBalanceoDobleALaIzquierdaDespuesDeBorrar()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol,13);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 11);/*hasta aca esta balanceado*/
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, 4);
    assert(arbol->clave == 11);
    assert(arbol->derecha->clave == 13);
    assert(arbol->izquierda->clave == 8);
    assert(esAVL(arbol));
}

void testBalanceoDobleALaDerechaDespuesDeBorrar()
{
    Arbol *arbol = NULL;
    arbol = insertarArbol(arbol, 8);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 4);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol,13);
    assert(esAVL(arbol));
    arbol = insertarArbol(arbol, 5);/*hasta aca esta balanceado*/
    assert(esAVL(arbol));
    arbol = eliminarArbol(arbol, 13);
    assert(arbol->clave == 5);
    assert(arbol->derecha->clave == 8);
    assert(arbol->izquierda->clave == 4);
    assert(esAVL(arbol));
}

void testBorradoPrecisaDobleBalanceo()
{
    Arbol *arbol = NULL;
    int i, numeros[] = {50, 25, 75, 80, 60, 40, 15, 90, 65, 55, 35, 62};
    for(i = 0; i < sizeof(numeros) / sizeof(int); i++) {
        arbol = insertarArbol(arbol, numeros[i]);
        assert(esAVL(arbol));
    }
    arbol = eliminarArbol(arbol, 15);
    assert(esAVL(arbol));
    assert(arbol->clave == 60);
}

int main()
{
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
    testBalanceoSimpleIzquierda();
    testBalanceoSimpleDerecha();
    testBalanceoDobleALaDerecha();
    testBalanceoDobleALaIzquierda();
    testBalanceoaLaDerechaDespuesDeBorrar();
    testBalanceoaLaIzquierdaDespuesDeBorrar();
    testBalanceoDobleALaDerechaDespuesDeBorrar();
    testBalanceoDobleALaIzquierdaDespuesDeBorrar();
    testBorradoPrecisaDobleBalanceo();
    return 0;
}
