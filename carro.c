#include <stdio.h>

typedef struct{
  char marca[50];
  char modelo[50];
  int ano;
} Carro;

void lerDados(Carro *carro){
 
  printf("Informe a marca do carro: \t");
  fgets(carro->marca, 50, stdin);
  printf("Informe o modelo do carro: \t");
  fgets(carro->modelo, 50, stdin);
  printf("Informe o ano do carro: \t");
  scanf("%d", &carro->ano);

  // carro->marca = marca;
  // carro->modelo = modelo;
}

void imprimirDados(Carro *carro){
  
  printf("marca: \t%s", carro->marca);
  printf("modelo: \t%s", carro->modelo);
  printf("ano: \t%d\n", carro->ano);
}

void main(){
  Carro carro;

  lerDados(&carro);
  imprimirDados(&carro);
}