#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED
#include "cola.h"
#include "pila.h"

struct VueloE;

typedef struct VueloE * VueloPtr;

VueloPtr crearVuelo(int n, char* d);

void insertarUltimoPasajero(VueloPtr v, PasajeroPtr p);
void insertarUltimoEquipaje(VueloPtr v, EquipajePtr e);

void eliminarPrimerPasajero(VueloPtr v);
void eliminarUltimoEquipaje(VueloPtr v);

void mostrarVuelo(VueloPtr v);
void mostrarUltimoPasajero(VueloPtr v);
void mostrarUltimoEquipaje(VueloPtr v);

void liberarVuelo(VueloPtr v);

ColaPtr getPasajerosAbordados(VueloPtr v);
PilaPtr getEquipajesCargados(VueloPtr v);

#endif // VUELO_H_INCLUDED
