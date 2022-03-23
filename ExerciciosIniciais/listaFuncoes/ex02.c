#include <stdio.h>

int sub(int value1, int value2, int value3){
  return value1 - value2 - value3;
}

void main(){
  int value1, value2, value3, subtracao;
  
  scanf("%d", &value1);
  scanf("%d", &value2);
  scanf("%d", &value3);
  
  subtracao = sub(value1, value2, value3);

  printf("Resultado: %d", subtracao);
}