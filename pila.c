#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "nodo.h"

struct Pila {
    NodoPtr ultimo;
};

NodoPtr getUltimoPila(PilaPtr pila) {
    return pila->ultimo;
}

void setUltimoPila(PilaPtr pila, NodoPtr nuevoUltimo) {
    pila->ultimo = nuevoUltimo;
}

PilaPtr crearPila() {
    PilaPtr p = (PilaPtr)malloc(sizeof(struct Pila));
    p->ultimo = NULL;
    return p;
}

void insertarUltimoPila(PilaPtr pila, DatoPtr dato) {
    NodoPtr nodo = crearNodo(dato, pila->ultimo);
    pila->ultimo = nodo;
}

DatoPtr eliminarUltimoPila(PilaPtr pila) {
    if (pila->ultimo == NULL) return NULL;
    DatoPtr dato = getDato(pila->ultimo);
    NodoPtr temp = pila->ultimo;
    pila->ultimo = getSiguiente(pila->ultimo);
    free(temp);
    return dato;
}

PilaPtr duplicarPila(PilaPtr pila) {
    PilaPtr pilaNueva = crearPila();
    NodoPtr actual = pila->ultimo;
    while (actual != NULL) {
        insertarUltimoPila(pilaNueva, getDato(actual));
        actual = getSiguiente(actual);
    }
    return pilaNueva;
}

void liberarPila(PilaPtr pila) {
    while (pila->ultimo != NULL) {
        eliminarUltimoPila(pila);
    }
    free(pila);
}
