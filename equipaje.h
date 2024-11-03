#ifndef EQUIPAJE_H_INCLUDED
#define EQUIPAJE_H_INCLUDED

struct EquipajeE;

typedef struct EquipajeE * EquipajePtr;

EquipajePtr crearEquipaje(float p, int n);
EquipajePtr crearEquipajexTec();

void mostrarEquipaje(EquipajePtr e);
void mostrarEquipajeGenerico(void * d);

void liberarEquipaje(EquipajePtr e);

#endif // EQUIPAJE_H_INCLUDED
