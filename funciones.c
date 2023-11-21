#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estructuras.h" 

// Función para normalizar una palabra (convertirla a minúsculas)
void normalizarPalabra(char *palabra) {
    int i = 0;
    while (palabra[i]) {
        palabra[i] = tolower(palabra[i]);
        i++;
    }
}

// Función para buscar una palabra en el arreglo de conteo de palabras
int buscarPalabra(ConteoPalabra conteo[], char *palabra, int numPalabras) {
    for (int i = 0; i < numPalabras; i++) {
        if (strcmp(conteo[i].palabra, palabra) == 0) {
            return i;
        }
    }
    return -1;
}

// problema 2

void agregarUsuario(FILE *archivo) {
    Usuario nuevoUsuario;

    printf("Ingrese el nombre del usuario: ");
    scanf("%s", nuevoUsuario.nombre);

    printf("Ingrese el PIN del usuario: ");
    scanf("%d", &nuevoUsuario.pin);

    printf("Ingrese el saldo del usuario: ");
    scanf("%f", &nuevoUsuario.saldo);

    fseek(archivo, 0, SEEK_END); // Coloca el puntero al final del archivo
    fwrite(&nuevoUsuario, sizeof(Usuario), 1, archivo);
    printf("Usuario agregado con éxito.\n");
}

// Función para mostrar la información de todos los usuarios
void mostrarUsuarios(FILE *archivo) {
    Usuario usuario;

    fseek(archivo, 0, SEEK_SET); // Coloca el puntero al inicio del archivo

    printf("\nLista de Usuarios:\n");
    printf("Nombre\t\tPIN\tSaldo\n");
    printf("------------------------------------\n");

    while (fread(&usuario, sizeof(Usuario), 1, archivo) == 1) {
        printf("%s\t\t%d\t%.2f\n", usuario.nombre, usuario.pin, usuario.saldo);
    }
}

// Función para modificar el saldo de un usuario por su PIN
void modificarSaldo(FILE *archivo, int pin, float nuevoSaldo) {
    Usuario usuario;

    fseek(archivo, 0, SEEK_SET); // Coloca el puntero al inicio del archivo

    int encontrado = 0;
    while (fread(&usuario, sizeof(Usuario), 1, archivo) == 1) {
        if (usuario.pin == pin) {
            usuario.saldo = nuevoSaldo;
            fseek(archivo, -sizeof(Usuario), SEEK_CUR); // Retrocede para sobrescribir el registro
            fwrite(&usuario, sizeof(Usuario), 1, archivo);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 1) {
        printf("Saldo actualizado para el usuario con PIN %d.\n", pin);
    } else {
        printf("Usuario con PIN %d no encontrado.\n", pin);
    }
}
