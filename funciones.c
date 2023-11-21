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

 