#include "Llamada.h"

//Llamada* ticket_new()
//{
//    Llamada* element;
//    char nameStr[51];
//    int auxInt;
//    int r=1;
//    element=(Llamada*)malloc(sizeof(Llamada));
//
//    getAlphabeticalString("Ingrese el nombre del llamado a cargar: ",nameStr,50);
//    r+=ticket_setNombre(element,nameStr);
//
//    auxInt=getPositiveInt("\nIngrese la cantidad de horas trabajadas: ");
//    r+=ticket_setHorasTrabajadas(element,auxInt);
//
//    auxInt=getPositiveInt("\nIngrese el sueldo: ");
//    r+=ticket_setSueldo(element,auxInt);
//
//    if(r<4)
//    {
//        showMessage("Error al cargar el nuevo llamado.\n");
//    }
//
//    return element;
//}

Llamada* ticket_newParametros(char* id,char* date,char* clientID,char* errorCode, char* status)
{
    Llamada* ticket;
    ticket=(Llamada*)malloc(sizeof(Llamada));

    ticket_setId(ticket,atoi(id));
    ticket_setDate(ticket,date);
    ticket_setClientID(ticket,atoi(clientID));
    ticket_setErrorCode(ticket,atoi(errorCode));
    ticket_setStatus(ticket,status);

    return ticket;
}

//void ticket_delete(LinkedList* pArrayListticket,int len)
//{
//    int i;
//    int founded=0;
//    int id;
//    Llamada* aux;
//
//    id=getPositiveInt("\nIngrese el ID del llamado que desea eliminar:\n");
//    system("cls");
//
//    for(i=0; i<len; i++)
//    {
//        aux=(Llamada*)ll_get(pArrayListticket,i);
//        if(aux->id==id)
//        {
//            printf("Esta por eliminar al siguiente llamado:\n\nID: %d \nNombre: %s\nHoras trabajadas: %d\nSueldo: %d\n\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
//            founded=1;
//            if(getConfirm()==1)
//            {
//                ll_remove(pArrayListticket,ll_indexOf(pArrayListticket,aux));
//                free()///Hacer un free del elemento acá!
//                showMessage("Se elimino al llamado correctamente.\n");
//            }
//            else
//            {
//                showMessage("Se cancelo la operacion.\n");
//            }
//
//            break;
//        }
//    }
//    if(founded==0)
//    {
//        showMessage("El ID ingresado no se encuentra cargado en el sistema.\n");
//    }
//}

int ticket_setId(Llamada* this,int id)
{
    this->id=id;
    return 1;
}

int ticket_getId(Llamada* this,int* id)
{
    *id=this->id;
    return 1;
}

int ticket_setDate(Llamada* this,char* date)
{
    strcpy(this->date,date);
    return 1;
}

int ticket_getDate(Llamada* this,char* date)
{
    strcpy(date,this->date);
    return 1;
}

int ticket_setClientID(Llamada* this,int clientID)
{
    this->clientID=clientID;
    return 1;
}

int ticket_getClientID(Llamada* this,int* clientID)
{
    *clientID=this->clientID;
    return 1;
}

int ticket_setErrorCode(Llamada* this,int errorCode)
{
    this->errorCode=errorCode;
    return 1;
}

int ticket_getErrorCode(Llamada* this,int* errorCode)
{
    *errorCode=this->errorCode;

    return 1;
}

int ticket_setStatus(Llamada* this,char* status)
{
    strcpy(this->status,status);
    return 1;
}

int ticket_getStatus(Llamada* this,char* status)
{
    strcpy(status,this->status);
    return 1;
}

//int compareById (void* p1, void* p2)
//{
//    Llamada* e1 = (Llamada*) p1;
//    Llamada* e2 = (Llamada*) p2;
//
//    return intCmp(e1->id,e2->id);
//}

//int compareByName (void* p1, void* p2)
//{
//    Llamada* e1 = (Llamada*) p1;
//    Llamada* e2 = (Llamada*) p2;
//
//    return stricmp(e1->nombre,e2->nombre);
//}

//int compareByWorkedHours (void* p1, void* p2)
//{
//    Llamada* e1 = (Llamada*) p1;
//    Llamada* e2 = (Llamada*) p2;
//
//    return intCmp(e1->horasTrabajadas,e2->horasTrabajadas);
//}

int compareToOne (void* pElement)
{
    int ret=0;
    int error;
    Llamada* ticket;

    ticket=(Llamada*)pElement;
    error=ticket->errorCode;
    if(error==1)
    {
        ret=1;
    }

    return ret;
}

int compareToTwo (void* pElement)
{
    int ret=0;
    int error;
    Llamada* ticket;

    ticket=(Llamada*)pElement;
    error=ticket->errorCode;
    if(error==2)
    {
        ret=1;
    }

    return ret;
}

int compareToThree (void* pElement)
{
    int ret=0;
    int error;
    Llamada* ticket;

    ticket=(Llamada*)pElement;
    error=ticket->errorCode;
    if(error==3)
    {
        ret=1;
    }

    return ret;
}

int compareToFour (void* pElement)
{
    int ret=0;
    int error;
    Llamada* ticket;

    ticket=(Llamada*)pElement;
    error=ticket->errorCode;
    if(error==4)
    {
        ret=1;
    }

    return ret;
}

int compareToFive (void* pElement)
{
    int ret=0;
    int error;
    Llamada* ticket;

    ticket=(Llamada*)pElement;
    error=ticket->errorCode;
    if(error==5)
    {
        ret=1;
    }

    return ret;
}

void ticket_showEveryone(LinkedList* pArrayListticket)
{
    int i;
    int len;
    int id;
    char date[11];
    int clientID;
    int errorCode;
    char status[3];
    char error[21];
    Llamada* aux;
    len=ll_len(pArrayListticket);
    printf("Hay %d llamados cargados\n\n", len);

    printTab();

    for(i=0; i<len; i++)
    {
        aux=(Llamada*)ll_get(pArrayListticket,i);
        ticket_getId(aux,&id);
        ticket_getDate(aux,date);
        ticket_getClientID(aux,&clientID);
        ticket_getErrorCode(aux,&errorCode);
        ticket_getStatus(aux,status);
        switch(errorCode)
        {
        case 1:
            strcpy(error,"No enciende PC");
            break;
        case 2:
            strcpy(error,"No funciona mouse");
            break;
        case 3:
            strcpy(error,"No funciona teclado");
            break;
        case 4:
            strcpy(error,"No hay internet");
            break;
        case 5:
            strcpy(error,"No funciona telefono");
            break;
        }
        printf("%-4d %-12s %-16d %-22s %-12s\n",id,date,clientID,error,status);
    }
}
