#include "Estacionamiento.h"

void cargarPersonas (ePersona persona[],int len)
{
    int i;
    int id[]={1,2,3,4};
    char nombre[][15]={"Maria","Ezequiel","German","Yanina"};
    int dia[]={33,22,25,11};
    int mes[]={3,4,12,11};
    int anio[]={1990,1980,2000,1995};

    for(i=0;i<len;i++)
    {
        persona[i].id=id[i];
        persona[i].fechaNac.dia=dia[i];
        persona[i].fechaNac.mes=mes[i];
        persona[i].fechaNac.anio=anio[i];
        strcpy(persona[i].nombre,nombre[i]);
    }
    return;
}

void mostrarPersona (ePersona persona[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d\t",persona[i].id);
        printf("%s\t",persona[i].nombre);
        printf("%d\t",persona[i].fechaNac.dia);
        printf("%d\t",persona[i].fechaNac.mes);
        printf("%d\n\n",persona[i].fechaNac.anio);
    }
    system("pause");
    return;
}

void cargarVehiculo (eVehiculo vehiculo[], int len)
{
    int i;
    int id[]={1,2,2,4};
    char patente[][15]={"AAA111","BBB222","AA111BB","OJ222BB"};
    int horaEntrada[]={10,9,8,11};
    int horaSalida[]={11,11,11,12};
    int dia[]={26,26,26,26};
    int mes[]={9,9,9,9};
    int anio[]={2019,2019,2019,2019};

    for(i=0;i<len;i++)
    {
        vehiculo[i].idDuenio=id[i];
        vehiculo[i].fechaIngreso.dia=dia[i];
        vehiculo[i].fechaIngreso.mes=mes[i];
        vehiculo[i].fechaIngreso.anio=anio[i];
        vehiculo[i].horaIngreso=horaEntrada[i];
        vehiculo[i].horaSalida=horaSalida[i];
        strcpy(vehiculo[i].patente,patente[i]);
    }
    return;
}

void mostrarVehiculo (eVehiculo vehiculo[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        printf("%d\t",vehiculo[i].idDuenio);
        printf("%s\t",vehiculo[i].patente);
        printf("%d\t",vehiculo[i].fechaIngreso.dia);
        printf("%d\t",vehiculo[i].fechaIngreso.mes);
        printf("%d\t",vehiculo[i].fechaIngreso.anio);
        printf("%d\t",vehiculo[i].horaIngreso);
        printf("%d\t\n\n",vehiculo[i].horaSalida);
    }
    system("pause");
    return;
}

void mostrarVehiculoPorID(ePersona persona[], eVehiculo vehiculo[],int len)
{
    int i;
    int id;

    printf("Ingrese el ID del propietario del/los vehiculo/s a mostrar:\n\n");
    scanf("%d",&id);

    for(i=0;i<len;i++)
    {
        if(id==persona[i].id)
        {
            printf("%d\t",persona[i].id);
            printf("%s\t",persona[i].nombre);
            printf("%d\t",persona[i].fechaNac.dia);
            printf("%d\t",persona[i].fechaNac.mes);
            printf("%d\n\n",persona[i].fechaNac.anio);
        }
        if(id==vehiculo[i].idDuenio)
        {
            printf("%d\t",vehiculo[i].idDuenio);
            printf("%s\t",vehiculo[i].patente);
            printf("%d\t",vehiculo[i].fechaIngreso.dia);
            printf("%d\t",vehiculo[i].fechaIngreso.mes);
            printf("%d\t",vehiculo[i].fechaIngreso.anio);
            printf("%d\t",vehiculo[i].horaIngreso);
            printf("%d\t\n\n",vehiculo[i].horaSalida);
        }
    }
    system("pause");
    return;
}

int buscarIndicePersona(ePersona persona[],int len,int id)
{
    int i;
    for(i=0;i<len;i++)
    {
        if (id==persona[i].id)
        {
            return i;
        }
    }
    return -1;
}

void mostrarVehiculoPorPatente(ePersona persona[], eVehiculo vehiculo[],int len)
{
    int i;
    char patente[8];

    printf("Ingrese la patente del vehiculo a mostrar:\n\n");
    scanf("%s",patente);

    for(i=0;i<len;i++)
    {
        if(stricmp(patente,vehiculo[i].patente)==0)
        {
            printf("%d\t",vehiculo[i].idDuenio);
            printf("%s\t",vehiculo[i].patente);
            printf("%d\t",vehiculo[i].fechaIngreso.dia);
            printf("%d\t",vehiculo[i].fechaIngreso.mes);
            printf("%d\t",vehiculo[i].fechaIngreso.anio);
            printf("%d\t",vehiculo[i].horaIngreso);
            printf("%d\t\n\n",vehiculo[i].horaSalida);

            buscarIndicePersona(persona,len,vehiculo[i].idDuenio);
            printf("%d\t",persona[i].id);
            printf("%s\t",persona[i].nombre);
            printf("%d\t",persona[i].fechaNac.dia);
            printf("%d\t",persona[i].fechaNac.mes);
            printf("%d\n\n",persona[i].fechaNac.anio);
        }
    }
    system("pause");
    return;
}
