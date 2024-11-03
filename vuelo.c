#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "equipaje.h"
#include "pasajero.h"
#include "vuelo.h"
#include "cola.h"
#include "pila.h"

struct VueloE{
    ColaPtr pasajerosAbordados;
    PilaPtr equipajesCargados;
    int numVuelo;
    char destino[20];
};

VueloPtr crearVuelo(int n, char* d){
    VueloPtr v = (VueloPtr)malloc(sizeof(struct VueloE));

    v->pasajerosAbordados = crearCola();
    v->equipajesCargados = crearPila();
    v->numVuelo = n;
    strcpy(v->destino, d);

    return v;
};

void insertarUltimoPasajero(VueloPtr v, PasajeroPtr p){
    insertarUltimoCola(v->pasajerosAbordados, p);
};

void insertarUltimoEquipaje(VueloPtr v, EquipajePtr e){
    insertarUltimoPila(v->equipajesCargados, e);
}

void eliminarPrimerPasajero(VueloPtr v){
    eliminarPrimeroCola(v->pasajerosAbordados);
};
void eliminarUltimoEquipaje(VueloPtr v){
    eliminarUltimoPila(v->equipajesCargados);
};

void mostrarVuelo(VueloPtr v){
    printf("\n============ INFORMACION DEL VUELO ============\n");
    printf("Numero de vuelo: %d\n", v->numVuelo);
    printf("Destino: %s\n", v->destino);

    // Mostrar último pasajero
    NodoPtr ultimoPasajero = getUltimoCola(v->pasajerosAbordados);
    if (ultimoPasajero != NULL) {
        printf("\n--- Ultimo pasajero abordado ---\n");
        PasajeroPtr p = (PasajeroPtr)getDato(ultimoPasajero);
        mostrarPasajero(p);
    } else {
        printf("\nNo hay pasajeros abordados.\n");
    }

    // Mostrar último equipaje
    NodoPtr ultimoEquipaje = getUltimoPila(v->equipajesCargados);
    if (ultimoEquipaje != NULL) {
        printf("\n--- Ultimo equipaje registrado ---\n");
        EquipajePtr e = (EquipajePtr)getDato(ultimoEquipaje);
        mostrarEquipaje(e);
    } else {
        printf("\nNo hay equipaje registrado.\n");
    }
};

void mostrarUltimoPasajero(VueloPtr v) {
    if (v == NULL || v->pasajerosAbordados == NULL) {
        printf("\nNo hay pasajeros abordados en este vuelo.\n");
        return;
    }

    NodoPtr ultimoPasajero = getUltimoCola(v->pasajerosAbordados);
    if (ultimoPasajero != NULL) {
        printf("\n=== ULTIMO PASAJERO ABORDADO ===\n");
        PasajeroPtr p = (PasajeroPtr)getDato(ultimoPasajero);
        if (p != NULL) {
            mostrarPasajero(p);
        } else {
            printf("El nodo no tiene un pasajero válido.\n");
        }
    } else {
        printf("\nNo hay pasajeros abordados en este vuelo.\n");
    }
}

void mostrarUltimoEquipaje(VueloPtr v) {
    if (v == NULL || v->equipajesCargados == NULL) {
        printf("\nNo hay equipaje registrado en este vuelo.\n");
        return;
    }

    NodoPtr ultimoEquipaje = getUltimoPila(v->equipajesCargados);
    if (ultimoEquipaje != NULL) {
        printf("\n=== ULTIMO EQUIPAJE REGISTRADO ===\n");
        EquipajePtr e = (EquipajePtr)getDato(ultimoEquipaje);
        mostrarEquipaje(e);
    } else {
        printf("\nNo hay equipaje registrado en este vuelo.\n");
    }
}

void liberarVuelo(VueloPtr v){
    free(v);
};

///GETTERS Y SETTERS
//GETTER
ColaPtr getPasajerosAbordados(VueloPtr v) {
    return v->pasajerosAbordados;
}

PilaPtr getEquipajesCargados(VueloPtr v) {
    return v->equipajesCargados;
}

