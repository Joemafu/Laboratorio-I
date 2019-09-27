#include "Estacionamiento.h"

void hardcodearPersonas (ePersona persona[],int lenP)
{
    int i;
    int id[]={100,101,105,106};
    char nombre[][51]={"Maria","Ezequiel","German","Yanina"};
    int dia[]={33,22,25,11};
    int mes[]={3,4,12,11};
    int anio[]={1990,1980,2000,1995};

    for(i=0;i<lenP;i++)
    {
        persona[i].idPropietario=id[i];
        persona[i].fechaNac.dia=dia[i];
        persona[i].fechaNac.mes=mes[i];
        persona[i].fechaNac.anio=anio[i];
        strcpy(persona[i].nombre,nombre[i]);
    }
    return;
}

void hardcodearVehiculo (eVehiculo vehiculo[], int lenA)
{
    int i;
    int id[]={101,106,100,106,101,101,100,105,106,106};
    char patente[][15]={"AAA111", "BBB222", "AAA222","WWW777","AKK222","EEE111","UUU777","YYY778","ABC123","QQQ128"};
    int horaEntrada[]={10,9,8,11,10,11,9,7,7,14};
    int horaSalida[]={11,11,11,12,14,15,12,10,11,17};
    int dia[]={26,26,26,26,26,26,26,26,26,26};
    int mes[]={9,9,9,9,9,9,9,9,9,9};
    int anio[]={2019,2019,2019,2019,2019,2019,2019,2019,2019,2019};

    for(i=0;i<lenA;i++)
    {
        vehiculo[i].idPropietario=id[i];
        vehiculo[i].fechaIngreso.dia=dia[i];
        vehiculo[i].fechaIngreso.mes=mes[i];
        vehiculo[i].fechaIngreso.anio=anio[i];
        vehiculo[i].horaIngreso=horaEntrada[i];
        vehiculo[i].horaSalida=horaSalida[i];
        strcpy(vehiculo[i].patente,patente[i]);
    }
    return;
}

///Funciona pero no se utiliza.-
//void mostrarPersonas (ePersona persona[], int lenP)
//{
//    int i;
//    system("cls");
//    printf("Datos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
//    for(i=0;i<lenP;i++)
//    {
//        mostrarPersonaPorIndice(persona,i);
//    }
//    system("pause");
//    return;
//}

void mostrarPersonaPorIndice (ePersona persona[], int i)
{
    printf("%04d\t",persona[i].idPropietario);
    printf("%14s\t\t",persona[i].nombre);
    printf("%02d/",persona[i].fechaNac.dia);
    printf("%02d/",persona[i].fechaNac.mes);
    printf("%4d\n\n",persona[i].fechaNac.anio);
    return;
}

///Funciona pero no se utiliza.-
//void mostrarPersonaPorID (ePersona persona[], int lenP,int id)
//{
//    int i;
//    i=buscarIndicePersona(persona,lenP,id);
//    mostrarPersonaPorIndice(persona,i);
//    return;
//}

void mostrarPersonasYSusVehiculos (ePersona persona[], eVehiculo vehiculo[],int lenP,int lenA)
{
    int i;
    int j;
    for(i=0;i<lenP;i++)
    {
        printTabP();
        mostrarPersonaPorIndice(persona,i);
        printTabA();
        for(j=0;j<lenA;j++)
        {
            if(persona[i].idPropietario==vehiculo[j].idPropietario)
            {
                mostrarVehiculoPorIndice(vehiculo,j);
            }
        }
        printSeparation();
    }
    system("pause");
    return;
}

void mostrarVehiculoPorIndice (eVehiculo vehiculo[], int i)
{
    printf("%04d\t",vehiculo[i].idPropietario);
    printf("%8s\t",vehiculo[i].patente);
    printf("%02d/",vehiculo[i].fechaIngreso.dia);
    printf("%02d/",vehiculo[i].fechaIngreso.mes);
    printf("%4d\t\t",vehiculo[i].fechaIngreso.anio);
    printf("%02d:00\t\t",vehiculo[i].horaIngreso);
    printf("%02d:00\t\n\n",vehiculo[i].horaSalida);
    return;
}

void mostrarVehiculoPorID(ePersona persona[], eVehiculo vehiculo[],int lenP,int lenA,int id)
{
    int i;
    int j;
    i=buscarIndicePersona(persona,lenP,id);
    printTabP();
    mostrarPersonaPorIndice(persona,i);
    printTabA();
    for(j=0;j<lenA;j++)
    {
        if(vehiculo[j].idPropietario==id)
        {
            mostrarVehiculoPorIndice(vehiculo,j);
        }
    }
    system("pause");
    return;
}

