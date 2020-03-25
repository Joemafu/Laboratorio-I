#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[20];
}sAlien;

sAlien* newAlien ();
sAlien* newAlienP (int id, char* name);
void setId (sAlien* alien,int id);
void setName (sAlien* alien,char* name);
int writeAliens (sAlien* lista[], int size);
int readAliens (sAlien* lista[]);
void getId (sAlien* alien,int* id);
void getName (sAlien* alien,char* name);
void printAlien (sAlien* alien);

int main()
{
    sAlien* listaEscritura[2];
    sAlien* listaLectura[2];
    listaEscritura[0]=newAlienP(1,"Xarg");
    listaEscritura[1]=newAlienP(2,"Xorg");
    listaLectura[0]=newAlien();
    listaLectura[1]=newAlien();

    printf("Aiens escritos:\n");

    printAlien(listaEscritura[0]);
    printAlien(listaEscritura[1]);

    if(writeAliens(listaEscritura,2)==1)
    {
        printf("Se escribieron los aliens correctamente.\n");
    }
    else
    {
        printf("Hubo un error al escribir los aliens.\n");
    }

    printf("\nAiens leidos:\n");

    if(readAliens(listaLectura)==1)
    {
        printf("Se leyeron los aliens correctamente.\n");
    }
    else
    {
        printf("Hubo un error al leer los aliens.\n");
    }

    return 0;
}

sAlien* newAlien ()
{
    sAlien* pAlien=NULL;

    pAlien=(sAlien*)malloc(sizeof(sAlien));

    return pAlien;
}

sAlien* newAlienP (int id, char* name)
{
    sAlien* pAlien;
    pAlien=newAlien();
    if (pAlien!=NULL)
    {
        setId(pAlien,id);
        setName(pAlien,name);
    }

    return pAlien;
}

void setId (sAlien* alien,int id)
{
    alien->id=id;
}

void setName (sAlien* alien,char* name)
{
    strcpy(alien->name,name);
}

void getId (sAlien* alien,int* id)
{
    *id=alien->id;
}

void getName (sAlien* alien,char* name)
{
    strcpy(name,alien->name);
}

int writeAliens (sAlien* lista[], int size)
{
    FILE* pFile=NULL;
    int i;
    int success;
    int ret=-1;

    pFile=fopen("aliens.bin","wb");
    if(pFile!=NULL)
    {
        ret=1;
    }

    for (i=0;i<size;i++)
    {
        success=fwrite(lista[i],sizeof(sAlien),1,pFile);
        if(success!=1||lista[i]==NULL)
        {
            ret=0;
            break;
        }
    }
    fclose(pFile);

    return ret;

}

int readAliens (sAlien* lista[])
{
    FILE* pFile=NULL;
    int i;
    int success;
    int ret=-1;

    pFile=fopen("aliens.bin","rb");
    if(pFile!=NULL)
    {
        ret=1;
    }

    for (i=0;!feof(pFile);i++)
    {
        success=fread(lista[i],sizeof(sAlien),1,pFile);
        if(success!=1||lista[i]==NULL)
        {
            break;
        }
        printAlien(lista[i]);
    }
    fclose(pFile);

    return ret;
}

void printAlien (sAlien* alien)
{
    int id;
    char name[20];

    getId(alien,&id);
    getName(alien,name);
    printf("Alien %s - ID %d\n",name,id);
}
