#include <stdio.h>
#include <stdlib.h>
 
struct NodoArbol {
    int dato;
    struct NodoArbol *izquierdo;   
    struct NodoArbol *derecho;     
}; 

struct NodoArbol* crearNodoArbol(int valor) {
    struct NodoArbol *nuevoNodo = (struct NodoArbol *)malloc(sizeof(struct NodoArbol));
    nuevoNodo->dato = valor;
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}
 
struct NodoArbol* insertar(struct NodoArbol *raiz, int valor) {
    if (raiz == NULL) {
        return crearNodoArbol(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    } else if (valor > raiz->dato) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }

    return raiz;
}
void preorden(struct NodoArbol *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dato);
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}
void inorden(struct NodoArbol *raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierdo);
        printf("%d ", raiz->dato);
        inorden(raiz->derecho);
    }
}
 void postorden(struct NodoArbol *raiz) {
    if (raiz != NULL) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        printf("%d ", raiz->dato);
    }
}

int main() {
    struct NodoArbol *raiz = NULL;

    // Insertar nodos en el árbol
    raiz = insertar(raiz, 50);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 70);
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 40);

     
    printf("Recorrido preorden del árbol: ");
    preorden(raiz);
    printf("\n");

    printf("Recorrido inorden del árbol: ");
    inorden(raiz);
    printf("\n");

    printf("Recorrido postorden del árbol: ");
    postorden(raiz);
    printf("\n");
    return 0;
}