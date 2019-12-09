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
void getNota(eAlumno* alumno,int* nota);
void getNombre(eAlumno* alumno, char* nombre);
void setNota(eAlumno* alumno, int nota);
void setNombre(eAlumno* alumno, char* nombre);
void escribirAlumnos(eAlumno* alumno,int tam);
void leerAlumnos(char* path);

int main()
{
    int i;
    eAlumno* alumno[2];
    alumno[0]=nuevoAlumnoParametros(10,"Pedro");
    alumno[1]=nuevoAlumnoParametros(6,"Juan");

    escribirAlumnos(alumno[0],1);
    escribirAlumnos(alumno[1],1);
    leerAlumnos("alumnos.bin");

    return 0;
}

eAlumno* nuevoAlumno ()
{
    eAlumno* alumno=NULL;
    alumno=(eAlumno*)malloc(sizeof(alumno));

    return alumno;
}

eAlumno* nuevoAlumnoParametros(int nota, char* nombre)
{
    eAlumno* alumno;

    alumno=nuevoAlumno();
    if(alumno!=NULL)
    {
        setNota(alumno,nota);
        setNombre(alumno,nombre);
    }else
    {
        printf("No se pudo cargar al alumno.\n");
    }

    return alumno;
}

void getNota(eAlumno* alumno,int* nota)
{
    *nota=alumno->nota;
}

void getNombre(eAlumno* alumno, char* nombre)
{
    strcpy(nombre,alumno->nombre);
}

void setNota(eAlumno* alumno, int nota)
{
    alumno->nota=nota;
}

void setNombre(eAlumno* alumno, char* nombre)
{
    strcpy(alumno->nombre,nombre);
}

void escribirAlumnos(eAlumno* alumno,int tam)
{
//    int i;
    FILE* pFile=NULL;
    pFile=fopen("alumnos.bin","wb");

//    for(i=0;i<tam;i++)
//    {
        fwrite(alumno,sizeof(eAlumno),tam,pFile);
//    }
    fclose(pFile);
}

void leerAlumnos(char* path)
{
    int i;
    eAlumno* alumno;
    FILE* pFile=NULL;
    pFile=fopen(path,"rb");
    while(!feof(pFile))
    {
        alumno=nuevoAlumno();
        fread(alumno,sizeof(eAlumno),1,pFile);
        i++;
    }

    fclose(pFile);
}
