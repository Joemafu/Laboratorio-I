#include <stdio.h>
#include <stdlib.h>

int main()
{
//    int* pEntero = (int*) malloc(sizeof(int*)+5);
    int* pEntero = (int*) calloc(sizeof(int),5); ///Esto sería lo mismo que el renglon de arriba pero inicializando los valores en 0.
//    int vector[5]={};///inicializa en 0.
    int i;



    free(pEntero); /// libera la memoria reservada por malloc o calloc en este caso, por eso luego imprime basura, puede imprimir algunos datos, pero estos estan en espacios de memoria liberada por lo que no estan seguros.


    for(i=0;i<5;i++)
    {
        printf("%d-",pEntero[i]);
    }


    return 0;
}
