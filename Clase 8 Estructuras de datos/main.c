#include "alumno.h"

int main()
{
//  ealumno nuevoAlumno = {1000,"pepe",7};
    /*  eAlumno otroAlumno;     */               /**< Puedo copiar los valores de una variable estructura a otra. */
//  otroAlumno=nuevoAlumno;

    /*  eAlumno miAlumno;
        eAlumno otroAlumno;
        miAlumno=pedirAlumno();
        otroAlumno=pedirAlumno();
        mostrarAlumno(miAlumno);
        mostrarAlumno(otroAlumno);

        if (compararAlumnosPorLegajo(miAlumno, otroAlumno))
        {
            printf("Los legajos de los alumnos son iguales.\n");
        }
        else
        {
            printf("Los legajos de los alumnos no son iguales.\n");
        }
    */
    eAlumno listaDeAlumnos[A];
    int opcion;
    int index;
    int legajo;

    if (inicializarAlumnos(listaDeAlumnos, A)!=-1)
    {
        do
        {
            printf("1)Cargar alumnos.\n2)Mostrar alumnos.\n3)Ordenar por Nombre.\n4)Mostrar alumno por legajo.\n5)Borrar alumno.\n6)Salir.\n");
            scanf("%d", &opcion);
            system("cls");

            switch (opcion)
            {
            case 1:
                hardcodearAlumnos(listaDeAlumnos,A);//cargarAlumnos(listaDeAlumnos,A);
                break;
            case 2:
                mostrarListaDeAlumnos(listaDeAlumnos,A);
                system("pause");
                system("cls");
                break;
            case 3:
                ordenarAlumnosPorNombre(listaDeAlumnos,A);
                break;
            case 4:
                printf("Ingrese legajo del alumno a mostrar:\n");
                scanf("%d", &legajo);
                fflush(stdin);
                system("cls");
                index=buscarAlumnoPorLegajo(listaDeAlumnos,A,legajo);
                mostrarAlumno(listaDeAlumnos[index]);
                system("pause");
                system("cls");
                break;
            case 5:
                switch(borrarAlumno(listaDeAlumnos,A))
                {
                case 0:

                    printf("Se borro al alumno.\n");

                case 1:

                    printf("Accion cancelada\n");

                case -1:

                    printf("No se encontro el legajo indicado.\n");
                }
                break;
            case 6:                                                     ///AGREGAR MODIFICACIONES.
                break;
            default:
                printf("Opcion incorrecta.\n");
            }
        }
        while (opcion!=6);
    }
    else
    {
        printf("Error");
    }

    return 0;
}
