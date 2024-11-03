#ifndef PASAJERO_H_INCLUDED
#define PASAJERO_H_INCLUDED

struct PasajeroE;

typedef struct PasajeroE * PasajeroPtr;

PasajeroPtr crearPasajero(char* n, int num);
PasajeroPtr crearPasajeroxTec();

void mostrarPasajero(PasajeroPtr p);
void mostrarPasajeroGenerico(void * d);

void liberarPasajero(PasajeroPtr p);

#endif // PASAJERO_H_INCLUDED
