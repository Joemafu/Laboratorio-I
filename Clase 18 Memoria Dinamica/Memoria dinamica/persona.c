#include "persona.h"

ePersona* new_person()
{
    ePersona* myPerson;///={100,40,1.87};

    myPerson=malloc(sizeof (ePersona));

    myPerson->file=100;
    myPerson->age=40;
    myPerson->height=1.87;

    return myPerson;
}

int mostrarPersona (ePersona* unaPersona)
{
    int ret=-1;
    if(unaPersona!=NULL)
    {
            printf("%d--%d--%f",ePersona->file,ePersona->age,ePersona->height);
    }

    deletePersona(unaPersona)
}

int deletePersona(ePersona*);
{
    int ret=-1;
    if(unaPersona!=NULL)
    {
            free(unaPersona*);
    }
    else
}

ePersona* newPersonaParametros(int legajo, int edad, float altura)
{
    ePersona* miPersona = new_Person();

    if (miPersona!=NULL)
    {
        miPersona->file=legajo;
        miPersona->age=edad;
        miPersona->height=altura;
    }


    return miPersona;
}
