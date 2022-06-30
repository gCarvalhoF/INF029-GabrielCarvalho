#include <stdio.h>

int multiply(int valor1, int valor2)
{
    if (valor2 == 1)
        return valor1;
    else
        return valor1 + multiply(valor1, valor2 - 1);
}

int main()
{
    int valor1, valor2, multiplyValor;

    printf("Informe um número: ");
    scanf("%d", &valor1);
    printf("Informe outro número: ");
    scanf("%d", &valor2);

    multiplyValor = multiply(valor1, valor2);
    printf("multiply: %d", multiplyValor);
}