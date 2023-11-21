#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LONGITUD_PALABRA 50

int main() {
    FILE *archivo = fopen("texto.txt", "r");;
    char buffer[MAX_LONGITUD_PALABRA];
    struct Palabra *palabras = NULL;
    int numPalabras = 0;

    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    while (fscanf(archivo, "%s", buffer) == 1) {
        int indice = buscarPalabra(palabras, numPalabras, buffer);
        if (indice != -1) {
            palabras[indice].repeticiones++; // Incrementa el contador de repeticiones
        } else {
            struct Palabra *temp = realloc(palabras, (numPalabras + 1) * sizeof(struct Palabra));
            if (temp == NULL) {
                printf("Error: No se pudo asignar memoria para la palabra.\n");
                break;
            } else {
                palabras = temp;
            }
            asignarPalabra(&palabras[numPalabras], buffer, 1);
            numPalabras++;
        }
    }

    fclose(archivo);

    printf("Palabras y repeticiones:\n");
    for (int i = 0; i < numPalabras; i++) {
        printf("%s : %d\n", palabras[i].cadena, palabras[i].repeticiones);
    }

    liberarPalabras(palabras, numPalabras);

    return 0;
}