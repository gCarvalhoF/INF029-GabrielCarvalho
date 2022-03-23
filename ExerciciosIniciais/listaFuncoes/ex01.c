#include <stdio.h>

int sum(int value1, int value2){
  return value1 + value2;
}

void main(){
  int value1, value2, soma;
  
  scanf("%d", &value1);
  scanf("%d", &value2);
  
  soma = sum(value1, value2);

  printf("Resultado: %d", soma);
}