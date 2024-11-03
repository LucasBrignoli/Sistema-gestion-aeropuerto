#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "nodo.h"

struct Cola {
    NodoPtr primero;
    NodoPtr ultimo;
};

NodoPtr getUltimoCola(ColaPtr cola) {
    return cola->ultimo;
}

NodoPtr getPrimeroCola(ColaPtr cola) {
    return cola->primero;
}

void setUltimoCola(ColaPtr cola, NodoPtr nuevoUltimo) {
    cola->ultimo = nuevoUltimo;
}

void setPrimeroCola(ColaPtr cola, NodoPtr nuevoPrimero) {
    cola->primero = nuevoPrimero;
}

ColaPtr crearCola() {
    ColaPtr c = (ColaPtr)malloc(sizeof(struct Cola));
    c->primero = NULL;
    c->ultimo = NULL;
    return c;
}

void insertarUltimoCola(ColaPtr cola, DatoPtr dato) {
    NodoPtr nodo = crearNodo(dato, NULL);
    if (cola->primero == NULL) {
        cola->primero = nodo;
        cola->ultimo = nodo;
    } else {
        setSiguiente(cola->ultimo, nodo);
        cola->ultimo = nodo;
    }
}

DatoPtr eliminarPrimeroCola(ColaPtr cola) {
    if (cola->primero == NULL) return NULL;

    DatoPtr primero = getDato(cola->primero);
    NodoPtr nodo = getSiguiente(cola->primero);
    free(cola->primero);
    cola->primero = nodo;

    if (cola->primero == NULL) {
        cola->ultimo = NULL;
    }

    return primero;
}

ColaPtr duplicarCola(ColaPtr cola) {
    ColaPtr colaNueva = crearCola();
    NodoPtr c = getPrimeroCola(cola);
    while (c != NULL) {
        insertarUltimoCola(colaNueva, getDato(c));
        c = getSiguiente(c);
    }
    return colaNueva;
}

void liberarCola(ColaPtr cola) {
    while (cola->primero != NULL) {
        eliminarPrimeroCola(cola);
    }
    free(cola);
}
