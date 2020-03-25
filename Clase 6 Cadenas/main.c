#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /**<
    strlen //string length
    strcpy //string copy
    strupr //string uppercase
    strlwr //string lowercase
    strcmp //string compare
    stricmp //string ignore compare
    strcat //string concatenate
    */

    /**<
    char palabra[10];
    char palabra2[10];
    int lenght;
    int comp;
    char todo[50];
    printf("Ingrese una palabra : ");

    gets(palabra);
    lenght = strlen(palabra);
    printf("la palabra es %s y el largo es %d", palabra, lenght);
    strcpy(palabra2, "perro");
    printf("\nla palabra copiada es %s", palabra2);

    if (stricmp(palabra, palabra2)==0) //Compara los dos strings ignorando mayusculas. Devuelve 0 si son iguales, 1 o -1 si son diferentes.
    {
        printf("Son iguales.\n");
    }
    else
    {
        printf("Son diferentes.\n");
    }

    strcat(todo,palabra); //Concatena string "todo" con string "palabra". "todo" = "todopalabra".
    strcat(todo,palabra2); //Concatena. "todo" = "todopalabra2".
    strcat(todo, " chau"); //Concatena. "todo" con el literal " chau". "todo" = "todo chau"
    printf("Todo: %s\n", todo);
    */

    char nombre[15];
    char apellido[15];
    char apellidoNombre[29];
    int i;

    printf("Ingrese nombre: \n");
    scanf("%s", nombre);

    printf("Ingrese apellido: \n");
    scanf("%s", apellido);

    strcpy(apellidoNombre,apellido);
    strcat(apellidoNombre,", ");
    strcat(apellidoNombre,nombre);

    apellidoNombre[0]-=32; /**< Acá convierto a mayúscula la inicial del apellido */

    for(i=0; i<29; i++)
    {
        if (apellidoNombre[i]==32)  /**< Acá detecto el espacio */
        {
            i++; /**< voy al siguiente subíndice para modificar el char posterior al espacio (Inicial del nombre) */
            apellidoNombre[i]-=32; /**< Le resto 32 al valor ASCII para convertirlo a mayúscula como hice con la inicial del apellido. */
            break;
        }
    }

    printf("%s",apellidoNombre);

    return 0;
}
