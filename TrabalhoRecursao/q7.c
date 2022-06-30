#include <stdio.h>
#include <stdlib.h>

int MDC(int a, int b);

int main()
{
    int x, y;

    printf("Digite o valor de X: ");
    scanf("%d", &x);
    getchar();

    printf("Digite o valor de y: ");
    scanf("%d", &y);
    getchar();

    printf("Resultado %d", MDC(x, y));
}

int MDC(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    MDC(b, a % b);
}