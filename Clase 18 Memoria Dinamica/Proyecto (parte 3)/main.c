#include <stdio.h>
#include <stdlib.h>

int main()
{
///    int*pEntero = (int*) malloc(sixeof(int*)+5);
    int* pEntero = (int*) calloc(sizeof(int),5); ///Esto sería lo mismo que el renglon de arriba pero inicializando los valores en 0.
//    int vector[5]={};///inicializa en 0.
    int i;



    free(pEntero);


    for(i=0;i<5;i++)
    {
        printf("%d-",pEntero[i]);

    }


    return 0;
}
