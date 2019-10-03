#include "Estacionamiento.h"

/*********************************************************************************
*    Realizar las siguientes consultas:
*
*    1.Cada auto con el nombre de su dueño
*    2.Por cada dueño los autos que tiene estacionados.
*    3.Ingresar un dueño y mostrar todos sus autos.
*    4.Mostrar el total de la estadia de cada auto, sabiendo que
*      el valor hora es $100
*    5.Mostrar cuanto debera pagar cada dueño por todos sus autos estacionados
*    6.Mostrar el/los dueños con mas autos estacionados
*
***********************************************************************************/

int main()
{
    int opcion;
    int auxId;
    ePersona persona[LENP];
    eVehiculo vehiculo[LENA];

    hardcodearPersonas(persona,LENP);
    hardcodearVehiculo(vehiculo,LENA);

    do
    {
        system("cls");
        printf("Ingrese la opcion deseada:\n\n1.Cada auto con el nombre de su duenio\n2.Por cada duenio los autos que tiene estacionados.\n3.Ingresar un duenio y mostrar todos sus autos.\n4.Mostrar el total de la estadia de cada auto. Valor hora $100\n5.Mostrar cuanto debera pagar cada duenio por todos sus autos estacionados\n6.Mostrar el/los duenios con mas autos estacionados\n7.Salir.\n\n");
        scanf("%d",&opcion);

        switch (opcion)
        {
        case 1:
            mostrarVehiculosYDuenios(persona,vehiculo,LENP,LENA);
            break;
        case 2:
            system("cls");
            mostrarPersonasYSusVehiculos(persona,vehiculo,LENP,LENA);
            break;
        case 3:
            system("cls");
            printf("Ingrese el ID del titular cuyos vehiculos quiere consultar:\n");
            scanf("%d",&auxId);
            mostrarVehiculoPorID(persona,vehiculo,LENP,LENA,auxId);
            break;
        case 4:
            mostrarTodasLasTarifas(vehiculo,LENA);
            break;
        case 5:
            mostrarTarifaPorDuenio(persona,vehiculo,LENP,LENA);
            break;
        case 6:
            mostrarPersonaConMasAutos(persona,vehiculo,LENP,LENA);
            break;
        case 7:
            break;
        }
    }while (opcion!=7);

    return 0;
}
