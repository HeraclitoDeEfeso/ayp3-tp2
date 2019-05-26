#include <string.h>
#include "nodo.h"
    void agregar(Nodo *nodo, int key, int valor){
        int i;
        for(i = 0; i< 2; i++){
            if nodo-> keys[i] == NULL{
                nodo->keys[i] = key;
                nodo->valores[i] = valores;
            }
        }
        while(i>0){
            if (nodo->keys[i] > nodo->keys[i-1]){
                Nodo.swapn(nodo->keys, i);
                Nodo.swapn(nodo->valores, i);
            }
        }
    }

    void split(Nodo padre,int key){
    }
    void swapn(int lista[2], int key){
    }
