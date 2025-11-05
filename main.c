#include <stdio.h>
#include <string.h>
#include "utils.h"

int main(int argc, char *argv[])
{

    int n, opc;
    char entrada[25];
    float promedioPrecios;

    // -------------- ENTRADAS --------------

    // Ingreso de cuantos productos se desean registrar:
    int nValido = 0;

    do
    {
        printf("\nIngrese la cantidad de productos a ingresar (1 - 10): ");

        if (fgets(entrada, 25, stdin) == NULL)
        {
            LimpiarBuffer();
            continue;
        }

        // 2. Eliminar el salto de línea al final de la cadena
        entrada[strcspn(entrada, "\n")] = '\0';

        if (VerificacionDigitos(entrada))
        {
            int nIngresado = atoi(entrada);
            if (nIngresado > 0 && nIngresado <= 10)
            {
                n = nIngresado;
                nValido = 1;
            }
        }
        else
        {
            printf("\nSolo se permiten numeros del 1 al 10. Intentelo de nuevo.");
        }

    } while (nValido == 0);

    char productos[n][25]; // cambiar [1] por "n"
    float precios[n];

    for (int i = 0; i < n; i++)
    {

        int nombreValido = 0;
        do
        {
            printf("\nIngresar el nombre del producto #%i: ", i + 1);
            if (fgets(entrada, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                nombreValido = 0;
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionChar(entrada) == 1)
            {
                strcpy(productos[i], entrada);
                nombreValido = 1;
            }
            else
            {
                printf("\nSolo se permiten numeros enteros. Intentelo de nuevo.");
                nombreValido = 0;
            }

        } while (nombreValido == 0);
    }

    for (int i = 0; i < n; i++)
    {
        int precioValido = 0;
        do
        {
            printf("\nIngrese el precio unitario del libro #%i: ", i + 1);
            if (fgets(entrada, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionFloat(entrada) == 1)
            {
                int precioIngresado = atof(entrada);

                if (precioIngresado > 0)
                {
                    precios[i] = precioIngresado;
                    precioValido = 1;
                }
            }
            else
            {
                printf("\nSolo se permiten numeros positivos. Intentelo de nuevo.");
            }

        } while (precioValido == 0);
    }

    // -------------- SALIDAS --------------

    // Menu de informacion:

    do
    {
        printf("\n=====================================\n");
        printf("\nElija la opcion deseada:");
        printf("\n1) Precio total del inventario");
        printf("\n2) Producto mas caro y mas barato");
        printf("\n3) Promedio de precios");
        printf("\n4) Buscar producto por nombre");
        printf("\n5) Salir");
        printf("\n>>>");

    } while (opc != 6);

    // for (int i = 0; i < 1; i++)
    // {
    //     printf("\nNombre #%i: %s", i + 1, productos[i]);
    // }

    return 0;
}