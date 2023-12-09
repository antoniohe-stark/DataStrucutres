#include<stdio.h>
#include<stdlib.h> 
struct Nodo{
    int dato;
    struct Arista* adyacente;   
};
 
struct Arista {
    struct Nodo* destino;   
    struct Arista* siguiente; 
};

// Función para imprimir los vertices adyacentes
void imprimirAdyacentes(struct Nodo* nodo){
    struct Arista* arista = nodo->adyacente;
    while (arista != NULL) {
        printf("%d ", arista->destino->dato);
        arista = arista->siguiente;
    }
    printf("\n");
}

int main(){

    // Creando nodos 
    struct Nodo* nodo1 = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* nodo2 = (struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* nodo3 = (struct Nodo*) malloc(sizeof(struct Nodo));

    // asignando valores a los nodos 
    nodo1->dato = 7;
    nodo2->dato = 9;
    nodo3->dato = 16;

    //agrega aristas
    nodo1->adyacente = (struct Arista*) malloc(sizeof(struct Arista));
    nodo1->adyacente->destino = nodo2;
    nodo1->adyacente->siguiente = (struct Arista*) malloc(sizeof(struct Arista));
    nodo1->adyacente->siguiente->destino = nodo3;
    nodo1->adyacente->siguiente->siguiente = NULL;

    nodo2->adyacente = (struct Arista*) malloc(sizeof(struct Arista));
    nodo2->adyacente->destino = nodo3;
    nodo2->adyacente->siguiente = (struct Arista*) malloc(sizeof(struct Arista));
    nodo2->adyacente->siguiente->destino = nodo1;
    nodo2->adyacente->siguiente->siguiente = NULL;

    nodo3->adyacente = (struct Arista*) malloc(sizeof(struct Arista));
    nodo3->adyacente->destino = nodo1;
    nodo3->adyacente->siguiente = (struct Arista*) malloc(sizeof(struct Arista));
    nodo3->adyacente->siguiente->destino = nodo2;
    nodo3->adyacente->siguiente->siguiente = NULL;

    printf("Lista de adyacencia\n");
    printf("Vertice 1: ");
    imprimirAdyacentes(nodo1);
    printf("Vertice 2: ");
    imprimirAdyacentes(nodo2);
    printf("Vertice 3: ");
    imprimirAdyacentes(nodo3);

    return 0;
}
