#include <stdio.h>
#include <string.h>

/**
 * @brief Funcion para calcular el precio total del inventario
 *
 * @param precios
 * @param tamano
 * @return float Precio total de inventario
 */
float PrecioTotal(float precios[], int tamano)
{
    float suma = 0;
    for (int i = 0; i < tamano; i++)
    {
        suma += precios[i];
    }

    return suma;
}

/**
 * @brief Funcion para encontrar precios caros y baratos
 *
 * La funcion va comparando segun una cantidad para ver si el siguiente
 * elemento es menor o mayor, y segun eso imprime que producto es el mas
 * caro y barato y su precio
 *
 * @param productos
 * @param precios
 * @param tamano
 */
void CaroBarato(char productos[][25], float precios[], int tamano)
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
    printf("\nEl producto mas barato es %c y cuesta $%.2f", productos[indexBa], precioBajo);
}

/**
 * @brief Calcular promedio de los precios
 *
 * @param precios
 * @param tamano
 * @return float promedio
 */
float Promediar(float precios[], int tamano)
{
    float suma = 0, promedio = 0;
    for (int i = 0; i < tamano; i++)
    {
        suma += precios[i];
    }

    promedio = suma / tamano;
    return promedio;
}

/**
 * @brief Buscador de precios de productos
 *
 * La funcion toma el ingreso del usuario y lo compara con la matriz de productos para
 * determinar cual es el precio asociado.
 *
 * @param entrada Ingreso del usuario
 * @param productos Matriz de nombres de productos
 * @param precios Vector de precios asociados
 * @param tamano Numero de filas
 *  de la matriz de nombres
 */
void BuscarProd(char entrada[], char productos[][25], float precios[], int tamano)
{
    int encontrado = 0;
    for (int i = 0; i < tamano; i++)
    {

        if (strcmp(entrada, productos[i]) == 0)
        {
            printf("\nEl precio del producto %s es: $%.2f", entrada, precios[i]);
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0)
    {
        printf("\n Producto no encontrado.");
    }
}
