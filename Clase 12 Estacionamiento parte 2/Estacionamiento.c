#include "Estacionamiento.h"

void hardcodearPersonas (ePersona persona[],int len)
{
    int i;
    int id[]={100,101,105,106};
    char nombre[][51]={"Maria","Ezequiel","German","Yanina"};
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

void hardcodearVehiculo (eVehiculo vehiculo[], int len)
{
    int i;
    int id[]={101,106,100,106,101,101,100,105,106,106};
    char patente[][15]={"AAA111", "BBB222", "AAA222","WWW777","AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"};
    int horaEntrada[]={10,9,8,11,10,11,9,7,7,14};
    int horaSalida[]={11,11,11,12,14,15,12,10,11,17};
    int dia[]={26,26,26,26,26,26,26,26,26,26};
    int mes[]={9,9,9,9,9,9,9,9,9,9};
    int anio[]={2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};

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

void mostrarPersonas (ePersona persona[], int len)
{
    int i;
    system("cls");
    printf("Datos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
    for(i=0;i<len;i++)
    {
        printf("%04d\t",persona[i].id);
        printf("%15s\t\t",persona[i].nombre);
        printf("%02d\t",persona[i].fechaNac.dia);
        printf("%02d\t",persona[i].fechaNac.mes);
        printf("%4d\n\n",persona[i].fechaNac.anio);
    }
    system("pause");
    return;
}

void mostrarPersonaPorID (ePersona persona[], int len,int id)
{
    int i;
    system("cls");
    printf("Datos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
    for(i=0;i<len;i++)
    {
        if(id==persona[i].id)
        {
            printf("%04d\t",persona[i].id);
            printf("%15s\t\t",persona[i].nombre);
            printf("%02d\t",persona[i].fechaNac.dia);
            printf("%02d\t",persona[i].fechaNac.mes);
            printf("%4d\n\n",persona[i].fechaNac.anio);
            break;
        }
    }
    system("pause");
    return;
}

void mostrarPersonasYSusVehiculos (ePersona persona[], eVehiculo vehiculo[],int lenp,int lena)
{
    int i;
    system("cls");

    for(i=0;i<lenp;i++)
    {
        printf("\n----------------------------------------------------\n\nDatos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
        mostrarPersonaPorID(persona,lenp,persona[i].id);
        mostrarVehiculoPorID(persona,vehiculo,lenp,lena,persona[i].id);
    }
    system("pause");
    return;
}

void mostrarVehiculoPorIndice (eVehiculo vehiculo[], int lena, int i)
{
    printf("Datos del vehiculo:\n\nID \tPatente\t\tDia\tMes\tAnio\tHora ing.\tHora egr.\n");

    printf("%04d\t",vehiculo[i].idDuenio);
    printf("%8s\t",vehiculo[i].patente);
    printf("%02d\t",vehiculo[i].fechaIngreso.dia);
    printf("%02d\t",vehiculo[i].fechaIngreso.mes);
    printf("%4d\t",vehiculo[i].fechaIngreso.anio);
    printf("%02d\t\t",vehiculo[i].horaIngreso);
    printf("%02d\t\n\n",vehiculo[i].horaSalida);

    return;
}

void mostrarVehiculoPorID(ePersona persona[], eVehiculo vehiculo[],int lenp,int lena,int id)
{
    int i;

    mostrarPersonaPorID(persona,lenp,id);
    printf("\nDatos del vehiculo:\n\nID \tPatente\t\tDia\tMes\tAnio\tHora ing.\tHora egr.\n");

    for(i=0;i<lena;i++)
    {
        if(id==vehiculo[i].idDuenio)
        {
            printf("%04d\t",vehiculo[i].idDuenio);
            printf("%8s\t",vehiculo[i].patente);
            printf("%02d\t",vehiculo[i].fechaIngreso.dia);
            printf("%02d\t",vehiculo[i].fechaIngreso.mes);
            printf("%4d\t",vehiculo[i].fechaIngreso.anio);
            printf("%02d\t\t",vehiculo[i].horaIngreso);
            printf("%02d\t\n\n",vehiculo[i].horaSalida);
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
    system("cls");

    for(i=0;i<len;i++)
    {
        if(stricmp(patente,vehiculo[i].patente)==0)
        {
            printf("Datos del vehiculo:\n\nID \tPat.\tDia\tMes\tAnio\tHora ing.\tHora egr.\n");
            printf("%04d\t",vehiculo[i].idDuenio);
            printf("%s\t",vehiculo[i].patente);
            printf("%02d\t",vehiculo[i].fechaIngreso.dia);
            printf("%02d\t",vehiculo[i].fechaIngreso.mes);
            printf("%4d\t",vehiculo[i].fechaIngreso.anio);
            printf("%02d\t\t",vehiculo[i].horaIngreso);
            printf("%02d\t\n\n\n",vehiculo[i].horaSalida);

            i=buscarIndicePersona(persona,len,vehiculo[i].idDuenio);
            printf("Datos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
            printf("%04d",persona[i].id);
            printf("%15s\t\t",persona[i].nombre);
            printf("%02d\t",persona[i].fechaNac.dia);
            printf("%02d\t",persona[i].fechaNac.mes);
            printf("%4d\n\n",persona[i].fechaNac.anio);
            break;
        }
    }
    system("pause");
    return;
}

//int buscarVehiculoPor

int calcularTarifaAuto(eVehiculo vehiculo[],int lena,int index)
{
    int tarifa;

    tarifa=(vehiculo[index].horaSalida-vehiculo[index].horaIngreso)*100;

    return tarifa;
}

void mostrarTodasLasTarifas (eVehiculo vehiculo[], int lena)
{
    int i;
    int total;

    system("cls");
    for(i=0;i<lena;i++)
    {
        mostrarVehiculoPorIndice(vehiculo, lena, i);
        total=calcularTarifaAuto(vehiculo,lena,i);
        printf("Debe pagar $%d\n\n-----------------------------------------------------------------------------\n",total);
    }
    system("pause");
    return;
}
