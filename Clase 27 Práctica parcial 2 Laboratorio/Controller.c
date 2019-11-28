#include "Controller.h"

/** \brief Carga los datos de los llamados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListTicket LinkedList*
 * \return int
 *
 */
int controller_loadFromText(LinkedList* pArrayListTicket)
{
    int len;
    len=ll_len(pArrayListTicket);
    char path[128];

    if(len>0)
    {
        showMessage("Ya hay llamados cargados en el sistema.\n");
    }
    else
    {
        getAlphabeticalString("Ingrese el nombre del archivo a cargar: ",path,127);
        FILE* pFile;
        pFile = fopen(path,"r");
        parser_TicketFromText(pFile,pArrayListTicket);
        fclose(pFile);
    }
    return 1;
}

/** \brief Carga los datos de los llamados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListTicket LinkedList*
 * \return int
 *
 */
//int controller_loadFromBinary(char* path, LinkedList* pArrayListTicket)
//{
//    int len;
//    len=ll_len(pArrayListTicket);
//    if(len>0)
//    {
//        showMessage("Ya hay llamados cargados en el sistema.\n");
//    }
//    else
//    {
//        FILE* pFile;
//        pFile = fopen(path,"rb");
//        parser_TicketFromBinary(pFile,pArrayListTicket);
//        fclose(pFile);
//    }
//    return 1;
//}

/** \brief Alta de llamados
 *
 * \param pArrayListTicket LinkedList*
 * \return int
 *
 */
//int controller_addTicket(LinkedList* pArrayListTicket)
//{
//    int ret=0;
//    Llamada* ticket;
//    ticket=ticket_new();
//    ticket_setId(ticket,getNextId(pArrayListTicket));
//    if(getConfirm()==1)
//    {
//        ll_add(pArrayListTicket,ticket);
//        showMessage("El llamado se cargo con exito.\n");
//        ret=1;
//    }
//    else
//    {
//        showMessage("Se cancelo la carga del llamado.\n");
//        ret=1;
//    }
//
//    return ret;
//}

/** \brief Modificar datos de llamado
 *
 * \param pArrayListTicket LinkedList*
 * \return int
 *
 */
//int controller_editTicket(LinkedList* pArrayListTicket)
//{
//    int i;
//    int founded=0;
//    int id;
//    int id2;
//    int workedHours;
//    int salary;
//    int len;
//    int auxInt;
//    int option;
//    int flagModified=0;
//    char newName[128];
//    char name[128];
//    Llamada* auxElement;
//
//    len=ll_len(pArrayListTicket);
//    if(len==0)
//    {
//        showMessage("No hay llamados cargados.\n");
//    }
//    else
//    {
//        ticket_showEveryone(pArrayListTicket);
//
//        id=getPositiveInt("\nIngrese el ID del llamado que desea modificar:\n");
//        system("cls");
//
//        for(i=0; i<len; i++)
//        {
//            auxElement=(Llamada*)ll_get(pArrayListTicket,i);
//            ticket_getId(auxElement,&id2);
//            if(id2==id)
//            {
//                founded=1;
//                do
//                {
//                    if(flagModified==1)
//                    {
//                        printf("Desea hacer alguna otra modificacion?\n\nID: %d \nNombre: %s\nHoras trabajadas: %d\nSueldo: %d\n\n",auxElement->id,auxElement->nombre,auxElement->horasTrabajadas,auxElement->sueldo);
//                    }
//                    else
//                    {
//                        printf("Esta por modificar al siguiente llamado:\n\nID: %d \nNombre: %s\nHoras trabajadas: %d\nSueldo: %d\n\n",auxElement->id,auxElement->nombre,auxElement->horasTrabajadas,auxElement->sueldo);
//                    }
//                    option=showMenuGetOption("Indique el campo que desea modificar:\n1)Nombre\n2)Horas trabajadas\n3)Sueldo\n4)Volver al menu principal\n",1,4);
//                    switch(option)
//                    {
//                    case 1:
//                        getAlphabeticalString("Ingrese nuevo nombre: ",newName,50);
//                        ticket_getNombre(auxElement,name);
//                        printf("\nEsta por modificar %s por %s\n",name,newName);
//                        if(getConfirm()==1)
//                        {
//                            ticket_setNombre(auxElement,newName);
//                            showMessage("Se modifico el campo indicado.\n");
//                        }
//                        else
//                        {
//                            showMessage("Se cancelo la modificacion.\n");
//                        }
//                        break;
//                    case 2:
//                        auxInt=getPositiveInt("Ingrese nueva cantidad de horas trabajadas: ");
//                        ticket_getHorasTrabajadas(auxElement,&workedHours);
//                        printf("\nEsta por modificar %d por %d\n",workedHours,auxInt);
//                        if(getConfirm()==1)
//                        {
//                            ticket_setHorasTrabajadas(auxElement,auxInt);
//                            showMessage("Se modifico el campo indicado.\n");
//                        }
//                        else
//                        {
//                            showMessage("Se cancelo la modificacion.\n");
//                        }
//                        break;
//                    case 3:
//                        auxInt=getPositiveInt("Ingrese nuevo sueldo: ");
//                        ticket_getSueldo(auxElement,&salary);
//                        printf("\nEsta por modificar %d por %d\n",salary,auxInt);
//                        if(getConfirm()==1)
//                        {
//                            ticket_setSueldo(auxElement,auxInt);
//                            showMessage("Se modifico el campo indicado.\n");
//                        }
//                        else
//                        {
//                            showMessage("Se cancelo la modificacion.\n");
//                        }
//                        break;
//                    case 4:
//                        if(flagModified==1)
//                        {
//                            showMessage("Modificaciones aplicadas, volviendo al menu.\n");
//                        }
//                        else
//                        {
//                            showMessage("Se cancelo la modificacion, volviendo al menu.\n");
//                        }
//                        break;
//                    }
//                    flagModified=1;
//                }
//                while(option!=4);
//            }
//        }
//        if(founded==0)
//        {
//            showMessage("El ID ingresado no se encuentra cargado en el sistema.\n");
//        }
//    }
//
//    return 1;
//}

