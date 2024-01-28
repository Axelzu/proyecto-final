#include <stdio.h>

// Estructura para representar una cita médica
struct Cita {
    int dia;
    int mes;
    int año;
    int hora;
    int minuto;
    char especialidad[50];
};
//  esta función  sirve para verificar si una cita está disponible
int citaDisponible(struct Cita citas[], int numCitas, struct Cita nuevaCita) {
    for (int i = 0; i < numCitas; i++) {
        if (citas[i].dia == nuevaCita.dia &&
            citas[i].mes == nuevaCita.mes &&
            citas[i].año == nuevaCita.año &&
            citas[i].hora == nuevaCita.hora &&
            citas[i].minuto == nuevaCita.minuto) {
            return 0; // La cita ya está reservada
        }
    }
    return 1; // La cita está disponible
}
