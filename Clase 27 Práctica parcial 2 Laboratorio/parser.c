#include "parser.h"

/** \brief Parsea los datos los datos de los llamados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
int parser_TicketFromText(FILE* pFile, LinkedList* pArrayListElement)
{
    int r;
    int errorFlag=0;
    char var1[50];
    char var3[50];
    char var2[50];
    char var4[50];
    char var5[50];
    Llamada* element;
    if(pFile == NULL)
    {
        showMessage("El archivo no pudo abrirse. Asegurese de que el archivo existe.\n");
        r=0;
    }
    else
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
        do
        {
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);
            if(r==5)
            {
                element = ticket_newParametros(var1,var2,var3,var4,var5);

                if(ll_add(pArrayListElement,element)!=0)
                {
                    errorFlag=1;
                }
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

/** \brief Parsea los datos de los elementos desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListElement LinkedList*
 * \return int
 *
 */
//int parser_TicketFromBinary(FILE* pFile, LinkedList* pArrayListElement)
//{
//    int errorFlag=0;
//    char var1[50];
//    char var2[50];
//    Llamada auxElement;
//    Llamada lastElement;
//    Llamada* element;
//    if(pFile == NULL)
//    {
//        showMessage("El archivo no pudo abrirse.\n");
//    }
//    else
//    {
//        while(!feof(pFile))
//        {
//            fread(&auxElement,sizeof(Llamada),1,pFile);
//
//            if(lastElement.id!=auxElement.id)
//            {
//                element = ticket_newParametros(itoa(auxElement.id,var1,10),auxElement.nombre,itoa(auxElement.horasTrabajadas,var2,10));
//                ticket_setSueldo(element,auxElement.sueldo);
//
//                if(ll_add(pArrayListElement,element)!=0)
//                {
//                    printf("Error al dar de alta al llamado.\n");
//                }
//                lastElement=*element;
//            }
//        }
//        if(errorFlag==1)
//        {
//            showMessage("Hubo un error al cargar uno o más datos desde el archivo.\n");
//        }
//        else
//        {
//            showMessage("Se cargaron los datos con exito.\n\n");
//        }
//    }
//    return 1;
//}
