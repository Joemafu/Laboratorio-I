#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Llamada.h"
#include "parser.h"
#include "AuxFunctions.h"

int main()
{
    int option;
    LinkedList* ticketList = ll_newLinkedList();

    do
    {
        option=showMenuGetOption("Menu:\n\n\
         1. Cargar datos desde archivo.\n\
         2. Imprimir llamadas.\n\
         3. Generar archivo de llamadas.\n\
         4. Salir.\n",1,4);
        switch(option)
        {
        case 1:
            controller_loadFromText(ticketList);
            break;
        case 2:
            controller_ListElement(ticketList);
            break;
        case 3:
            controller_saveAsText(ticketList);
            break;
        case 4:
            ll_deleteLinkedList(ticketList);
            break;
        }
    }
    while(option != 4);

    return 0;
}
