#include "utn.h"

char randomizarNumero(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand (time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}

int getInt (char* mensaje)
{
    int ret;
    printf(mensaje);
    scanf("%d",&ret);

    return ret;
}

float getFloat (char* mensaje)
{
    float ret;
    printf(mensaje);
    scanf("%f",&ret);

    return ret;
}

char getChar (char* mensaje)
{
    char ret;
    printf(mensaje);
    fflush(stdin);
    scanf("%c",&ret);

    return ret;
}
