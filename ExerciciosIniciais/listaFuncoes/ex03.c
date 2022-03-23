#include <stdio.h>

int fat(int value1){
  if (value1 == 0 )
    return 1;
  else if(value1 < 0)
    return -1;
  else
    return value1 * fat(value1 - 1);
}

void main(){
  int value1, fatorial;
  
  scanf("%d", &value1);
  
  fatorial = fat(value1);

  if (fatorial == -1){
    printf("Nâo é possível calcular o fatorial desse valor");

  }
  else{
    printf("Resultado: %d", fatorial);
  }
}