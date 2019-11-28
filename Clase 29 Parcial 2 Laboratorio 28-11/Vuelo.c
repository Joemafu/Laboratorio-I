#include "Vuelo.h"

Flight* flight_newParametros(char* flightID,char* plane,char* pilot,char* date, char* destination, char* amountOfPassengers,char* departureTime, char* arrivalTime)
{
    Flight* flight;
    flight=(Flight*)malloc(sizeof(Flight));

    flight_setFlightId(flight,atoi(flightID));
    flight_setPlaneID(flight,atoi(plane));
    flight_setPilotID(flight,atoi(pilot));
    flight_setDate(flight,date);
    flight_setDestination(flight,destination);
    flight_setAmountOfPassengers(flight,atoi(amountOfPassengers));
    flight_setDepartureTime(flight,atoi(departureTime));
    flight_setArrivalTime(flight,atoi(arrivalTime));

    return flight;
}

int flight_setFlightId(Flight* this,int id)
{
    this->idFlight=id;
    return 1;
}

int flight_getFlightId(Flight* this,int* id)
{
    *id=this->idFlight;
    return 1;
}

int flight_setPlaneID(Flight* this,int idPlane)
{
    this->idPlane=idPlane;
    return 1;
}

int flight_getPlaneID(Flight* this,int* idPlane)
{
    *idPlane=this->idPlane;
    return 1;
}

int flight_setPilotID(Flight* this,int idPilot)
{
    this->idPilot=idPilot;
    return 1;
}

int flight_getPilotID(Flight* this,int* idPilot)
{
    *idPilot=this->idPilot;

    return 1;
}

int flight_setDate(Flight* this,char* date)
{
    strcpy(this->date,date);
    return 1;
}

int flight_getDate(Flight* this,char* date)
{
    strcpy(date,this->date);
    return 1;
}

int flight_setDestination(Flight* this,char* destination)
{
    strcpy(this->destination,destination);
    return 1;
}

int flight_getDestination(Flight* this,char* destination)
{
    strcpy(destination,this->destination);
    return 1;
}

int flight_setAmountOfPassengers(Flight* this,int amountOfPassengers)
{
    this->amountOfPassengers=amountOfPassengers;
    return 1;
}

int flight_getAmountOfPassengers(Flight* this,int* amountOfPassengers)
{
    *amountOfPassengers=this->amountOfPassengers;

    return 1;
}

int flight_setDepartureTime(Flight* this,int departureTime)
{
    this->departureTime=departureTime;
    return 1;
}

int flight_getDepartureTime(Flight* this,int* departureTime)
{
    *departureTime=this->departureTime;

    return 1;
}

int flight_setArrivalTime(Flight* this,int arrivalTime)
{
    this->arrivalTime=arrivalTime;
    return 1;
}

int flight_getArrivalTime(Flight* this,int* arrivalTime)
{
    *arrivalTime=this->arrivalTime;

    return 1;
}

void flight_showEveryone(LinkedList* pArrayListflight)
{
    int i;
    int len;
    int flightID;
    int planeID;
    int pilotID;
    char date[11];
    char destination[51];
    int amountOfPassengers;
    int departureTime;
    int arrivalTime;
    char pilot[21];
    Flight* aux;
    len=ll_len(pArrayListflight);
    printf("Hay %d vuelos cargados\n\n", len);

    printTab();

    for(i=0; i<len; i++)
    {
        aux=(Flight*)ll_get(pArrayListflight,i);

        flight_getFlightId(aux,&flightID);
        flight_getPlaneID(aux,&planeID);
        flight_getPilotID(aux,&pilotID);
        flight_getDate(aux,date);
        flight_getDestination(aux,destination);
        flight_getAmountOfPassengers(aux,&amountOfPassengers);
        flight_getDepartureTime(aux,&departureTime);
        flight_getArrivalTime(aux,&arrivalTime);

        switch(pilotID)
        {
        case 1:
            strcpy(pilot,"Alex Lifeson");
            break;
        case 2:
            strcpy(pilot,"Richard Bach");
            break;
        case 3:
            strcpy(pilot,"John Kerry");
            break;
        case 4:
            strcpy(pilot,"Erwin Rommel");
            break;
        case 5:
            strcpy(pilot,"Stephen Coonts");
            break;
        }
        printf("%-4d %-4d %-16s %-12s %-12s %-4d %-6d %-6d\n",flightID,planeID,pilot,date,destination,amountOfPassengers,departureTime,arrivalTime);
    }
}

int passengerCounter (void* pElement)
{
    int ret=0;
    Flight* flight;
    if(pElement!=NULL)
    {
        flight=(Flight*) pElement;
        ret=flight->amountOfPassengers;
    }

    return ret;
}

int counterToIreland (void* pElement)
{
    Flight* flight;
    flight=(Flight*)pElement;
    int counter=0;

    if(stricmp(flight->destination,"irlanda")==0)
    {
        counter=passengerCounter(flight);
    }
    return counter;
}

int compareShortFlights(void* pElement)
{
    int ret=0;
    Flight* flight;

    flight=(Flight*)pElement;
    if(flight->arrivalTime-flight->departureTime<3)
    {
        ret=1;
    }
    return ret;
}

int compareDestinationPortgual(void* pElement)
{
    int ret=0;
    Flight* flight;

    flight=(Flight*)pElement;
    if(stricmp(flight->destination,"portugal")==0)
    {
        ret=1;
    }
    return ret;
}

int comparePilotAlexLifeson(void* pElement)
{
    int ret=1;
    Flight* flight;

    flight=(Flight*)pElement;
    if(flight->idPilot==1)
    {
        ret=0;
    }
    return ret;
}

