#include <stdio.h>

int imprime_decrescente(int numero){
  int contador;
  if (contador <= numero){
    printf("%d\n", contador);
    contador++;
    numero = imprime_decrescente(numero);
  }
  return numero;
}

int main(){
  int numero;
  printf("Insira um numero:\n");
  scanf("%d", &numero);
  numero = imprime_decrescente(numero);

  printf("Acabou os números\n");
}