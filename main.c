#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"
#include "equipaje.h"
#include "pasajero.h"
#include "vuelo.h"

int main() {
    VueloPtr v = crearVuelo(737, "Italia");
    PasajeroPtr p1 = NULL;
    EquipajePtr e1 = NULL;
    int opcion;

    do {
        printf("\n============== SISTEMA DE AEROPUERTO ================\n");
        printf("1. Agregar pasajeros a fila de check-in\n");
        printf("2. Procesar check-in y abordar pasajero\n");
        printf("3. Registrar equipaje\n");
        printf("4. Cargar equipaje al avion\n");
        printf("5. Ver ultimo pasajero a bordo\n");
        printf("6. Ver ultimo equipaje registrado\n");
        printf("7. Ver informacion del vuelo\n");
        printf("8. Dar de baja ultimo equipaje\n");
        printf("9. Dar de baja primer pasajero\n");
        printf("10. Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: {
                p1 = crearPasajeroxTec();
                printf("Pasajero agregado a la fila de check-in\n");
                break;
            }
            case 2: {
                insertarUltimoPasajero(v, p1);
                printf("Pasajero abordado\n");
                break;
            }
            case 3: {
                e1 = crearEquipajexTec();
                printf("Equipaje registrado\n");
                break;
            }
            case 4: {
                insertarUltimoEquipaje(v, e1);
                printf("Equipaje cargado al avion\n");
                break;
            }
            case 5: {
                mostrarUltimoPasajero(v);
                break;
            }
            case 6: {
                mostrarUltimoEquipaje(v);
                break;
            }
            case 7: {
                mostrarVuelo(v);
                break;
            }
            case 8: {
                eliminarUltimoEquipaje(v);
                printf("Equipaje dado de baja correctamente\n");
                break;
            }
            case 9: {
                eliminarPrimerPasajero(v);
                printf("Pasajero dado de baja correctamente\n");
                break;
            }
            case 10: {
                printf("Saliendo del sistema... .. .\n");
                break;
            }
            default: {
                printf("Opción no válida. Intente de nuevo.\n");
                break;
            }
        }
    } while(opcion != 10); // Corrección de la condición de salida

    return 0;
}
