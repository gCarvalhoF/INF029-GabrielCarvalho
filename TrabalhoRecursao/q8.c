#include <stdio.h>
#include <stdlib.h>

int contaOcorrencia(int n, int k, int i);

int main()
{
    int k = 0, n = 0, i = 0;

    printf("Digite o numero K: ");
    scanf("%d", &k);
    getchar();

    printf("Digite o numero N: ");
    scanf("%d", &n);
    getchar();

    printf("o digito %d ocorre %d vezes em %d", k, contaOcorrencia(n, k, i), n);
}

int contaOcorrencia(int n, int k, int i)
{
    if (n % 10 == k)
    {
        i++;
    }
    if (n % 10 == n)
    {
        return i;
    }
    contaOcorrencia(n / 10, k, i);
}