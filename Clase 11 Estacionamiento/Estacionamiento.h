#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENP 4
#define LENA 10

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int id;
    char nombre[51];
    eFecha fechaNac;
}ePersona;

typedef struct
{
    char patente[8];
    eFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idDuenio;
}eVehiculo;

void cargarPersonas (ePersona*,int);

void mostrarPersona (ePersona*,int);

void cargarVehiculo (eVehiculo*,int);

void mostrarVehiculo(eVehiculo*,int);

void mostrarVehiculoPorID(ePersona*,eVehiculo*,int);

int buscarIndicePersona(ePersona*,int,int);

void mostrarVehiculoPorPatente(ePersona*, eVehiculo*,int);

///ordenarPorPatente
///ordenarPorNombreDuenio
