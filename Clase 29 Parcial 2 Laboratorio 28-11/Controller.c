#include "Controller.h"

int controller_loadFromText(LinkedList* flightList)
{
    int len;
    len=ll_len(flightList);
    char path[128];

    if(len>0)
    {
        showMessage("Ya hay vuelos cargados en el sistema.\n");
    }
    else
    {
        getAlphabeticalString("Ingrese el nombre del archivo a cargar: ",path,127);
        FILE* pFile;
        pFile = fopen(path,"r");
        parser_FlightFromText(pFile,flightList);
        fclose(pFile);
    }
    return 1;
}

int controller_ListElement(LinkedList* flightList)
{
    int len;
    len=ll_len(flightList);
    if(len==0)
    {
        showMessage("No hay vuelos cargados.\n");
    }
    else
    {
        flight_showEveryone(flightList);
        system("pause");
        system("cls");
    }
    return 1;
}

int controller_saveAsText(LinkedList* flightList, char* path)
{
    int i;
    int len;
    int ret=1;
    int flightID=0;
    int planeID=0;
    int pilotID=0;
    char date[11];
    char destination[51];
    int amountOfPasengers=0;
    int departure=0;
    int arrival=0;

    FILE* pArchive;
    Flight* aux;
    len=ll_len(flightList);

    if(len==0)
    {
        printf("No hay vuelos cargados.\n");
    }
    else
    {

        pArchive=fopen(path,"w");
        if(pArchive == NULL)
        {
            showMessage("El archivo no pudo abrirse.\n");
            ret=-1;
        }
        else
        {
            len=ll_len(flightList);
            fprintf(pArchive, "idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada");

            for(i=0; i<len; i++)
            {
                aux=(Flight*)ll_get(flightList,i);
                flight_getFlightId(aux,&flightID);
                flight_getPlaneID(aux,&planeID);
                flight_getPilotID(aux,&pilotID);
                flight_getDate(aux,date);
                flight_getDestination(aux,destination);
                flight_getAmountOfPassengers(aux,&amountOfPasengers);
                flight_getArrivalTime(aux,&arrival);
                flight_getDepartureTime(aux,&departure);

                fprintf(pArchive,"\n%d,%d,%d,%s,%s,%d,%d,%d",flightID,planeID,pilotID,date,destination,amountOfPasengers,departure,arrival);
            }
            fclose(pArchive);
        }
        if(ret==1)
        {
            showMessage("Se guardo el listado correctamente.\n");
        }
    }
    return ret;
}

void controller_countPassengers(LinkedList* flightList)
{
    int totalPassengers;
    totalPassengers=ll_count(flightList,passengerCounter);
    printf("Cantidad de pasajeros totales: %d\n",totalPassengers);
    system("pause");
    system("cls");
}

void controller_countPassengersToIreland(LinkedList* flightList)
{
    int totalPassengersToIreland;
    totalPassengersToIreland=ll_count(flightList,counterToIreland);
    printf("Cantidad de pasajeros a Irlanda: %d\n",totalPassengersToIreland);
    system("pause");
    system("cls");
}

void controller_filterShortFlights(LinkedList* flightList)
{
    LinkedList* filteredList=NULL;
    filteredList=ll_filter(flightList,compareShortFlights);
    controller_saveAsText(filteredList,"shortFlights.csv");
    flight_showEveryone(filteredList);
    system("pause");
    system("cls");
}

void controller_filterPortugalFlights(LinkedList* flightList)
{
    LinkedList* filteredList=NULL;
    filteredList=ll_filter(flightList,compareDestinationPortgual);
    controller_saveAsText(filteredList,"destinationPortugal.csv");
    flight_showEveryone(filteredList);
    system("pause");
    system("cls");
}

void controller_filterAlexLifeson(LinkedList* flightList)
{
    LinkedList* filteredList=NULL;
    filteredList=ll_filter(flightList,comparePilotAlexLifeson);
    controller_saveAsText(filteredList,"flightsWithoutAlexLifeson.csv");
    flight_showEveryone(filteredList);
    system("pause");
    system("cls");
}

void controller_exit(LinkedList* flightList)
{
    ll_deleteLinkedList(flightList);
}
