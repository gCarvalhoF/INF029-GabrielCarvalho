
#include <stdio.h>
#include <stdlib.h>

int somaN(int n);

int main()
{
    int num, resultado;
    printf("Informe o numero");
    scanf("%d", &num);
    getchar();

    printf("Resultado: %d", somaN(num));
}

int somaN(int n)
{
    if (n == 1)
        return n;
    else
        return n + somaN(n - 1);
}