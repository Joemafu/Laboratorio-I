#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4
#define MAXCHAR 50

void cargarConDatosEnteros(int[], int);
void cargarNombres(char[][MAXCHAR], int);
void mostrarResultado (char[][MAXCHAR], int[],int);
void mostrarDatos (char[][MAXCHAR], int[]);
int calcularNotaMax();

int main()
{
    int notas [TAM];
    char nombres [TAM][MAXCHAR];
    int subMax;

    cargarConDatosEnteros(notas, TAM);
    cargarNombres(nombres, TAM);
    mostrarDatos(nombres,notas);
    subMax=calcularNotaMax(nombres,notas);
    mostrarResultado(nombres,notas,subMax);

    return 0;
}

void cargarConDatosEnteros(int array[], int cantidad)
{
    int aux[TAM]= {4,10,8,2};
    int i;

    for(i=0; i<cantidad; i++)
    {
        array[i] = aux[i];
    }
}

void cargarNombres(char miArray[][MAXCHAR], int cantidad)
{
    char aux[][MAXCHAR] = {"Alfredo", "Rogelio", "Julieta", "Pablo"};
    int i;

    for (i=0; i<TAM; i++)
    {
        strcpy(miArray[i], aux[i]);
    }
}

void mostrarDatos (char array[][MAXCHAR], int notas[])
{
    int i;
    for (i=0; i<TAM; i++)
    {
        printf("Nombre: %s. Nota: %d\n", array[i], notas[i]);
    }
}

void mostrarResultado (char nombres[][MAXCHAR], int notas[], int i)
{
    printf("La nota mas alta corresponde a %s y es un %d \n",nombres[i],notas[i]);
}

int calcularNotaMax (char* nombres[], int notas[])
{
    int i;
    int notaMax=0;
    int subMax=0;

    for (i=1; i<TAM; i++)
    {
        if(notas[i]>notaMax)
        {
            subMax=i;
            notaMax = notas[i];
        }
    }
    return subMax;
}

