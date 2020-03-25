#include <stdio.h>
#include <stdlib.h>

int getInt(char* mensaje);

int main()
{
    int numeros[5];
    int i;
    int opcion;
    int posicion;
    int acumulador;
    int max;
    int min;
    float promedio;

    for(i=0;i<5;i++)
    {
        numeros[i]=getInt("Ingrese un numero: ");
        if(i==0||min>numeros[i])
        {
            min=numeros[i];

        }
        if(i==0||min<numeros[i])
        {
            max=numeros[i];
        }
    }

    do
    {
        system("cls");
        printf("Menu:\n\n1)Modificar numeros ingresados.\n2)Mostrar resultados.\n3)Salir.\n\n");
        opcion=getInt("Ingrese una opcion: ");

        switch(opcion)
        {
        case 1:
            posicion=getInt("Indique la posicion del numero a modificar:");

            posicion--;
            numeros[posicion]=getInt("Ingrese nuevo valor para la posicion elegida");
            break;
        case 2:
            acumulador=0;
            system("cls");
            for(i=0;i<5;i++)
            {
                acumulador+=numeros[i];
                printf("acumulador = %d\n",acumulador);
                printf("%d\n",numeros[i]);
            }
            promedio=(float)acumulador/5;
            printf("El numero maximo ingresado es %d\n", max);
            printf("El numero minimo ingresado es %d\n", min);
            printf("El promedio de numeros ingresados es %f\n", promedio);

            system("pause");

            break;
        case 3:
            break;
        }

    }while (opcion!=3);

    return 0;
}

int getInt(char* mensaje)
{
    int ret;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&ret);

    return ret;
}
