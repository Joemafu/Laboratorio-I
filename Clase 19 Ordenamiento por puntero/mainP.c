///NO FUNCIONA, REVISAR

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int id;
    int orden;
    char apellido[];
}ePersona;

void inicializar(ePersona*, int);
void mostrar(ePersona*, int);
void ordenar(ePersona*, int);
void swap(ePersona*, ePersona*);
void hardcodear(ePersona*, int);
void pedirDatos(ePersona*, int);

int main()
{
    int pos;
    ePersona persona[50];
    char opcion;
    inicializar(persona,50);
    pos=11;
    hardcodear(persona,50);

    do
    {
        pedirDatos(persona,pos);

        pos++;
        printf("\nIngresa Otro?");
        fflush(stdin);
        gets(&opcion);
    }
    while(opcion=='s');

    ordenar(persona,50);
    mostrar(persona,50);

    return 0;
}

void inicializar(ePersona* array, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        (array+i)->orden=-1;
    }
}

void mostrar(ePersona* array, int tam)
{
    int i=0;

    for(i=0;i<tam;i++)
    {
        if((array+i)->orden!=-1)
        {
            printf("%d-%d-%s-\n ", (array+i)->id, (array+i)->orden, (array+i)->apellido);
        }
    }
}

void ordenar(ePersona* array, int tam)
{
    int i=0;
    int j=0;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if((array+i)->orden>(array+j)->orden)
            {
                swap(array+i,array+j);
            }
        }
    }
}

void swap(ePersona* a, ePersona* b)
{
    ePersona c;
    c=*a;
    *a=*b;
    *b=c;
}

void hardcodear(ePersona* persona, int len)
{
    int i;
    int j=0;
    int id[10]={1,2,3,4,5,6,7,8,9,10};
    int orden[10]={5,6,8,7,9,1,2,3,4,10};
    char apellido[10][50]={"gomez","gonzalez","perez","gutierrez","garcia","gimenez","perez","muñoz","lezama","martinez",};

    for(i=0;i<10;i++)
    {
        (persona+i)->id=id[j];
        (persona+i)->orden=orden[j];
        strcpy((persona+i)->apellido,apellido[j]);
        j++;
    }
}

void pedirDatos(ePersona* per, int id)
{
    system("cls");
    printf("Ingrese el Apellido: \n");
    fflush(stdin);
    gets(per->apellido);
    printf("Ingrese el Orden: \n");
    scanf("%d", &(per->orden));
    per->id=id;
}