int buscarIndicePersona(ePersona persona[],int lenP,int id)
{
    int i;
    for(i=0;i<lenP;i++)
    {
        if (id==persona[i].idPropietario)
        {
            return i;
        }
    }
    return -1;
}

///Funciona pero no se utiliza.-
//void mostrarVehiculoPorPatente(ePersona persona[], eVehiculo vehiculo[],int lenP,int lenA)
//{
//    int i;
//    char patente[8];
//
//    printf("Ingrese la patente del vehiculo a mostrar:\n\n");
//    scanf("%s",patente);
//    system("cls");
//
//    for(i=0;i<lenA;i++)
//    {
//        if(stricmp(patente,vehiculo[i].patente)==0)
//        {
//            printf("Datos del vehiculo:\n\nID \tPat.\tDia\tMes\tAnio\tHora ing.\tHora egr.\n");
//            mostrarVehiculoPorIndice(vehiculo,i);
//
//            i=buscarIndicePersona(persona,lenP,vehiculo[i].idPropietario);
//            printf("Datos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
//            mostrarPersonaPorIndice(persona,i);
//            break;
//        }
//    }
//    system("pause");
//    return;
//}

int calcularTarifaAuto(eVehiculo vehiculo[],int lenA,int index)
{
    int tarifa;
    tarifa=(vehiculo[index].horaSalida-vehiculo[index].horaIngreso)*100;
    return tarifa;
}

void mostrarTodasLasTarifas (eVehiculo vehiculo[], int lenA)
{
    int i;
    int total;
    system("cls");
    for(i=0;i<lenA;i++)
    {
        mostrarVehiculoPorIndice(vehiculo, i);
        total=calcularTarifaAuto(vehiculo,lenA,i);
        printf("Debe pagar $%d\n\n-----------------------------------------------------------------------------\n",total);
    }
    system("pause");
    return;
}

void printSeparation()
{
    printf("\n------------------------------------------------------------------------------------\n\n");
}
void printTabP()
{
    printf("Datos del titular:\n\nID\t\tNombre\t\tFecha de Nacimiento.\n\n");
}
void printTabA()
{
    printf("\n\nDatos del/los vehiculos:\n\nID\t  Patente\tFecha de Ingreso\tHora ing.\tHora Egr.\n\n");
}

void mostrarTarifaPorDuenio (ePersona persona[],eVehiculo vehiculo[],int lenA,int lenP)
{
    int i;
    int j;
    int total=0;
    system("cls");
    for(i=0;i<lenP;i++)
    {
        printTabP();
        mostrarPersonaPorIndice(persona,i);
        printTabA();
        for(j=0;j<lenA;j++)
        {
            if(persona[i].idPropietario==vehiculo[j].idPropietario)
            {
                total+=calcularTarifaAuto(vehiculo,lenA,j);
                mostrarVehiculoPorIndice(vehiculo,j);
            }
        }
        printf("\n%s debe en total %d por todos sus vehiculos.\n",persona[i].nombre,total);
        printSeparation();
        total=0;
    }
    system("pause");
    return;
}

void mostrarVehiculosYDuenios (ePersona persona[],eVehiculo vehiculo[],int lenp,int lena)
{
    int i;
    int j;
    system("cls");

    for(i=0;i<lena;i++)
    {
        printTabA();
        mostrarVehiculoPorIndice(vehiculo,i);
        for(j=0;j<lenp;j++)
        {
            if (vehiculo[i].idPropietario==persona[j].idPropietario)
            {
                printTabP();
                mostrarPersonaPorIndice(persona,j);
                break;
            }
        }
        printSeparation();
    }
    system("pause");
    return;
}

void mostrarPersonaConMasAutos(ePersona persona[],eVehiculo vehiculo[],int lenP, int lenA)
{
    int i;
    int j;
    int t;
    int maxA=0;
    int cont;
    int hora;
    int flagMaxEncontrado=0;
    system("cls");
    printf("Ingrese la hora:\n");
    scanf("%d",&hora);
    printf("\nPropietario/s con mas autos estacionados:\n\n");
    for(t=0;t<2;t++)
    {

        for(i=0;i<lenP;i++)
        {
            cont=0;
            for(j=0;j<lenA;j++)
            {
                if((persona[i].idPropietario==vehiculo[j].idPropietario)&&(hora>=vehiculo[j].horaIngreso&&hora<vehiculo[j].horaSalida))
                {
                    cont++;
                }
            }
            if(cont>maxA&&flagMaxEncontrado==0)
            {
                maxA=cont;
            }
            if(cont==maxA&&flagMaxEncontrado==1)
            {
                printf("%s con %d auto/s\n",persona[i].nombre,maxA);
            }
        }
        flagMaxEncontrado=1;
    }
    system("pause");
    return;
}
