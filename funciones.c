#include "funciones.h"
#include "estructuras.h"

void asignarPalabra(struct Palabra *p, const char *nuevaPalabra, int repeticiones) {
    p->cadena = (char *)malloc((strlen(nuevaPalabra) + 1) * sizeof(char));
    if (p->cadena != '\0') {
        strcpy(p->cadena, nuevaPalabra);
        p->repeticiones = repeticiones;
    } else {
        printf("Error: No se pudo asignar memoria para la palabra.\n");
    }
}

void liberarPalabras(struct Palabra *palabras, int numPalabras) {
    for (int i = 0; i < numPalabras; i++) {
        free(palabras[i].cadena);
    }
    free(palabras);
}

int buscarPalabra(struct Palabra *palabras, int numPalabras, const char *palabra) {
    for (int i = 0; i < numPalabras; i++) {
        if (strcmp(palabras[i].cadena, palabra) == 0) {
            return i; // La palabra ya existe en la estructura, devuelve su índice
        }
    }
    return -1; // La palabra no existe en la estructura
}