#include <stdio.h>
#include <math.h>

float hyperFat(int valor)
{
    if (valor == 0)
        return 1;
    else
        return pow(valor, valor) * hyperFat(valor - 1);
}

int main()
{
    int number;
    float fatNumber;

    printf("Informe o numero para calcular o fatorial: ");
    scanf("%d", &number);

    fatNumber = hyperFat(number);

    printf("%d! = %f", number, fatNumber);

    return 0;
}