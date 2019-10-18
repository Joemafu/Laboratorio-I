#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* miVector;
    int x;
    int* auxMiVector;

    miVector=(int*)malloc(sizeof(int)*5);

    if(miVector!=NULL)
    {
        for(x=0;x<5;x++)
        {
            *(miVector+x)=x+1;
        }
        for(x=0;x<5;x++)
        {
            printf("%d\n",*(miVector+x));
        }
    }
    else
    {
        printf("No encontre espacio.\n");
    }

    auxMiVector = (int*) realloc(miVector,sizeof(int)*10);
    printf("Pido mas espacio.\n");

    if (auxMiVector!=NULL)
    {
        miVector=auxMiVector;
        for(x=5;x<10;x++)
        {
            *(miVector+x)=x+1;
        }
        for(x=0;x<10;x++)
        {
            printf("%d\n",*(miVector+x));
        }
    }
    else
    {
        printf("No encontre espacio para ampliar.\n");
    }

    miVector = (int*) realloc(miVector,sizeof(int)*3);
    printf("Reduzco espacio.\n");

    for(x=0;x<3;x++)
    {
        printf("%d\n",*(miVector+x));
    }

    return 0;
}
