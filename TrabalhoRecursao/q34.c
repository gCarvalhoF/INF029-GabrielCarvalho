#include <stdio.h>

void imprimeCrescente(int valorI, int valorF, int pace)
{
    if (valorI < valorF)
    {
        printf("%d ", valorI);
        imprimeCrescente(valorI + pace, valorF, pace);
    }
}

int main()
{
    int valorI, valorF, pace;

    printf("Informe o primeiro número: ");
    scanf("%d", &valorI);
    printf("Informe o último número: ");
    scanf("%d", &valorF);
    printf("Informe o intervalo: ");
    scanf("%d", &pace);

    imprimeCrescente(valorI, valorF, pace);
}