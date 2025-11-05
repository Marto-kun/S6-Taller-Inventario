#include <stdio.h>
#include <string.h>
#include "utils.h"

int main(int argc, char *argv[])
{

    int n;
    char entrada[25];

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

    char productos[1][25]; // cambiar [1] por "n"

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

    for (int i = 0; i < 1; i++)
    {
        printf("\nNombre #%i: %s", i + 1, productos[i]);
    }

    return 0;
}