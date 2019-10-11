#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct
{
    int a;
    float b;
    char c;
}eDato;

void cargarDatos(eDato*, int);
void mostrarDatos(eDato*, int);

int main()
{
    eDato unDato[2];///={{2,3.26,'C'},{1,5.3,'B'}};

    cargarDatos(unDato,2);
    mostrarDatos(unDato,2);

    return 0;

//    eDato unDato={1,5.3,'B'};
//    eDato* pDato;
//
//    pDato = &unDato;
//
//    printf("%d--%.1f--%c",(*pDato).a,(*pDato).b,(*pDato).c); ///Parentesis otorgan prioridad al operador de inacceso.
//
//    return 0;
}

void cargarDatos(eDato* listaDatos, int tam)
{
    int i;

        for(i=0;i<tam;i++)
    {
        printf("Ingrese entero\n");
        scanf("%d",&(listaDatos+i)->a);
        printf("Ingrese flotante\n");
        scanf("%f",&(listaDatos+i)->b);
        printf("Ingrese caracter\n");
        fflush(stdin);
        (listaDatos+i)->c=getche();
        printf("\n");
    }
}

void mostrarDatos(eDato* listaDatos, int tam)
{
    int i;

    for(i=0;i<tam;i++)
    {
        ///Parentesis otorgan prioridad al operador de inacceso. "& Operador de dirección" "* Operador de indireccion o inacceso"
        printf("%d--%.2f--%c\n",(listaDatos+i)->a,(listaDatos+i)->b,(listaDatos+i)->c);///printf("%d--%.2f--%c\n",(*(pDato+i)).a,(*(pDato+i)).b,(*(pDato+i)).c);
        ///Suprimo asterisco y punto y pongo flechita.
    }
}
