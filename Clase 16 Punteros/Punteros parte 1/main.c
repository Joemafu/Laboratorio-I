#include <stdio.h>
#include <stdlib.h>

int main()
{
    int unEntero=10;
    int* puntero = NULL; ///NULL = no dirección de memoria..
    int* otroPuntero;



    puntero = &unEntero;
//    *puntero = 10;

///Como controlar que el puntero se asigne correctamente.
    if(puntero!=NULL)
    {
        otroPuntero=puntero;
        printf("Ingrese numero: \n");
        scanf("%d", otroPuntero);
//        printf("%d\n", unEntero);
//        printf("%d\n",*puntero);
//        printf("%d\n",&unEntero);
//        printf("%d\n",puntero);
//        printf("%d\n",&puntero);
    }
    else{
        printf("Error.\n");
    }

///Lectura de una variable a través de un puntero.
//    printf("Ingrese numero: \n");
//    scanf("%d", puntero);

    printf("El numero es : %d", *puntero);
    return 0;
}
