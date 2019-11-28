#include "AuxFunctions.h"

int getAlphabeticalString (char* message,char* string,int maxLen)
{
    int i;
    int len;
    int ret;
    do
    {
        printf(message);
        gets(string);
        fflush(stdin);
        len=strlen(string);
        ret=1;
        if(len>maxLen)
        {
            system("cls");
            printf("Se supero el maximo de caracteres permitidos para este campo (hasta %d).\n",maxLen);
            system("pause");
            system("cls");
            ret=0;
        }
        else
        {
            for(i=0; i<len; i++)
            {
                if (!((string[i]==32)||(string[i]==39)||(string[i]>64&&string[i]<91)||(string[i]>96&&string[i]<123)||(string[i]>47&&string[i]<58)||(string[i]==46)))
                {
                    showMessage("Se ingresaron caracteres no alfanumericos, verifique e intente nuevamente.\n\n");
                    ret=0;
                    break;
                }
            }
        }

    }
    while(len==0||ret==0);


    return ret;
}

int getConfirm()
{
    int ret=-1;
    printf("Desea confirmar? s/n.\n");
    do
    {
        ret=getche();
        fflush(stdin);
        if((ret==83)||(ret==115))
        {
            ret=1;
        }
        else if((ret==78)||(ret==110))
        {
            ret=0;
        }
        else
        {
            printf("\n\nPresione s para confirmar, n para cancelar: \n");
        }
    }
    while(ret!=0&&ret!=1);

    return ret;
}

int getNextId (LinkedList* elementList)
{
    int i;
    int len;
    int maxId=0;
    int flag=0;
    int id=0;
    Flight* aux;

    len=ll_len(elementList);

    for(i=0; i<len; i++)
    {
        aux=(Flight*)ll_get(elementList,i);
        flight_getFlightId(aux,&id);
        if(id>maxId||flag==0)
        {
            flag=1;
            maxId=id;
        }
    }

    return maxId+1;
}

int getPositiveInt(char message[])
{
    int i=0;
    char string[10]; ///Almacena hasta el 2147483647.
    int ret;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        ret=0;
        for(i=0; string[i]!='\0'; i++)
        {
            if(string[i]<48||string[i]>57)
            {
                showMessage("Ingrese un valor numerico valido. (Solo numeros enteros positivos).\n\n");
                ret=-1;
                break;
            }
        }
    }
    while(ret==-1);
    ret=atoi(string);
    return ret;
}

int intCmp (int int1,int int2)
{
    int ret;
    if(int1>int2)
    {
        ret=1;
    }
    else if(int1==int2)
    {
        ret=0;
    }
    else
    {
        ret=-1;
    }

    return ret;
}

void printTab ()
{
    printf("ID vuelo - ID avion - Piloto - Fecha - Destino - Pasajeros - Hora salida - Hora llegada\n\n");
    return;
}

void processing()
{
    printf("Aguarde mientras se procesan los datos...\n");
}

int showMenuGetOption(char* message, int min, int max)
{
    int option;
    do
    {
        printf(message);
        scanf("%d", &option);
        fflush(stdin);
        system("cls");
        if(option<min||option>max)
        {
            system("cls");
            printf("Indique una opcion valida entre %d y %d.\n\n",min,max);
        }
    }
    while(option <min||option>max);
    return option;
}

void showMessage(char message[])
{
    system("cls");
    printf(message);
    system("pause");
    system("cls");
}

int getIntMinMax(char message[],int min,int max)
{
    int i;
    char string[10]; ///Almacena hasta el 2147483647.
    int ret;
    int success;
    do
    {
        printf(message);
        scanf("%s",string);
        fflush(stdin);
        success=0;
        if (!((string[0]>47&&string[0]<58)||(string[0]==45)))
        {
            success--;
        }
        for(i=1; string[i]!='\0'; i++)
        {
            if((string[i]<48||string[i]>57)||(success<0))
            {
                success--;
                break;
            }
        }
        ret=atoi(string);
        if ((ret<min||ret>max)||(success<0))
        {
            printf("Ingrese un valor numerico valido. (Solo numeros enteros entre %d y %d).\n\n",min,max);
            success--;
        }
    }
    while(success<0);

    return ret;
}

