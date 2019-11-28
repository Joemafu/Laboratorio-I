#include "parser.h"

int parser_FlightFromText(FILE* pFile, LinkedList* flightList)
{
    int r;
    int i=0;
    int errorFlag=0;
    char var1[50];
    char var3[50];
    char var2[50];
    char var4[50];
    char var5[50];
    char var6[50];
    char var7[50];
    char var8[50];
    Flight* element;
    if(pFile == NULL)
    {
        showMessage("El archivo no pudo abrirse. Asegurese de que el archivo existe.\n");
        r=0;
    }
    else
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);
        do
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);
            if(r==8)
            {
                element = flight_newParametros(var1,var2,var3,var4,var5,var6,var7,var8);

                if(ll_add(flightList,element)!=0)
                {
                    errorFlag=1;
                }
                i++;
            }
            else
            {
                showMessage("No se cargaron los datos.\n");
                r=0;
                break;
            }
        }
        while(!feof(pFile));
        if(errorFlag==1)
        {
            showMessage("Hubo un error al cargar uno o más datos desde el archivo.\n");
            r=0;
        }
        else
        {
            showMessage("Se cargaron los datos con exito.\n\n");
            r=1;
        }
    }
    return r;
}
