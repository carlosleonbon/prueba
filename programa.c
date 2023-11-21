#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "estructuras.h"
#define MAX_LONGITUD_PALABRA 100

int main() {
    char nombreArchivo[] = "texto.txt";
    FILE *archivo;
    char palabra[MAX_LONGITUD_PALABRA];

    archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        return 1;
    }

    ConteoPalabra conteo[1000]; // Arreglo para almacenar conteo de palabras
    int numPalabras = 0;

    while (fscanf(archivo, "%s", palabra) == 1) {
        normalizarPalabra(palabra);

        int indice = buscarPalabra(conteo, palabra, numPalabras);
        if (indice != -1) {
            conteo[indice].frecuencia++;
        } else {
            strcpy(conteo[numPalabras].palabra, palabra);
            conteo[numPalabras].frecuencia = 1;
            numPalabras++;
        }
    }

    fclose(archivo);

    // Generar reporte
    printf("Reporte de frecuencia de palabras:\n");
    printf("------------------------------\n");
    for (int i = 0; i < numPalabras; i++) {
        printf("%s : %d\n", conteo[i].palabra, conteo[i].frecuencia);
    }

    return 0;
}

