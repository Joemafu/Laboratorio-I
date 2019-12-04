#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 5
typedef struct{

    int id;
    float coordY;
    float coordX;
    char raza [20];
    char galaxia[20];

}eAlien;

void* newAlien ();
void* newAlienP (int id, float coordY, float coordX, char* raza, char* galaxia);
int escribirAliens (eAlien* Lista[],int tam, char* path);
int leerAliens (char* path, eAlien* lista[]);
void setId (eAlien* alien, int id);
void getId (eAlien* alien, int* id);
void setCoordY (eAlien* alien, float coordY);
void getCoordY (eAlien* alien, float* coordY);
void setCoordX (eAlien* alien, float coordX);
void getCoordX (eAlien* alien, float* coordX);
void setRaza (eAlien* alien, char* raza);
void getRaza (eAlien* alien, char* raza);
void setGalaxia (eAlien* alien, char* galaxia);
void getGalaxia (eAlien* alien, char* galaxia);

int main()
{
    eAlien* alien[CANT];

    alien[0]=newAlienP(1,1.01,1.10,"raza1","galaxia1");
    alien[1]=newAlienP(2,2.02,2.20,"raza2","galaxia2");
    alien[2]=newAlienP(3,3.03,3.30,"raza3","galaxia3");
    alien[3]=newAlienP(4,4.04,4.40,"raza4","galaxia4");
    alien[4]=newAlienP(5,5.05,5.50,"raza5","galaxia5");

    escribirAliens(alien,CANT,"aliens.bin");

    leerAliens("aliens.bin",alien);

    return 0;
}

void* newAlien ()
{
    eAlien* ret;

    ret=(eAlien*)calloc(sizeof(eAlien),1);

    if (ret==NULL)
    {
        printf("Hubo un error al crear el alien.");
    }

    return ret;
}

void* newAlienP (int id, float coordY, float coordX, char* raza, char* galaxia)
{
    eAlien* ret;
    ret=newAlien();

    if (ret!=NULL)
    {
        setId(ret,id);
        setCoordY(ret,coordY);
        setCoordX(ret,coordX);
        setRaza(ret,raza);
        setGalaxia(ret,galaxia);
    }
    else
    {
        printf("Hubo un error al crear el alien.");
    }

    return ret;
}

int escribirAliens (eAlien* lista[],int tam, char* path)
{
    int i;
    FILE* pFile=NULL;
    int r=0;
    int ret=-1;
    if(path!=NULL)
    {
        ret=1;
        pFile=fopen(path,"wb");

        for (i=0;i<tam;i++)
        {
            r=fwrite(lista[i],sizeof(eAlien),1,pFile);
            if(r!=1)
            {
                printf("No se pudo escribir el alien.\n");
                ret=0;
                break;
            }
        }

        fclose(pFile);
    }
    return ret;
}

int leerAliens (char* path, eAlien* lista[])
{
    int i=0;
    int ret=-1;
    int r=0;
    FILE* pFile;
    eAlien* pAlien=newAlien();
    int auxID=0;
    float auxCoordY=0;
    float auxCoordX=0;
    char auxRaza[20];
    char auxGalaxia[20];

    if(path!=NULL)
    {
        pFile=fopen(path,"rb");

        while(!feof(pFile))
        {
            r=fread(pAlien,sizeof(eAlien),1,pFile);
            if (r!=1)
            {
                break;
            }else
            {
                getId(pAlien,&auxID);
                getCoordY(pAlien,&auxCoordY);
                getCoordX(pAlien,&auxCoordX);
                getRaza(pAlien,auxRaza);
                getGalaxia(pAlien,auxGalaxia);

                lista[i]=(eAlien*)newAlienP(pAlien->id,pAlien->coordY,pAlien->coordX,pAlien->raza,pAlien->galaxia);

                printf("%d--%.02f--%.02f--%s--%s\n",auxID,auxCoordY,auxCoordX,auxRaza,auxGalaxia);

                i++;
            }
//
        }
        fclose(pFile);
    }
    return ret;
}

void setId (eAlien* alien, int id)
{
    alien->id=id;
}

void getId (eAlien* alien, int* id)
{
    *id=alien->id;
}

void setCoordY (eAlien* alien, float coordY)
{
    alien->coordY=coordY;
}

void getCoordY (eAlien* alien, float* coordY)
{
    *coordY=alien->coordY;
}

void setCoordX (eAlien* alien, float coordX)
{
    alien->coordX=coordX;
}

void getCoordX (eAlien* alien, float* coordX)
{
    *coordX=alien->coordX;
}

void setRaza (eAlien* alien, char* raza)
{
    strcpy(alien->raza,raza);
}

void getRaza (eAlien* alien, char* raza)
{
    strcpy(raza,alien->raza);
}

void setGalaxia (eAlien* alien, char* galaxia)
{
    strcpy(alien->galaxia,galaxia);
}

void getGalaxia (eAlien* alien, char* galaxia)
{
    strcpy(galaxia,alien->galaxia);
}
