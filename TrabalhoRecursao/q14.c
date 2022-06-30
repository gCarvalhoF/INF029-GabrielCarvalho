#include <stdio.h>

void imprimeCrescente(int valorF)
{
    if (0 < valorF)
    {
        imprimeCrescente(valorF - 2);
        printf("%d ", valorF);
    }
}

int main()
{
    int valorF;

    printf("Informe o primeiro número: ");
    scanf("%d", &valorF);

    imprimeCrescente(valorF);
}