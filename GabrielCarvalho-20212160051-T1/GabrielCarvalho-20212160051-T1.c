#include <stdio.h>
#include "datas.c"
#include "texto.c"

void main()
{
  int option;

  printf("O que deseja fazer?");
  printf("\n1- Calcular a distancia entre duas datas");
  printf("\n2- Tratamento de textos");
  printf("\n3- Tratamento de numeros\n");
  scanf("%d", &option);

  switch (option)
  {
  case 1:
    mainDatas();
    break;
  case 2:
    mainTexto();
    break;

  default:
    printf("Finalizando trabalho 1...");
    break;
  }
}