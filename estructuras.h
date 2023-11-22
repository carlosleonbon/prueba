#define longitud 100
#pragma once

typedef struct ConteoPalabra{
    char palabra[longitud];
    int frecuencia;
}ConteoPalabra;


typedef struct Usuario{
    char nombre[50];
    int pin;
    float saldo;
} Usuario;