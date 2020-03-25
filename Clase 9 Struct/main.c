#include "Library.h"

int main()
{

    int opcion;
    ePersona persona[CANT];


    do
    {
        system("cls");
        printf("Ingrese una opcion:\n\n1)Inicializar personas/Eliminar todas.\n2)Cargar persona.\n3)Mostrar personas cargadas.\n4)Ordenar por DNI.\n5)Ordenar por apellido.\n6)Salir.\n\n");
        fflush(stdin);
        scanf("%d", &opcion);

        system("cls");

        switch (opcion)
        {
            case 1:
            {
                inicializarPersonas(persona,CANT);
                break;
            }
            case 2:
            {
                pedirPersona(persona,1);
                break;
            }
            case 3:
            {
                mostrarPersona(persona,CANT);
                break;
            }
            case 4:
            {
                ordenarPorDNI(persona,CANT);
                mostrarPersona(persona,CANT);
            }
            case 5:
            {
                ordenarPorApellido(persona,CANT);
                mostrarPersona(persona,CANT);
                break;
            }
            case 6:
            {
                break;
            }
            default:
            {
                system("cls");
                printf("Ingrese un numero de opcion valida.\n");
                system("pause");
            }
        }
    }
    while (opcion!=6);
    return 0;
}
