#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "calculos.h"

int main(int argc, char *argv[])
{
    int verif;
    int n, opc;
    char entrada[25], busqueda[25];

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

    char productos[n][25]; // Creacion de variables con el tamano ingresado por el usuario
    float precios[n];

    // Ingreso de nombres de productos
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
                printf("\nSolo se permiten letras. Intentelo de nuevo.");
                nombreValido = 0;
            }

        } while (nombreValido == 0);
    }

    //Ingreso de precios de productos
    for (int i = 0; i < n; i++)
    {
        int precioValido = 0;
        do
        {
            printf("\nIngrese el precio de %s: ", productos[i]);
            if (fgets(entrada, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }

            // Eliminar el salto de línea al final de la cadena
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionFloat(entrada) == 1)
            {
                float precioIngresado = atof(entrada);

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
        do
        {
            printf("\n=====================================\n");
            printf("\nElija la opcion deseada:");
            printf("\n1) Precio total del inventario");
            printf("\n2) Producto mas caro y mas barato");
            printf("\n3) Promedio de precios");
            printf("\n4) Buscar producto por nombre");
            printf("\n5) Salir");
            printf("\n>>> ");

            verif = 0;
            if (fgets(entrada, 25, stdin) == NULL)
            {
                LimpiarBuffer();
                continue;
            }
            entrada[strcspn(entrada, "\n")] = '\0';

            if (VerificacionDigitos(entrada))
            {
                opc = atoi(entrada);
                verif = 1;
            }
            else
            {
                printf("\nSolo se permiten numeros enteros. Intentelo de nuevo...");
            }
        } while (verif == 0);

        switch (opc)
        {
        case 1:
            printf("\nEl precio total del inventario es: %.2f", PrecioTotal(precios, n));
            break;

        case 2:
            CaroBarato(productos, precios, n);
            break;

        case 3:
            float promedio = Promediar(precios, n);
            printf("\nEl precio promedio de los productos es: %.2f", promedio);
            break;

        case 4:

            int nombreValido = 0;
            do
            {
                printf("\nIngrese el producto que desea buscar: ");
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
                    strcpy(busqueda, entrada);
                    nombreValido = 1;
                }
                else
                {
                    printf("\nSolo se permiten letras sin simbolos. Intentelo de nuevo.");
                    nombreValido = 0;
                }

            } while (nombreValido == 0);

            BuscarProd(busqueda, productos, precios, n);
            break;

        case 5:
            printf("\nGracias por usar nuestro sistema. Saliendo...");
            return 0;
            break;

        default:
            printf("\nOpcion invalida. Intente de nuevo.");
            break;
        }

    } while (opc != 6);

    return 0;
}