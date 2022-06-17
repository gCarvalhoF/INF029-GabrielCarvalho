#include <stdio.h>

float fat(int valor){
  if (valor <= 0)
    return 1;
  else
    return valor * fat(valor - 2);
}

int main(){
  int number;
  float fatNumber;

  printf("Informe o numero para calcular o fatorial: ");
  scanf("%d", &number);

  fatNumber = fat(number);

  printf("%d!! = %.2f\n", number, fatNumber);
  
  return 0;
}