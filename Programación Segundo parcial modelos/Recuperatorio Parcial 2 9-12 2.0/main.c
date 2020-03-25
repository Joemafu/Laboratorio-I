#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nota;
    char nombre[20];

}eAlumno;

eAlumno* nuevoAlumno ();
eAlumno* nuevoAlumnoParametros(int nota, char* nombre);
void getNota(eAlumno* pAlumno,int* nota);
void getNombre(eAlumno* pAlumno, char* nombre);
void setNota(eAlumno* pAlumno, int nota);
void setNombre(eAlumno* pAlumno, char* nombre);
void escribirAlumnos(eAlumno* pAlumno[],int tam);
void leerAlumnos(eAlumno* pAlumno[], char* path);
void mostrarAlumnos(eAlumno* pAlumno[],int tam);

int main()
{
    eAlumno* pAlumno[2];
    pAlumno[0]=nuevoAlumnoParametros(10,"Pedro");
    pAlumno[1]=nuevoAlumnoParametros(6,"Juan");
    escribirAlumnos(pAlumno,2);
    leerAlumnos(pAlumno,"alumnos.bin");
    mostrarAlumnos(pAlumno,2);
    return 0;
}

eAlumno* nuevoAlumno ()
{
    eAlumno* pAlumno=NULL;
    pAlumno=(eAlumno*)malloc(sizeof(pAlumno));

    return pAlumno;
}

eAlumno* nuevoAlumnoParametros(int nota, char* nombre)
{
    eAlumno* pAlumno;

    pAlumno=nuevoAlumno();
    if(pAlumno!=NULL)
    {
        setNota(pAlumno,nota);
        setNombre(pAlumno,nombre);
    }else
    {
        printf("No se pudo cargar al alumno.\n");
    }

    return pAlumno;
}

void getNota(eAlumno* pAlumno,int* nota)
{
    *nota=pAlumno->nota;
}

void getNombre(eAlumno* pAlumno, char* nombre)
{
    strcpy(nombre,pAlumno->nombre);
}

void setNota(eAlumno* pAlumno, int nota)
{
    pAlumno->nota=nota;
}

void setNombre(eAlumno* pAlumno, char* nombre)
{
    strcpy(pAlumno->nombre,nombre);
}

void escribirAlumnos(eAlumno* pAlumno[],int tam)
{
    int i;
    FILE* pFile=NULL;
    pFile=fopen("alumnos.bin","wb");

    for(i=0;i<tam;i++)
    {
        fwrite(pAlumno[i],sizeof(eAlumno),1,pFile);
    }
    fclose(pFile);
}

void leerAlumnos(eAlumno* pAlumno[], char* path)
{
    int i;
    FILE* pFile=NULL;
    pFile=fopen(path,"rb");
    for(i=0;!feof(pFile);i++)
    {
        pAlumno[i]=nuevoAlumno();
        if(fread(pAlumno[i],sizeof(eAlumno),1,pFile)!=1)
        {
            break;
        }
    }

    fclose(pFile);
}

void mostrarAlumnos (eAlumno* pAlumno[],int tam)
{
    int i;
    eAlumno auxAlumno;

    for(i=0;i<tam;i++)
    {
        getNota(pAlumno[i],&auxAlumno.nota);
        getNombre(pAlumno[i],auxAlumno.nombre);
        printf("%s se saco %d\n",auxAlumno.nombre,auxAlumno.nota);
    }
}



///********************************************************************************************



//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//typedef struct
//{
//    int nota;
//    char nombre[20];
//
//}eAlumno;
//
//eAlumno* nuevoAlumno ();
//eAlumno* nuevoAlumnoParametros(int nota, char* nombre);
//void getNota(eAlumno* alumno,int* nota);
//void getNombre(eAlumno* alumno, char* nombre);
//void setNota(eAlumno* alumno, int nota);
//void setNombre(eAlumno* alumno, char* nombre);
//void escribirAlumnos(eAlumno* alumno,int tam);
//void leerAlumnos(char* path);
//
//int main()
//{
//    int i;
//    eAlumno* alumno[2];
//    alumno[0]=nuevoAlumnoParametros(10,"Pedro");
//    alumno[1]=nuevoAlumnoParametros(6,"Juan");
//
//    escribirAlumnos(alumno[0],1);
//    escribirAlumnos(alumno[1],1);
//    leerAlumnos("alumnos.bin");
//
//    return 0;
//}
//
//eAlumno* nuevoAlumno ()
//{
//    eAlumno* alumno=NULL;
//    alumno=(eAlumno*)malloc(sizeof(alumno));
//
//    return alumno;
//}
//
//eAlumno* nuevoAlumnoParametros(int nota, char* nombre)
//{
//    eAlumno* alumno;
//
//    alumno=nuevoAlumno();
//    if(alumno!=NULL)
//    {
//        setNota(alumno,nota);
//        setNombre(alumno,nombre);
//    }else
//    {
//        printf("No se pudo cargar al alumno.\n");
//    }
//
//    return alumno;
//}
//
//void getNota(eAlumno* alumno,int* nota)
//{
//    *nota=alumno->nota;
//}
//
//void getNombre(eAlumno* alumno, char* nombre)
//{
//    strcpy(nombre,alumno->nombre);
//}
//
//void setNota(eAlumno* alumno, int nota)
//{
//    alumno->nota=nota;
//}
//
//void setNombre(eAlumno* alumno, char* nombre)
//{
//    strcpy(alumno->nombre,nombre);
//}
//
//void escribirAlumnos(eAlumno* alumno,int tam)
//{
////    int i;
//    FILE* pFile=NULL;
//    pFile=fopen("alumnos.bin","wb");
//
////    for(i=0;i<tam;i++)
////    {
//        fwrite(alumno,sizeof(eAlumno),tam,pFile);
////    }
//    fclose(pFile);
//}
//
//void leerAlumnos(char* path)
//{
//    int i;
//    eAlumno* alumno;
//    FILE* pFile=NULL;
//    pFile=fopen(path,"rb");
//    while(!feof(pFile))
//    {
//        alumno=nuevoAlumno();
//        fread(alumno,sizeof(eAlumno),1,pFile);
//        i++;
//    }
//
//    fclose(pFile);
//}
