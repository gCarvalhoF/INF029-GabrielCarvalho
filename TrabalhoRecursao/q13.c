#include <stdio.h>

void imprimeDecrescente(int valor){
  printf("%d ", valor);
  
  if (valor > 0)
    imprimeDecrescente(valor - 1);
  

}

int main(){
  int valor;

  printf("Informe um número: ");
  scanf("%d", &valor);
  
  imprimeDecrescente(valor);
}