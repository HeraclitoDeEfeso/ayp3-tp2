#include <stdio.h>
#include "menu.h"
#include "avl.h"
#include "app.h"

int main()
{
    int opcion = 0;
    Arbol *miArbol = NULL;
    char *opciones[] = {"Insertar una clave.",
                        "Eliminar una clave.",
                        "Buscar una clave.",
                        "Recorrido en orden.",
                        "Recorrido pre orden.",
                        "Recorrido post orden.",
                        "Salir."};
    Menu miMenu = crearMenu("Listado de las operaciones disponibles", opciones, 7);
    printf("Aplicacion de prueba de un arbol AVL.\n");
    while (opcion != 7) {
        opcion = activarMenu(miMenu);
        switch (opcion) {
        case 1:
            miArbol = insertarArbol(miArbol, solicitarClave());
            break;
        case 2:
            miArbol = eliminarArbol(miArbol, solicitarClave());
            break;
        case 3:
            if (buscarArbol(miArbol, solicitarClave()))
                printf("La clave existe en el arbol.\n");
            else
                printf("La clave NO existe en el arbol.\n");
            break;
        case 4:
            mostrarRecorrido(enordenArbol(miArbol));
            break;
        case 5:
            mostrarRecorrido(preordenArbol(miArbol));
            break;
        case 6:
            mostrarRecorrido(postordenArbol(miArbol));
        }
    }
    return 0;
}

int solicitarClave() {
    int clave;
    do {
        printf("\nPor favor, ingrese un numero entero: ");
        if (scanf("%d", &clave) < 1)
            while (fgetc(stdin) != '\n');
        else
            break;
    } while (1);
    return clave;
}

void mostrarRecorrido(Lista *lista) {
    printf("\nClaves del arbol: ");
    while (lista) {
        printf("%i ", ((Arbol *) lista->dato)->clave);
        lista = desapilarLista(lista);
    }
    printf("\n");
}
