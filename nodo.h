
#ifndef __NODO__
#define __NODO__

typedef struct Nodo{
    int keys[2];
    int valores[2];
    Nodo hijos[3];
} Nodo;

void split(Nodo padre, int key);
void agregar(Nodo *nodo,int key, int valor);
void swapn(int lista[],int elemento);

#endif // __NODO_H__
