#include <stdio.h>
#include <stdlib.h>

///Tengo que arreglar todas las veces que puse array.

float* newArray ();
float* enlargeArray (float* arrayFloat[]);
void escribirArray (float* arrayFloat[]);
float* leerArray ();
void mostrarArray (float* arrayFloat[],int size);

int main()
{
    int i;
    float* floatArray;
//    float** ppFloat;

    floatArray=newArray();

//    ppFloat=&floatArray[0]+((sizeof(float*)*2));
//    **ppFloat=0.3;
//    ppFloat=&floatArray[0]+(sizeof(float*));
//    **ppFloat=0.2;
//    ppFloat=&floatArray[0];
//    **ppFloat=0.1;

    for(i=2;i>-1;i--)
    {
        *floatArray[i]=0.1;
        printf("%f\n",*floatArray[i]);
    }

    enlargeArray(floatArray);

    escribirArray(floatArray);

    leerArray(floatArray);

    mostrarArray(floatArray,5);

    return 0;
}

float* newArray ()
{
    float *floatArray;

    floatArray=(float*)malloc(sizeof(float)*3);

    return floatArray;
}

float* enlargeArray (float* arrayFloat)
{
    arrayFloat=(float*)realloc(arrayFloat,(sizeof(float)*5));

    return arrayFloat[0];
}

void escribirArray (float* arrayFloat[])
{
    int i;
    FILE* pFile;

    pFile=fopen("arrayFloat.bin","wb");

    for(i=0;i<5;i++)
    {
        fwrite(arrayFloat[i],sizeof(float),1,pFile);
    }

    fclose(pFile);

}

float* leerArray (float* arrayFloat[])
{
    int i;
    FILE* pFile;

    arrayFloat[0]=newArray();
    enlargeArray(arrayFloat);


    pFile=fopen("arrayFloat.bin","rb");

    for(i=0;i<5;i++)
    {
        fread(arrayFloat[i],sizeof(float),1,pFile);
    }

    fclose(pFile);

    return arrayFloat[0];
}

void mostrarArray (float* arrayFloat[],int size)
{
    int i;

    for(i=0;i<size;i++)
    {
        printf("%f\n",*arrayFloat[i]);
    }

}


//Promoción
//Segundo Parcial
//1. Realizar una función que no reciba nada y que defina espacio en memoria dinámica para un array de 3 flotantes. Desde el main cargar dicho array desde el último elemento hacia el primero y mostrar los valores. Deberá utilizar notación de punteros para resolver este punto.
//Pude hacerlo
//No pude hacerlo.
//2. Realizar una función que reciba un array de 3 flotantes y permita generar en memoria dinamica 2 flotantes mas. Desde el main cargar los espacios de memoria restantes y mostrar.
//Pude hacerlo.
//No pude hacerlo.
//3. Crear dos funciones. Una que permita guardar en binario el array generado en el punto 1 y otra que permita leer dichos valores. Mostrar los valores desde el main.
//Pude hacerlo
//No pude hacerlo.
