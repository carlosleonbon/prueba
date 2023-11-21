#pragma once
#include "estructuras.h"
#include <stdio.h> 

void normalizarPalabra(char *palabra);

int buscarPalabra(ConteoPalabra conteo[], char *palabra, int numPalabras);

//problema 2

void mostrarUsuarios(FILE *archivo);

void agregarUsuario(FILE *archivo);

void modificarSaldo(FILE *archivo, int pin, float nuevoSaldo);