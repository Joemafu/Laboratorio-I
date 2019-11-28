#include "persona.h"

ePersona* new_person()
{
    ePersona* myPerson;
//    ePersona* myPerson={100,40,1.87};

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
        printf("%d--%d--%f",unaPersona->file,unaPersona->age,unaPersona->height);
        ret=1;
    }

    deletePersona(unaPersona);
    return ret;
}

void deletePersona(ePersona* unaPersona)
{
    if(unaPersona!=NULL)
    {
        free(unaPersona);
    }
    else
    {
        printf("Error.\n");
    }
}

ePersona* newPersonaParametros(int legajo, int edad, float altura)
{
    ePersona* miPersona = new_person();

    if (miPersona!=NULL)
    {
        miPersona->file=legajo;
        miPersona->age=edad;
        miPersona->height=altura;
    }


    return miPersona;
}
