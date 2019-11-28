#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int file;
    char nombre[50];
    int age;
    float height;

}ePersona;

ePersona* new_person(); ///Constructor por defecto.

int mostrarPersona(ePersona*);

void deletePersona(ePersona*);

ePersona* newPersonaParametros(int, int, float);