/** \brief Baja de elemento
 *
 * \param pArrayListTicket LinkedList*
 * \return int
 *
 */
//int controller_removeElement(LinkedList* pArrayListTicket)
//{
//    int len;
//    len=ll_len(pArrayListTicket);
//    if(len==0)
//    {
//        showMessage("No hay llamados cargados.\n");
//    }
//    else
//    {
//        ticket_showEveryone(pArrayListTicket);
//        ticket_delete(pArrayListTicket,len);
//    }
//    return 1;
//}

/** \brief Listar llamados
 *
 * \param pArrayListTicket LinkedList*
 * \return int
 *
 */
int controller_ListElement(LinkedList* pArrayListTicket)
{
    int len;
    len=ll_len(pArrayListTicket);
    if(len==0)
    {
        showMessage("No hay llamados cargados.\n");
    }
    else
    {
        ticket_showEveryone(pArrayListTicket);
        system("pause");
        system("cls");
    }
    return 1;
}

/** \brief Ordenar llamados
 *
 * \param pArrayListTicket LinkedList*
 * \return int
 *
 */
//int controller_sortElements(LinkedList* pArrayListTicket)
//{
//    int len;
//    int option;
//    len=ll_len(pArrayListTicket);
//    if(len==0)
//    {
//        showMessage("No hay llamados cargados.\n");
//    }
//    else
//    {
//        option=showMenuGetOption("Indique el campo a tomar en cuenta para el ordenamiento:\n1)ID\n2)Nombre\n3)Horas trabajadas\n4)Sueldo\n5)Cancelar\n",1,5);
//        switch(option)
//        {
//        case 1:
//            if(showMenuGetOption("Seleccione el orden:\n\n1)Ascendente\n2)Descendente\n",1,2)==1)
//            {
//                processing();
//                ll_sort(pArrayListTicket,compareById,1);
//                system("cls");
//                controller_ListElement(pArrayListTicket);
//            }
//            else
//            {
//                processing();
//                ll_sort(pArrayListTicket,compareById,0);
//                system("cls");
//                controller_ListElement(pArrayListTicket);
//            }
//            break;
//        case 2:
//            if(showMenuGetOption("Seleccione el orden:\n\n1)Ascendente\n2)Descendente\n",1,2)==1)
//            {
//                processing();
//                ll_sort(pArrayListTicket,compareByName,1);
//                system("cls");
//                controller_ListElement(pArrayListTicket);
//            }
//            else
//            {
//                processing();
//                ll_sort(pArrayListTicket,compareByName,0);
//                system("cls");
//                controller_ListElement(pArrayListTicket);
//            }
//            break;
//        case 3:
//            if(showMenuGetOption("Seleccione el orden:\n\n1)Ascendente\n2)Descendente\n",1,2)==1)
//            {
//                processing();
//                ll_sort(pArrayListTicket,compareByWorkedHours,1);
//                system("cls");
//                controller_ListElement(pArrayListTicket);
//            }
//            else
//            {
//                processing();
//                ll_sort(pArrayListTicket,compareByWorkedHours,0);
//                system("cls");
//                controller_ListElement(pArrayListTicket);
//            }
//            break;
//        case 4:
//            if(showMenuGetOption("Seleccione el orden:\n\n1)Ascendente\n2)Descendente\n",1,2)==1)
//            {
//                processing();
//                ll_sort(pArrayListTicket,compareBySalary,1);
//                system("cls");
//                controller_ListElement(pArrayListTicket);
//            }
//            else
//            {
//                processing();
//                ll_sort(pArrayListTicket,compareBySalary,0);
//                system("cls");
//                controller_ListElement(pArrayListTicket);
//            }
//            break;
//        case 5:
//            break;
//        }
//    }
//    return 1;
//}

