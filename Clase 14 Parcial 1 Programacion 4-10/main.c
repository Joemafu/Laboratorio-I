#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
    int id;
    char nombre[51];
    float precio;

}typedef eProducto;

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int myStrlen (char string[],int);

int main()
{
    ///PUNTO 11
    eProducto producto[5];
    eProducto aux[1];
    int i;
    int j;
    int id[5]={1,2,3,4,5};
    char nombre[5][51]={"prod1","prod2","prod5","prod4","prod3"};
    float precio[5]={3.33,2.22,4.44,7.77,4.44};

    for(i=0;i<5;i++)
    {
        producto[i].id=id[i];
        strcpy(producto[i].nombre,nombre[i]);
        producto[i].precio=precio[i];
    }

    for(i=1;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            if(producto[i].precio<producto[j].precio)
            {
                aux[0]=producto[i];
                producto[i]=producto[j];
                producto[j]=aux[0];
            }
            if((producto[i].precio==producto[j].precio)&&(stricmp(producto[i].nombre,producto[j].nombre)<0))
            {
                aux[0]=producto[i];
                producto[i]=producto[j];
                producto[j]=aux[0];
            }
        }
    }
    printf("ID\tPrecio\tNombre\n");
    for(i=0;i<5;i++)
    {
        printf("%d\t",producto[i].id);
        printf("%.2f\t",producto[i].precio);
        printf("%s\n",producto[i].nombre);
    }



    printf("\n\n");


    ///PUNTO 12

    char string[51]={"hola mundo"};
    int len;

    len=myStrlen(string,51);

    printf("%d",len);

    return 0;
}

int myStrlen (char string[],int max)
{
    int i;
    int ret=0;

    for(i=0;i<max;i++)
    {
        if(string [i]!='\0')
        {
            ret++;
        }
    }
    return ret;
}
