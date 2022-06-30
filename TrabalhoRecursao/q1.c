#include <stdio.h>

float multiply(int valor1, int valor2, int cont)
{
  if (cont == 0)
    return 1;
  else
    return valor * fat(valor - 1);
}

int main()
{
  int number;
  float fatNumber;

  printf("Informe o numero para calcular o fatorial: ");
  scanf("%d", &number);

  fatNumber = fat(number);

  printf("%d! = %f", number, fatNumber);

  return 0;
}