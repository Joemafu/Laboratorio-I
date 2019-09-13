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

    do
    {
        printf("1)Cargar alumnos.\n2)Mostrar alumnos.\n3)Ordenar por Nombre.\n4)Salir.\n");
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
            break;
        default:
            printf("Opcion incorrecta.\n");
        }

    }
    while (opcion!=4);



    return 0;
}
