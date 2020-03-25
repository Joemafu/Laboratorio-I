#include <stdio.h>
#include <stdlib.h>

float pedirNum();
float calcularArea(float);

int main()
{
    float num;
    float area;

    printf("Ingrese el radio del circulo:\n");
    num=pedirNum();
    area=calcularArea(num);
    printf("El area del circulo es %f\n",area);
    return 0;
}

float pedirNum()
{
    float num;
    scanf("%f",&num);
    return num;
}

float calcularArea(float radio)
{
    float area;
    area = radio*radio*3.141593;
    return area;
}
