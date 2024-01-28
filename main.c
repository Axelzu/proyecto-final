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
// esta función sirve para mostrar las citas agendadas
void mostrarCitas(struct Cita citas[], int numCitas) {
    printf("\n");
    printf("Citas agendadas:\n");
    for (int i = 0; i < numCitas; i++) {
        printf("Fecha: %d/%d/%d\n", citas[i].dia, citas[i].mes, citas[i].año);
        printf("Hora: %d:%d\n", citas[i].hora, citas[i].minuto);
        printf("Especialidad: %s\n", citas[i].especialidad);
        printf("\n");
    }
}
