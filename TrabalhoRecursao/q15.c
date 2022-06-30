#include <stdio.h>

void imprimeDecrescente(int valorF)
{
    if (0 < valorF)
    {
        printf("%d ", valorF);
        imprimeDecrescente(valorF - 2);
    }
}

int main()
{
    int valorF;

    printf("Informe o primeiro número: ");
    scanf("%d", &valorF);

    imprimeDecrescente(valorF);
}