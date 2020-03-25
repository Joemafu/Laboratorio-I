/***********************************************************************************************************

1) Desarrollar una biblioteca "utn.h" que posea funciones para pedirle al usuario el ingreso de datos

getInt()
getFloat()
getChar()

2) Diseñar un programa para jugar a adivinar un número entre 0 y 100. El juego tiene que dar pistas de si
el número introducido por el jugador está por encima o por debajo. El juego termina cuando se adivina el
número o se decide terminar de jugar ingresando un número negativo. Permitir jugar tantas veces como lo
desee el jugador y al salir mostrar su mejor puntuación. Utilizar la biblioteca del punto 1.

************************************************************************************************************/

#include "utn.h"

int main()
{
    int numeroOculto;
    int numeroUsuario;
    int continuar=1;
    int nuevaPartida=1;
    int intentos=0;
    int recordIntentos=0;

    numeroOculto=randomizarNumero(1,100,1);

    while(nuevaPartida)
    {
        do
        {
            intentos++;
            numeroUsuario=getInt("Ingrese un numero: ");
            if(numeroUsuario>numeroOculto)
            {
                printf("Numero muy alto.\n");
            }
            else if (numeroUsuario<numeroOculto)
            {
                printf("Numero muy bajo.\n");

            }
            else if (numeroUsuario==numeroOculto)
            {
                printf("Felicidades, acertaste!\n");
                continuar=0;
                if(recordIntentos>intentos)
                {
                    recordIntentos=intentos;
                    intentos=0;
                }
            }
            else if(numeroUsuario<0)
            {
                continuar=0;
                intentos=0;
            }

            if(continuar==0)
            {
                if(getChar("Quiere comenzar una nueva partida? (s/n) \n")!='s')
                {
                    nuevaPartida=0;
                }
            }

        }
        while (continuar);

    }
    if(recordIntentos>0)
    {
        printf("Su record fue adivinar el numero en %d intentos. Hasta luego!\n",recordIntentos);
    }

    return 0;
}
