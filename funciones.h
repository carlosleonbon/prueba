#pragma once



void asignarPalabra(struct Palabra *p, const char *nuevaPalabra, int repeticiones);

void liberarPalabras(struct Palabra *palabras, int numPalabras);

int buscarPalabra(struct Palabra *palabras, int numPalabras, const char *palabra);