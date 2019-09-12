#include "Array.h"

int main()
{
    int cantidadSubindices = 6;
    int listadoDeEdades[cantidadSubindices];

    inicializarArray(listadoDeEdades, cantidadSubindices);
    cargaSecuencialArray(listadoDeEdades, cantidadSubindices, "Ingrese edad.\n");
    mostrarArray(listadoDeEdades, cantidadSubindices);
    mostrarMaximo(listadoDeEdades, cantidadSubindices);
    promediarArray(listadoDeEdades, cantidadSubindices);
    ordenarArray (listadoDeEdades, cantidadSubindices);

    return 0;
}
