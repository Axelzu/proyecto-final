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
int main() {
    // se creo un arreglo de citas paraponer un maximo de citas
    struct Cita citas[100];
    int numCitas = 0;

    //  esta variable  sirve para almacenar la opción del menú seleccionada por el usuario
    int opcion;

    do {
        // Mostrar el menú en el codigo
        printf("----- Menú -----\n");
        printf("1. Agendar cita\n");
        printf("2. Mostrar citas agendadas\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                // Pedir al usuario que ingrese los detalles de la cita
                struct Cita nuevaCita;
                printf("Ingrese la fecha de la cita (dd mm aaaa): ");
                scanf("%d %d %d", &nuevaCita.dia, &nuevaCita.mes, &nuevaCita.año);
                printf("Ingrese la hora de la cita (hh mm): ");
                scanf("%d %d", &nuevaCita.hora, &nuevaCita.minuto);
                printf("Ingrese la especialidad: ");
                scanf("%s", nuevaCita.especialidad);

                if (citaDisponible(citas, numCitas, nuevaCita)) {
                    citas[numCitas] = nuevaCita;
                    numCitas++;
                    printf("Cita agendada correctamente.\n");
                } else {
                    printf("La cita ya está reservada.\n");
                }
                break;
            case 2:
                mostrarCitas(citas, numCitas);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, ingrese una opción válida.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}
