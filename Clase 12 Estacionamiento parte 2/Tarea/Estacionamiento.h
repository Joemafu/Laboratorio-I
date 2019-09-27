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
    int idPropietario;
    char nombre[51];
    eFecha fechaNac;
}ePersona;

typedef struct
{
    char patente[8];
    eFecha fechaIngreso;
    int horaIngreso;
    int horaSalida;
    int idPropietario;
}eVehiculo;

void hardcodearPersonas(ePersona*,int);

void hardcodearVehiculo(eVehiculo*,int);



//void mostrarPersonas (ePersona*,int);

int buscarIndicePersona(ePersona*,int,int);

void mostrarPersonaPorIndice (ePersona*,int);

//void mostrarPersonaPorID (ePersona*,int,int);



void mostrarVehiculoPorIndice(eVehiculo*,int);

void mostrarVehiculoPorID(ePersona*,eVehiculo*,int,int,int);

//void mostrarVehiculoPorPatente(ePersona*, eVehiculo*,int,int);

int calcularTarifaAuto(eVehiculo*,int,int);

void mostrarTodasLasTarifas (eVehiculo*, int);


void mostrarTarifaPorDuenio (ePersona*,eVehiculo*,int,int);

void mostrarPersonasYSusVehiculos (ePersona*, eVehiculo*, int, int);

void mostrarVehiculosYDuenios(ePersona*,eVehiculo*,int,int);

void mostrarPersonaConMasAutos(ePersona*,eVehiculo*,int,int);


void printSeparation();
void printTabP();
void printTabA();


///ordenarPorPatente
///ordenarPorNombreDuenio
