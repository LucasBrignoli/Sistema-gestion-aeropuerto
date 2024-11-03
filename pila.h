#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include "nodo.h"

struct Pila;
typedef struct Pila * PilaPtr;

NodoPtr getUltimoPila(PilaPtr pila);

void setUltimoPila(PilaPtr pila, NodoPtr nuevoUltimo);

PilaPtr crearPila();

void insertarUltimoPila(PilaPtr pila, DatoPtr dato);

DatoPtr eliminarUltimoPila(PilaPtr pila);

PilaPtr duplicarPila(PilaPtr pila);

void liberarPila(PilaPtr pila);

#endif // PILA_H_INCLUDED
