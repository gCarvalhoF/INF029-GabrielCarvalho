#include <stdio.h>


int sum(int value1, int value2){
  return value1 + value2;
}

int sub(int value1, int value2){
  return value1 - value2;
}

int mult(int value1, int value2){
  return value1 * value2;
}

void main(){
  int valueSum, valueSub, valueMult;
  int value1, value2, value3, value4;

  scanf("%d", &value1);
  scanf("%d", &value2);
  valueSum = sum(value1, value2);
  
  scanf("%d", &value3);
  scanf("%d", &value4);
  valueSub = sub(value3, value4);

  valueMult = mult(valueSum, valueSub);

  printf("(%d + %d) * (%d - %d) = %d", value1, value2, value3, value4, valueMult);
}