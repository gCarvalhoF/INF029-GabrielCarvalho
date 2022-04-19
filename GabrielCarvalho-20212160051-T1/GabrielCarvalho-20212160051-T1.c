#include <stdio.h>
#include "datas.c"

void main()
{
  int option;

  printf("O que deseja fazer?");
  printf("\n1- Calcular a distancia entre duas datas");
  printf("\n2- Contagem de letras em um texto");
  printf("\n3- Descobrir em quais posicoes do texto uma letra aparece \n");
  scanf("%d", &option);

  switch (option)
  {
  case 1:
    mainDatas();
    break;

  default:
    printf("Finalizando trabalho 1...");
    break;
  }
}