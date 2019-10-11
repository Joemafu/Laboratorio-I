#include <stdio.h>
#include <stdlib.h>

void cargarVector (int*,int);
void mostrarVector (int* vector, int tam);
void incrementarID(int*);

int main()
{
    int contID=0;
    int vector[5];///={5,7,8,9,3};

    cargarVector(vector,5);
    mostrarVector(vector,5);

    incrementarID(&contID);
    printf("Siguiente ID: %d\n",contID);
    incrementarID(&contID);
    printf("Siguiente ID: %d\n",contID);
    incrementarID(&contID);
    printf("Siguiente ID: %d\n",contID);


///--------------------------------------------------PARTE 2--------------------------------------------------------

//    int unEntero;
//    int* puntero;
//
//    puntero = &unEntero;
//
//    printf("%p\n", puntero);/// %p para entero en formato hexadecimal(soluciona los warnings de %d).
//    printf("%p\n", puntero+0);
//    printf("%p\n", puntero+1);/// suman de a 4 que son los bytes que ocupa cada puntero en memoria.
//    printf("%p\n", puntero+2);
//    printf("%p\n", puntero+3);
//
//
//    puntero = puntero +1;
//    system("pause");
//    printf("p%\n", puntero);
//
//
/////    printf("%d", sizeof(char*)); ///para saberel tamaño de una variable (reemplazar char* por int, float, double, o lo que se quiera averiguar.


    return 0;
}


void cargarVector (int* vector,int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", vector+i);
    }
}

void mostrarVector (int* vector, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        printf("%d\n", *(vector+i));///los parentesis separan al asterisco porque este tiene prioridad sobre el simbolo de suma.
    }
}

void incrementarID(int* id)
{
    *id=*id+1;
}