/** \brief Guarda los datos de los llamados en el archivo data.csv (modo texto).
 *
 * \param pArrayListTicket LinkedList* * \return int 1 en caso de éxito, 0 en caso de cancelado, -1 no pudo crear/guardar el archivo.
 *
 */
int controller_saveAsText(LinkedList* pArrayListTicket)
{
    int i;
    int len;
    int ret=1;
    int id=0;
    char date[11];
    int clientID=0;
    int errorCode=0;
    char status[3];
    char path[6];
    int option;
    Llamada* pElement;
    LinkedList* filteredLinkedList=NULL;

    FILE* pArchive;
    Llamada* aux;
    len=ll_len(pArrayListTicket);

    if(len==0)
    {
        printf("No hay llamados cargados.\n");
    }
    else
    {
        option=getIntMinMax("Ingrese el codigo de error a filtrar: ",1,5);
        switch(option)
        {
        case 1:
            filteredLinkedList=ll_filter(pArrayListTicket,compareToOne);
            break;
        case 2:
            filteredLinkedList=ll_filter(pArrayListTicket,compareToTwo);
            break;
        case 3:
            filteredLinkedList=ll_filter(pArrayListTicket,compareToThree);
            break;
        case 4:
            filteredLinkedList=ll_filter(pArrayListTicket,compareToFour);
            break;
        case 5:
            filteredLinkedList=ll_filter(pArrayListTicket,compareToFive);
            break;
        }
        pElement=(Llamada*)ll_get(filteredLinkedList,0);
        option=pElement->errorCode;
        itoa(option,path,10);
        strcat(path,".csv");

        pArchive=fopen(path,"w");
        if(pArchive == NULL)
        {
            showMessage("El archivo no pudo abrirse.\n");
            ret=-1;
        }
        else
        {
            len=ll_len(filteredLinkedList);
            fprintf(pArchive, "ID,Fecha,Cliente,Problema,Resuelto");

            for(i=0; i<len; i++)
            {
                aux=(Llamada*)ll_get(filteredLinkedList,i);
                ticket_getId(aux,&id);
                ticket_getDate(aux,date);
                ticket_getClientID(aux,&clientID);
                ticket_getErrorCode(aux,&errorCode);
                ticket_getStatus(aux,status);

                fprintf(pArchive,"\n%d,%s,%d,%d,%s",id,date,clientID,errorCode,status);
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

/** \brief Guarda los datos de los llamados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListTicket LinkedList*
 * \return int 1 en caso de éxito, 0 en caso de cancelado, -1 no pudo crear/guardar el archivo.
 *
 */
//int controller_saveAsBinary(char* path, LinkedList* pArrayListTicket)
//{
//    int i;
//    int len;
//    int ret=1;
//    FILE* pArchive;
//    Llamada*pAux;
//    len=ll_len(pArrayListTicket);
//    if(len==0)
//    {
//        printf("No hay llamados cargados, si se guarda ahora se perderan los datos almacenados en el archivo \"%s\".\n",path);
//        if(getConfirm()==0)
//        {
//            showMessage("Se cancelo la operacion.\n");
//            ret=0;
//        }
//    }
//    pArchive=fopen(path,"wb");
//
//    if(pArchive == NULL)
//    {
//        showMessage("El archivo no pudo abrirse.\n");
//        ret=-1;
//    }
//    else
//    {
//        len=ll_len(pArrayListTicket);
//
//        for(i=0; i<len; i++)
//        {
//            pAux=(Llamada*)ll_get(pArrayListTicket,i);
//            fwrite(pAux,sizeof(Llamada),1,pArchive);
//        }
//        fclose(pArchive);
//    }
//    if(ret==1)
//    {
//        showMessage("Se guardo el listado correctamente.\n");
//    }
//    return ret;
//}

