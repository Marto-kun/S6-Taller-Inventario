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

void CaroBarato(char productos[], float precios[], int tamano)
{

    float precioAlto, precioBajo;
    int indexAl = 0, indexBa = 0;
    precioAlto = precios[0];
    precioBajo = precios[0];

    for (int i = 0; i < tamano; i++)
    {
        // Comparacion precio caro
        if (precioAlto < precios[i])
        {
            precioAlto = precios[i];
            indexAl = i;
        }

        // Comparacion precio barato
        if (precioBajo > precios[i])
        {
            precioBajo = precios[i];
            indexBa = i;
        }
    }

    printf("\nEl producto mas caro es %c y cuesta $%.2f", productos[indexAl], precioAlto);
}