#include <stdio.h>
#include <stdlib.h>
#include "equipaje.h"

struct EquipajeE{
    float peso;
    int numEtiqueta;
};

EquipajePtr crearEquipaje(float p, int n){
    EquipajePtr e = (EquipajePtr) malloc (sizeof(struct EquipajeE));

    e->peso =  p;
    e->numEtiqueta = n;

    return e;
};

EquipajePtr crearEquipajexTec(){
    EquipajePtr e = (EquipajePtr) malloc (sizeof(struct EquipajeE));

    printf("Ingrese el peso del equipaje:\n");
    scanf("%f",&e->peso);
    printf("Ingrese el numero de la etiqueta:\n");
    scanf("%d",&e->numEtiqueta);

    return e;
};

void mostrarEquipaje(EquipajePtr e){
    printf("PESO: %f \n", e->peso);
    printf("NUMERO DE ETIQUETA: %d \n", e->numEtiqueta);
};

void mostrarEquipajeGenerico(void * d){
    EquipajePtr e = (EquipajePtr) d;
    mostrarEquipaje(e);
}

void liberarEquipaje(EquipajePtr e){
    free(e);
};
