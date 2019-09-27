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

void hardcodearPersonas(ePersona*,int);

void hardcodearVehiculo(eVehiculo*,int);

void mostrarPersonas (ePersona*,int);

void mostrarVehiculoPorIndice(eVehiculo*,int,int);

void mostrarVehiculoPorID(ePersona*,eVehiculo*,int,int,int);

int buscarIndicePersona(ePersona*,int,int);

void mostrarVehiculoPorPatente(ePersona*, eVehiculo*,int);

void mostrarPersonasYSusVehiculos (ePersona*, eVehiculo*, int, int);

void mostrarPersonaPorID (ePersona*,int,int);

int calcularTarifaAuto(eVehiculo*,int,int);

void mostrarTodasLasTarifas (eVehiculo*, int);

///ordenarPorPatente
///ordenarPorNombreDuenio
