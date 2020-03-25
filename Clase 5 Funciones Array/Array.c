#include "Array.h"

void mostrarArray (int miArray[], int cantidadSubindices)
{
    int i;
    for(i=0; i<cantidadSubindices; i++)
    {
        printf("%d\n", miArray[i]);
    }
    printf("\n");
}
void mostrarMaximo (int miArray[], int cantidadSubindices)
{
    int i;
    int mayor;
    for (i=0; i<cantidadSubindices; i++)
    {
        if(i== 0 || miArray[i]>mayor)
        {
            mayor = miArray[i];
        }
    }
    printf("El mayor es: %d\n", mayor);
    printf("\n");
}

void inicializarArray (int miArray[], int cantidadSubindices)
{
    int i;

    for (i=0; i<cantidadSubindices; i++)
    {
        miArray[i]=0;
    }
    printf("\n");
}
void cargaSecuencialArray (int miArray[], int cantidadSubindices, char mensaje[])
{
    int i;

    for (i=0; i<cantidadSubindices; i++)
    {
        printf(mensaje);
        scanf("%d", &miArray[i]);
    }
    printf("\n");
}
void promediarArray (int miArray [], int cantidadSubindices)
{
    int i;
    int acumulador;
    float promedio;
    acumulador = 0;

    for (i=0; i<cantidadSubindices; i++)
    {
        acumulador = acumulador + miArray[i];
    }
    promedio = (float)acumulador / cantidadSubindices;
    printf("El promedio es %f\n", promedio);
    printf("\n");
}
void ordenarArray (int miArray[], int cantidadSubindices)
{
    int i;
    int j;
    int aux;

    for(i = 0; i < cantidadSubindices; i++)
    {
        for(j = i + 1; j < cantidadSubindices; j++)
        {
            if(miArray[i] > miArray[j])
            {
                aux = miArray[i];
                miArray[i] = miArray[j];
                miArray[j] = aux;
            }
        }
        printf("%d\n", miArray[i]);
    }
}

