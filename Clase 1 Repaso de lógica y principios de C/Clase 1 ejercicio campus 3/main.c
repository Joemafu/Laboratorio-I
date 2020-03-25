#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int num;
    int contP;
    int contN;

    contP=0;
    contN=0;

    for(i=0;i<10;i++)
    {
        printf("Ingrese un numero:\n");
        scanf("%d",&num);

        if (num>=0)
        {
            contP++;
        }else
        {
            contN++;
        }
    }


    printf("Se ingresaron %d numeros positivos y %d numeros negativos.",contP,contN);

    return 0;
}
