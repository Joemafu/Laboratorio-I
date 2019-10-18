#include <stdio.h>
#include <stdlib.h>

/*Escribir  un programa que realice las siguientes acciones
1. Limpie la pantalla
2. Asigne a 2 variables numero1 y numero2 valores distintos de cero
3. Efectœe el producto de dichas variables
4. Muestre el resultado por pantalla
Obtenga el cuadrado de numero1 y lo muestre par pantalla*/


int main(int argc, char *argv[])
{

    int a;
    int b;
    int producto;
    int cuadrado;

    system("clear");

    do
    {
        printf ("\nIngrese un numero: ");
        scanf ("%d", &a);
        printf ("\n______________________________________\n");
    }
    while (a == 0);

    do
    {
        printf ("\nIngrese otro numero: ");
        scanf ("%d", &b);
        printf ("\n______________________________________\n");
    }
    while (b == 0);

    producto = a * b;
    cuadrado = a * a;

    printf ("\nEl valor 1: %d\nEl valor 2: %d\n\nEl producto es: %d\n\nEl cuadrado de valor 1 (%d) es: %d \n", a, b, producto, a, cuadrado);
    printf ("______________________________________\n\n\n\n");

    return 0;
}
