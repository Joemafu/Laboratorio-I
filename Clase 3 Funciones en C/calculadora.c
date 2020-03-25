#include "calculadora.h"

float pedirNumero()
{
    float num;
    scanf("%f", &num);
    return num;
}
float sumar(float num1, float num2)
{
    float resultado;
    resultado = num1 + num2;
    return resultado;
}
float restar(float num1, float num2)
{
    float resultado;
    resultado = num1 - num2;
    return resultado;
}
float multiplicar(float num1, float num2)
{
    float resultado;
    resultado = num1 * num2;
    return resultado;
}
float dividir(float num1, float num2)
{
    float resultado;
    resultado = (float) num1 / (float) num2;
    if(num2 == 0){
        printf("No es posible dividir por 0.\n\n");
    }
    return resultado;
}
void mostrar(float resultado)
{
    printf("El resultado es: %.2f\n", resultado);
    return;
}
