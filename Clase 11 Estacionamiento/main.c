#include "Estacionamiento.h"

int main()
{
    int opcion;
    ePersona persona[LEN];
    eVehiculo vehiculo[LEN];

    do
    {
        system("cls");
        printf("Ingrese la opcion deseada:\n\n1)Cargar personas.\n2)Mostrar Personas.\n3)Cargar vehiculos.\n4)Mostrar vehiculos.\n5)Mostrar vehiculo por ID.\n6)Mostrar vehiculo por patente.\n7)Salir.\n\n");
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            cargarPersonas(persona,LEN);
            break;
        case 2:
            mostrarPersona(persona,LEN);
            break;
        case 3:
            cargarVehiculo(vehiculo,LEN);
            break;
        case 4:
            mostrarVehiculo(vehiculo,LEN);
            break;
        case 5:
            mostrarVehiculoPorID(persona,vehiculo,LEN);
            break;
        case 6:
            mostrarVehiculoPorPatente(persona,vehiculo,LEN);
            break;
        case 7:
            break;
        }
    }while (opcion!=6);

    return 0;
}
