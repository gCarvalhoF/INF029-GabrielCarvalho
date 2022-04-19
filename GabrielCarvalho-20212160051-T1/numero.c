#include <stdio.h>
#include <math.h>

int inverterNumero(int numero)
{
    int numero;
    int inverso;
    int mNum, cNum, dNum, uNum;
    int mInv, cInv, dInv, uInv;

    mNum = numero / 1000;
    cNum = (numero % 1000) / 100;
    dNum = (numero % 100) / 10;
    uNum = numero % 10;

    mInv = uNum * 1000;
    cInv = dNum * 100;
    dInv = cNum * 10;
    uInv = mNum;

    inverso = mInv + cInv + dInv + uInv;
    return inverso
}

splitValor(int valor, int valorArr[])
{
    int i;

    for (i = 0; valor > 0; i++)
    {
        valorArr[i] = (valor % pow(10, i)) / pow(10, i - 1);
    }
}

contarValor(int numero, int valor)
{
}

void main()
{
    int inverso, numero;

    printf("Informe o número para inverte-lo: ");
    scanf("%d", &numero);

    inverso = inverterNumero(numero);

    printf("O inverso de %04d: %04d", numero, inverso);
}