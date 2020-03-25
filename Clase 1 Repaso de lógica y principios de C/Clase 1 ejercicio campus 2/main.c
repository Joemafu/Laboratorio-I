#include <stdio.h>
#include <stdlib.h>


int main()
{

	int a;
	int b;
	int resultado;

	system("cls");

	printf("\nIngrese 1 numero: ");
	scanf("%d",&a);
	printf("\nIngrese 2 numero: ");
	scanf("%d",&b);
	resultado=a-b;

	printf("______________________________________\n");
	printf("\nEl resultado es: %d \n",resultado);
	if(resultado>=0){
        printf("\nResultado positivo \n");
	}
	if(resultado<0){
        printf("\nResultado negativo \n");
	}
	printf("______________________________________\n\n\n\n");


	return 0;
}
