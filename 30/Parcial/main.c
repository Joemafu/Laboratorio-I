#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{

    int id;
    float coordY;
    float coordX;
    char raza [20];
    char galaxia[20];

}eAlien;

void* newAlien ();
void* newAlienP (int id, float coordY, float coordX, char* raza, char* galaxia);
int escribirAliens (eAlien* Lista,int tam, char* path);

int main()
{
    eAlien* alien[6];

    alien[0]=newAlienP(1,1.01,1.10,"raza1","galaxia1");
    alien[1]=newAlienP(2,2.02,2.20,"raza2","galaxia2");
    alien[2]=newAlienP(3,3.03,3.30,"raza3","galaxia3");
    alien[3]=newAlienP(4,4.04,4.40,"raza4","galaxia4");
    alien[4]=newAlienP(5,5.05,5.50,"raza5","galaxia5");

    escribirAliens(alien[0],5,"aliens.bin");

    return 0;
}

void* newAlien ()
{
    eAlien* ret;
    char id [6];
    char coordY[6];
    char coordX[6];
    char raza[20];
    char galaxia[20];

    ret=(eAlien*)malloc(sizeof(eAlien));

    if (ret!=NULL)
    {
        printf("Ingrese ID de alien:\n");
        scanf(id);
        fflush(stdin);
        ret->id=atoi(id);

        printf("Ingrese coordenada Y de alien:\n");
        scanf(coordY);
        fflush(stdin);
        ret->coordY=atof(coordY);

        printf("Ingrese coordenada X de alien:\n");
        scanf(coordX);
        fflush(stdin);
        ret->coordX=atof(coordX);

        printf("Ingrese raza de alien:\n");
        scanf(raza);
        fflush(stdin);
        strcpy(ret->raza,raza);

        printf("Ingrese galaxia de alien:\n");
        scanf(galaxia);
        fflush(stdin);
        strcpy(ret->galaxia,galaxia);
    }
    else
    {
        printf("Hubo un error al crear el alien.");
    }

    return ret;
}
void* newAlienP (int id, float coordY, float coordX, char* raza, char* galaxia)
{
    eAlien* ret;
    ret=(eAlien*)malloc(sizeof(eAlien));

    if (ret!=NULL)
    {
        ret->id=id;
        ret->coordY=coordY;
        ret->coordX=coordX;
        strcpy(ret->raza,raza);
        strcpy(ret->galaxia,galaxia);
    }
    else
    {
        printf("Hubo un error al crear el alien.");
    }

    return ret;
}

int escribirAliens (eAlien* Lista,int tam, char* path)
{
    int i;
    FILE* pFile;
    int r=0;
    int ret=-1;
    if(path!=NULL)
    {
        ret=1;
        pFile=fopen(path,"wb");

        for (i=0;i<tam;i++)
        {
            r=fwrite(Lista+i,sizeof(eAlien),1,pFile);
            if(r!=1)
            {
                printf("No se pudo agregar al alien.\n");
                ret=0;
                break;
            }
        }
        fclose(pFile);
    }
    return ret;
}

eAlien* leerAliens (char* path)
{
    int i=0;
    eAlien* ret=NULL;
    FILE* pFile;
    int r=0;
    eAlien* alien[6];
    if(path!=NULL)
    {
        pFile=fopen(path,"rb");

        while(feof(pFile)!=1)
        {
            r=fread(alien[i],sizeof(eAlien),1,pFile);
            i++;
            if(r!=1)
            {
                printf("No se pudo agregar al alien.\n");
                ret=NULL;
                break;
            }
        }
        ret=alien[0];
    }
    return ret;
}
