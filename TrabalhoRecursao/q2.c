#include <stdio.h>

int fibonacci(int n) {
  int x;
  
  if (n == 1) {
    return(1);
  }
  
  if (n == 2) {
    return(1);
  }
  
  x = fibonacci(n-1) + fibonacci(n-2);
  return(x);
}


int main(){
  int qtd;

  printf("Quantos valores da seq deseja mostrar? ");
  scanf("%d", &qtd);

  printf("%d\n", fibonacci(qtd));
}