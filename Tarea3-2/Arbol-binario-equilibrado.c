#include <stdio.h>
#include <stdlib.h>
 
struct NodoAVL {
    int dato;
    int altura;   
    struct NodoAVL *izquierdo;   
    struct NodoAVL *derecho;     
};

//obtener la altura de un nodo, puede ser NULL
int altura(struct NodoAVL *nodo) {
    if (nodo == NULL)
        return 0;
    return nodo->altura;
}
 
int max(int a, int b) {
    return (a > b) ? a : b;
}

// fn para crear un nuevo nodo en el alrbol
struct NodoAVL* crearNodoAVL(int valor) {
    struct NodoAVL *nuevoNodo = (struct NodoAVL *)malloc(sizeof(struct NodoAVL));
    nuevoNodo->dato = valor;
    nuevoNodo->altura = 1;   
    nuevoNodo->izquierdo = NULL;
    nuevoNodo->derecho = NULL;
    return nuevoNodo;
}

// rota a la derecha
struct NodoAVL* rotacionDerecha(struct NodoAVL *y) {
    struct NodoAVL *x = y->izquierdo;
    struct NodoAVL *T2 = x->derecho;

    // Realizar rotación
    x->derecho = y;
    y->izquierdo = T2;

    // Actualizar alturas
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;

    return x;
}

// rota a la izquierda
struct NodoAVL* rotacionIzquierda(struct NodoAVL *x) {
    struct NodoAVL *y = x->derecho;
    struct NodoAVL *T2 = y->izquierdo;

  
    y->izquierdo = x;
    x->derecho = T2;

    
    x->altura = max(altura(x->izquierdo), altura(x->derecho)) + 1;
    y->altura = max(altura(y->izquierdo), altura(y->derecho)) + 1;

    return y;
}
 
int obtenerBalance(struct NodoAVL *nodo) {
    if (nodo == NULL)
        return 0;
    return altura(nodo->izquierdo) - altura(nodo->derecho);
}
 
struct NodoAVL* insertarAVL(struct NodoAVL *raiz, int valor) { 
    if (raiz == NULL)
        return crearNodoAVL(valor);

    if (valor < raiz->dato)
        raiz->izquierdo = insertarAVL(raiz->izquierdo, valor);
    else if (valor > raiz->dato)
        raiz->derecho = insertarAVL(raiz->derecho, valor);
    else
        return raiz;  
    raiz->altura = 1 + max(altura(raiz->izquierdo), altura(raiz->derecho)); 
    int balance = obtenerBalance(raiz); 
    if (balance > 1 && valor < raiz->izquierdo->dato)
        return rotacionDerecha(raiz);

    //Caso derecha derecha
    if (balance < -1 && valor > raiz->derecho->dato)
        return rotacionIzquierda(raiz);

    //caso izquierda derecha
    if (balance > 1 && valor > raiz->izquierdo->dato) {
        raiz->izquierdo = rotacionIzquierda(raiz->izquierdo);
        return rotacionDerecha(raiz);
    }

    //caso derecha-izquierda
    if (balance < -1 && valor < raiz->derecho->dato) {
        raiz->derecho = rotacionDerecha(raiz->derecho);
        return rotacionIzquierda(raiz);
    }

    return raiz;
}
 
void inordenAVL(struct NodoAVL *raiz) {
    if (raiz != NULL) {
        inordenAVL(raiz->izquierdo);
        printf("%d ", raiz->dato);
        inordenAVL(raiz->derecho);
    }
}

int main() {
    struct NodoAVL *raiz = NULL;

    // Insertar nodos en el arbol 
    raiz = insertarAVL(raiz, 50);
    raiz = insertarAVL(raiz, 30);
    raiz = insertarAVL(raiz, 70);
    raiz = insertarAVL(raiz, 20);
    raiz = insertarAVL(raiz, 40); 
    printf("Recorrido inorden del arbol AVL: ");
    inordenAVL(raiz);
    printf("\n");

    return 0;
}
