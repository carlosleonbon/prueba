#define MAX_LONGITUD_PALABRA 100
#pragma once

typedef struct ConteoPalabra{
    char palabra[MAX_LONGITUD_PALABRA];
    int frecuencia;
}ConteoPalabra;


typedef struct Usuario{
    char nombre[50];
    int pin;
    float saldo;
} Usuario;