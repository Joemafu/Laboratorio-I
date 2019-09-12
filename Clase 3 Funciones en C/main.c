#include "calculadora.h"

int main()
{
    float num1;
    float num2;
    int operacion;
    float resultado;

    do
    {
        printf ("Indique que operacion quiere realizar:\n1-Sumar\n2-Restar\n3-Multiplicar\n4-Dividir\n");
        operacion = pedirNumero();

        printf ("Ingrese el primer numero:\n");
        num1 = pedirNumero();

        printf ("Ingrese el segundo numero:\n");
        num2 = pedirNumero();

        switch(operacion)
        {
        case 1:
            resultado = sumar(num1, num2);
            break;
        case 2:
            resultado = restar(num1, num2);
            break;
        case 3:
            resultado = multiplicar(num1, num2);
            break;
        case 4:
            resultado = dividir(num1, num2);
            break;
        }
    }
    while (operacion == 4 && num2 == 0);

    mostrar(resultado);

    system ("pause");

    return 0;
}
