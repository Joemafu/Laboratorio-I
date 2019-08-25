#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // para poder usar la funcion tolower o toupper
/*calcular promedio de edades
promedio de alturas de hombres

prueba de escritorio:
edad sexo altura
66   m    1.60
33   m    1.70
44   m    1.66
88   m    1.56
22   m    1.88*/
int main()
{
    int edad;
    int edadMasBajo;
    int edadMayor;
    int edadMenor;
    int flag;
    int contador;
    float acumuladorEdad;
    float altura;
    float alturaMayor;
    float alturaMenor;
    float altVieja;
    float altJoven;
    float promedioEdades;
    float acumuladorAltH;
    float alturaHombres;
    char cont;
    char sexo;
    char sexoMasAlto;
    flag = 0;//revisar flag para varones y flag para mujeres.
    altVieja = 0;
    altJoven = 0;
    contador = 0;
    acumuladorAltH = 0;
    acumuladorEdad = 0;

    do{
    printf("Ingrese edad:\n");
    scanf("%d",&edad);

    while (edad < 0 || edad > 105){
        printf("Ingrese una edad valida entre 0 y 105:\n");
        printf("Ingrese edad:\n");
        scanf("%d",&edad);
    }
    printf("Ingrese sexo:\n");
    fflush(stdin);
    scanf("%c",&sexo);
    sexo = tolower(sexo);// sexo = tolower (getche()); reemplazaría 3 líneas

    while (sexo != 'f' && sexo != 'm'){
        printf("Ingrese f para femenino y m para masculino:\n");
        fflush(stdin);
        scanf("%c",&sexo); //sexo = getche();
        sexo = tolower(sexo);
    }

    printf("Ingrese altura:\n");
    scanf("%f",&altura);

    while (altura < 1 || altura > 2){
        printf("Ingrese una altura valida en metros entre 1 y 2:\n");
        scanf("%f",&altura);
    }

    printf("Ingrese s para continuar:\n");
    fflush(stdin); //limpia la memoria buffer donde se almacena el enter ingresado previamente e interfiere en la toma del caracter.
    scanf("%c",&cont);

    //getch() toma el caracter sin replicarlo en consola y lo confirma automaticamene sin necesitar fflush.
    //getche() toma el caracter replicandolo en consola y lo confirma automaticamene sin necesitar fflush. (La 'e' final es por echo).
    //getchar() sería igual que scanf pero solo para caracteres.

    if (sexo == 'f' && (flag == 0 || edad > edadMayor)){
        edadMayor = edad;
        altVieja = altura;
    }
    if (flag == 0 || edad < edadMenor){
        edadMenor = edad;
        altJoven = altura;
    }
    if (flag == 0 || altura > alturaMayor){
        alturaMayor = altura;
        sexoMasAlto = sexo;
    }
    if (sexo == 'm' && (flag == 0 || altura < alturaMenor)){
        alturaMenor = altura;
        edadMasBajo = edad;
    }
    if(sexo == 'm'){
            acumuladorAltH = acumuladorAltH + altura;
    }
    acumuladorEdad = acumuladorEdad + edad;
    flag = 1;
    contador = contador + 1;

    }while (cont=='s');

    promedioEdades = (float)acumuladorEdad / contador; //(float) castea uno de los valores para que se convierta en flotante, por si estaba declarado com int
    alturaHombres = acumuladorAltH / contador;

    printf("La altura de la mujer mas vieja es de %f \n", altVieja);
    printf("La altura de la persona mas joven es de %f \n", altJoven);
    printf("El sexo de la persona mas alta es %c \n", sexoMasAlto);
    printf("La edad del hombre mas bajo es de %d \n", edadMasBajo);
    printf("El promedio de edad es de %f \n", promedioEdades);
    printf("El promedio de altura de hombres es de %f \n", alturaHombres);

    system ("pause");//si no se indica un pause la consola se cierra automáticamente al finalizar la ejecución.
    return 0;
}//%d para variables int %c para char %f para float
//\a genera un beep del mother \t genera un tab \n genera salto de línea
