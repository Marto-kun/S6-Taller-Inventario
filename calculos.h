#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

float precioTotal(float precios[])
{
    size_t tamano = sizeof(precios);
    float suma = 0;
    for (int i = 0; i < tamano; i++)
    {
        suma += precios[i];
    }

    return suma;
}


