#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[20];
} eAlien;

eAlien* nuevoAlien ();
eAlien* nuevoAlienParam (int id, char* nombre);
void getId(eAlien* pAlien,int* id);
void setId(eAlien* pAlien,int id);
void getName(eAlien* pAlien,char* name);
void setName(eAlien* pAlien,char* name);
int escribirAliens (eAlien* lista[], int tam);
int leerAliens (eAlien* lista[], char* archive);
void mostrarAliens(eAlien* alien);

int main()
{
    eAlien* lista[2];
    lista[0]=nuevoAlienParam(1,"Xorg");
    lista[1]=nuevoAlienParam(2,"Xarg");

    if(escribirAliens(lista,2)==1)
    {
        printf("Se escribireron los aliens con exito.\n\n");
    }
    if(leerAliens(lista,"aliens.bin")==1)
    {
        printf("Se leyeron los aliens con exito.\n\n");

    }

    return 0;
}

eAlien* nuevoAlien ()
{
    eAlien* pAlien=NULL;
    pAlien = malloc (sizeof(eAlien));
    return pAlien;
}

eAlien* nuevoAlienParam (int id, char* nombre)
{
    eAlien* pAlien;
    pAlien=nuevoAlien();
    setId(pAlien,id);
    setName(pAlien,nombre);

    return pAlien;
}

void getId(eAlien* pAlien,int* id)
{
    *id=pAlien->id;
}

void setId(eAlien* pAlien,int id)
{
    pAlien->id=id;
}

void getName(eAlien* pAlien,char* name)
{
    strcpy(name,pAlien->nombre);
}

void setName(eAlien* pAlien,char* name)
{
    strcpy(pAlien->nombre,name);
}

int escribirAliens (eAlien* lista[], int tam)
{
    int i;
    int ret=-1;
    int success=0;
    FILE* pFile;

    pFile=fopen("aliens.bin","wb");

    if(pFile!=NULL)
    {
        ret=1;
        for(i=0; i<tam; i++)
        {
            mostrarAliens(lista[i]);
            success=fwrite(lista[i],sizeof(eAlien),1,pFile);
            if(success!=1)
            {
                break;
            }
        }
    }
    fclose(pFile);


    return ret;
}

int leerAliens (eAlien* lista[], char* archive)
{
    eAlien* pAuxAlien=nuevoAlien();
    FILE* pFile=NULL;
    int success;
    int i=0;
    int ret=-1;

    pFile=fopen(archive, "rb");

    if(pFile!=NULL)
    {

        while(!feof(pFile))
        {
            success=fread((eAlien*)pAuxAlien,sizeof(eAlien),1,pFile);

            lista[i]=pAuxAlien;

            if(success!=1)
            {
                break;
            }
            ret=1;
            mostrarAliens(lista[i]);

            i++;
        }
    }
    fclose(pFile);
    return ret;
}

void mostrarAliens(eAlien* alien)
{
    int auxInt=0;
    char auxName[20];

    getId(alien,&auxInt);
    getName(alien,auxName);
    printf("Alien %s, ID %d\n",auxName,auxInt);
}
