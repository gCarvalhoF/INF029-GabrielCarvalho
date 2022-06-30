#include <stdio.h>

int somatoria(int valor)
{
    if (valor == 1)
        return 1;
    else
        return valor + somatoria(valor - 1);
}

int main()
{
    int valor, somatoriaValor;

    printf("Informe um número: ");
    scanf("%d", &valor);

    somatoriaValor = somatoria(valor);
    printf("Somatoria: %d", somatoriaValor);
}