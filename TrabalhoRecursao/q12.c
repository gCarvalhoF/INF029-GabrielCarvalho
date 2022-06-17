#include <stdio.h>

void imprimeCrescente(int valor){
  if (valor > 0)
    imprimeCrescente(valor - 1);
  
  printf("%d ", valor);

}

int main(){
  int valor;

  printf("Informe um número: ");
  scanf("%d", &valor);
  
  imprimeCrescente(valor);
}