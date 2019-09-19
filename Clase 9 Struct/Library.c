#include "Library.h"

void inicializarPersonas(ePersona array[],int cant)
{
    int i;
    for (i=0; i<cant; i++)
    {
        array[i].estaVacio = 1;
    }
    return;
}

void pedirPersona (ePersona array[], int cant)
{
    int i;
    int j;
    int flagSuccess = 0;
    int auxDNI;

    for (i=0; i<cant; i++)
    {
        for(j=0; j<CANT; j++)
        {
            if(array[j].estaVacio==1)
            {
                printf("Ingrese DNI:\n");
                scanf("%d",&auxDNI);
                //scanf("%d",&array[j].DNI);
                fflush(stdin);

                while((validarDNI(array,CANT,auxDNI))== 1)
                {
                    printf("El DNI ingresado ya existe, ingrese otro:\n");
                    scanf("%d", &auxDNI);
                    fflush(stdin);
                    system("cls");
                }

                array[j].DNI=auxDNI;
                printf("Ingrese nombre:\n");
                gets(array[j].nombre);
                fflush(stdin);

                printf("Ingrese apellido:\n");
                gets(array[j].apellido);
                fflush(stdin);

                array[j].estaVacio=0;
                flagSuccess=1;
                break;
            }
        }
    }
    if (flagSuccess==0)
    {
        system("cls");
        printf("No se puede cargar la persona. No hay lugar disponible.\n");
        system("pause");
    }
    return;
}

int validarDNI (ePersona array[], int cant, int aux)
{
    int i;

    for(i=0;i<cant;i++)
    {
        if(array[i].DNI==aux)
        {
            return 1;
        }
    }
    return 0;
}

void mostrarPersona (ePersona persona[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(persona[i].estaVacio==0)
        {
            printf("%s\n%s\n%d\n\n",persona[i].nombre, persona[i].apellido,persona[i].DNI);
        }
    }
    system("pause");
    return;
}

void ordenarPorDNI(ePersona array[],int cant)
{
    int i;
    int j;
    ePersona aux;

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if (array[j].DNI<array[i].DNI)
            {
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}

void ordenarPorApellido(ePersona array[],int cant)
{
    int i;
    int j;
    ePersona aux;

    for(i=0;i<cant-1;i++)
    {
        for(j=i+1;j<cant;j++)
        {
            if (array[j].apellido[0]<array[i].apellido[0])///verificar condicional, así no se compara un string //Actualización, le agregué subíndices a .apellido[], pero esto solo los ordena por inicial.
            {
                aux = array[j];
                array[j] = array[i];
                array[i] = aux;
            }
        }
    }
}
