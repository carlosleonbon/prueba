#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "estructuras.h"

int main() {
    FILE *archivo;
    int opcion;
    int pin;
    float nuevoSaldo;

    archivo = fopen("usuarios.txt", "rb+");
    if (archivo == NULL) {
        archivo = fopen("usuarios.txt", "wb+");
        if (archivo == NULL) {
            printf("Error al abrir el archivo.\n");
            return 1;
        }
    }

    while (1) {
        printf("\nBienvenido al Banco Electrónico\n");
        printf("1. Agregar Usuario\n");
        printf("2. Mostrar Usuarios\n");
        printf("3. Modificar Saldo\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarUsuario(archivo);
                break;
            case 2:
                mostrarUsuarios(archivo);
                break;
            case 3:
                printf("Ingrese el PIN del usuario: ");
                scanf("%d", &pin);
                printf("Ingrese el nuevo saldo: ");
                scanf("%f", &nuevoSaldo);
                modificarSaldo(archivo, pin, nuevoSaldo);
                break;
            case 4:
                fclose(archivo);
                return 0;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
                break;
        }
    }

    return 0;
}