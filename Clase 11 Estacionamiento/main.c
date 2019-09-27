#include "Estacionamiento.h"

int main()
{
    int opcion;
    ePersona persona[LENP];
    eVehiculo vehiculo[LENA];

    cargarPersonas(persona,LENP);
    cargarVehiculo(vehiculo,LENA);

    do
    {
        system("cls");
        printf("Ingrese la opcion deseada:\n\n1)Mostrar Personas.\n2)Mostrar vehiculos.\n3)Mostrar vehiculo por ID.\n4)Mostrar vehiculo por patente.\n5)Salir.\n\n");
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            mostrarPersona(persona,LENP);
            break;
        case 2:
            mostrarVehiculo(vehiculo,LENA);
            break;
        case 3:
            mostrarVehiculoPorID(persona,vehiculo,LENA);
            break;
        case 4:
            mostrarVehiculoPorPatente(persona,vehiculo,LENA);
            break;
        case 5:
            break;
        }
    }while (opcion!=5);

    return 0;
}
