#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pasajero.h"

struct PasajeroE{
    char nombre[50];
    int numAsiento;
};

PasajeroPtr crearPasajero(char* n, int num){
    PasajeroPtr p = (PasajeroPtr)malloc(sizeof(struct PasajeroE));

    strcpy(p->nombre,n);
    p->numAsiento = num;

    return p;
};

PasajeroPtr crearPasajeroxTec(){
    PasajeroPtr p = (PasajeroPtr)malloc(sizeof(struct PasajeroE));

    printf("Ingrese el nombre del pasajero: \n");
    fflush(stdin);
    gets(p->nombre);
    printf("Ingrese el numero de asiento: \n");
    scanf("%d", &p->numAsiento);

    return p;
};

void mostrarPasajero(PasajeroPtr p){
    printf("PASAJERO: %s \n", p->nombre);
    printf("NUMERO DE ASIENTO: %d\n", p->numAsiento);
};

void mostrarPasajeroGenerico(void * d){
    PasajeroPtr p = (PasajeroPtr) d;
    mostrarPasajero(p);
};

void liberarPasajero(PasajeroPtr p){
    free(p);
};
