#include <stdio.h>
#include <stdlib.h>

double inverte(int n);
double inverteS(int n);

int main()
{
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    getchar();

    printf("Numero invertido: %.0lf", inverteS(num));
}

double inverte(int n)
{
    double aux;

    if (n <= 9)
    {
        return n;
    }
    else
    {
        aux = (n % 10) * pow(10, abs(log10(n)));
        return aux + inverte(n / 10);
    }
}

double inverteS(int n)
{
    if (n < 0)
    {
        return -1 * inverte(n * -1);
    }
    return inverte(n);
}