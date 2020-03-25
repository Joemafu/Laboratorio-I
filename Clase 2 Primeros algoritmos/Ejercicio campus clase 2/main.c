#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int num;
    int acumulador=0;
    int contador=0;
    int maximo;
    int minimo;
    float promedio;

    for(i=0;i<5;i++)
    {
        printf("Ingrese un numero\n");
        fflush(stdin);
        scanf("%d",&num);
        acumulador+=num;
        if(contador==0 || num>maximo)
        {
            maximo=num;
        }
        if(contador==0 || num<minimo)
        {
            minimo=num;
        }
        contador++;
    }
    promedio = (float)acumulador/contador;
    printf("El promedio ingresado es de %.1f, el maximo fue %d y el minimo fue %d.",promedio,maximo,minimo);

    return 0;
}
