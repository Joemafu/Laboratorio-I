#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4
#define MAXCHAR 50

void cargarConDatosEnteros(int[], int);
void cargarNombres(char[][MAXCHAR], int);
void mostrarResultado (char[MAXCHAR], int);
void mostrarDatos (char[][MAXCHAR], int[]);

int main()
{
    int notas [TAM];
    char nombres [TAM][MAXCHAR];
    int i;
    int notaMax;
    char nombreNotaMax[MAXCHAR];

    cargarConDatosEnteros(notas, TAM);
    cargarNombres(nombres, TAM);
    mostrarDatos(nombres,notas);

    notaMax = notas[0];
    strcpy(nombreNotaMax, nombres[0]);

    //MUDAR ESTO A FUNCION
    for (i=0;i<TAM;i++){
        if(notas[i]>notaMax)
        {
            notaMax = notas[i];
            strcpy(nombreNotaMax, nombres[i]);
        }
    }
    mostrarResultado(nombreNotaMax,notaMax);

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
    char aux[][MAXCHAR] ={"Alfredo", "Rogelio", "Julieta", "Pablo"};
    int i;

    for (i=0;i<TAM;i++){
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
void mostrarResultado (char notaMasAlta[MAXCHAR], int nota)
{
    printf("La nota mas alta corresponde a %s y es un %d \n",notaMasAlta,nota);
}
void devolverElNombreDelMaximo (int arrayPalabras[][MAXCHAR],int arrayNumeros[],int cantidad)
{
    //int i;
    //int indice;
    /**< CREAR ESTA FUNCION (MOSTRAR MAXIMO Y NOMBRE A TRAVES DE SUBINDICE)*/
    //indice=devolverElIndiceDelMaximo(array,cantidad);
    //arrayPalabras[indice];
}
