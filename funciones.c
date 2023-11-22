#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estructuras.h" 

void normalizarPalabra(char *palabra) {
    int i = 0;
    while (palabra[i]) {
        palabra[i] = tolower(palabra[i]);
        i++;
    }
}

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

    fseek(archivo, 0, SEEK_END); 
    fwrite(&nuevoUsuario, sizeof(Usuario), 1, archivo);
    printf("Usuario agregado con éxito.\n");
}


void mostrarUsuarios(FILE *archivo) {
    Usuario usuario;

    fseek(archivo, 0, SEEK_SET); 

    printf("\nLista de Usuarios:\n");
    printf("Nombre\t\tPIN\tSaldo\n");
    printf("------------------------------------\n");

    while (fread(&usuario, sizeof(Usuario), 1, archivo) == 1) {
        printf("%s\t\t%d\t%.2f\n", usuario.nombre, usuario.pin, usuario.saldo);
    }
}


void modificarSaldo(FILE *archivo, int pin, float nuevoSaldo) {
    Usuario usuario;

    fseek(archivo, 0, SEEK_SET); 

    int encontrado = 0;
    while (fread(&usuario, sizeof(Usuario), 1, archivo) == 1) {
        if (usuario.pin == pin) {
            usuario.saldo = nuevoSaldo;
            fseek(archivo, -sizeof(Usuario), SEEK_CUR); 
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
