#include <stdio.h>
#define ANO_ATUAL 22
#define QTD_DATAS 2

typedef struct
{
  char dataStr[11];
  int dia;
  int mes;
  int ano;
} Data;

int convStrInt(char charValue)
{
  int intValue;

  if (charValue == '0')
    intValue = 0;
  else if (charValue == '1')
    intValue = 1;
  else if (charValue == '2')
    intValue = 2;
  else if (charValue == '3')
    intValue = 3;
  else if (charValue == '4')
    intValue = 4;
  else if (charValue == '5')
    intValue = 5;
  else if (charValue == '6')
    intValue = 6;
  else if (charValue == '7')
    intValue = 7;
  else if (charValue == '8')
    intValue = 8;
  else if (charValue == '9')
    intValue = 9;

  return intValue;
}

int getValidDMA(Data datas[], int qtd_datas)
{
  int i, j, barraCount;
  int valido = 0;

  for (i = 0; i < qtd_datas; i++)
  {
    barraCount = 0;
    for (j = 0; j < 11; j++)
    {
      if (datas[i].dataStr[j] == '/')
      {
        barraCount++;
        continue;
      }

      if (barraCount == 0 && datas[i].dataStr[j] != '/' && datas[i].dataStr[j + 1] != '/')
      {
        datas[i].dia = convStrInt(datas[i].dataStr[j]) * 10 + convStrInt(datas[i].dataStr[j + 1]);
      }
      else if (datas[i].dia == 0)
      {
        datas[i].dia = convStrInt(datas[i].dataStr[j]);
      }

      if (barraCount == 1 && datas[i].dataStr[j] != '/' && datas[i].dataStr[j + 1] != '/')
      {
        datas[i].mes = convStrInt(datas[i].dataStr[j]) * 10 + convStrInt(datas[i].dataStr[j + 1]);
      }
      else if (barraCount == 1 && datas[i].mes == 0)
      {
        datas[i].mes = convStrInt(datas[i].dataStr[j]);
      }

      if (barraCount == 2 && datas[i].dataStr[j] != '/' && datas[i].ano == 0 && datas[i].dataStr[j + 2] != '\n')
      {
        datas[i].ano = convStrInt(datas[i].dataStr[j]) * 1000 + convStrInt(datas[i].dataStr[j + 1]) * 100 + convStrInt(datas[i].dataStr[j + 2]) * 10 + convStrInt(datas[i].dataStr[j + 3]);
      }
      else if (barraCount == 2 && datas[i].ano == 0 && datas[i].dataStr[j + 2] == '\n')
      {
        datas[i].ano = convStrInt(datas[i].dataStr[j]) * 10 + convStrInt(datas[i].dataStr[j + 1]);
      }
    }

    printf("%s // %d - %d - %d \n", datas[i].dataStr, datas[i].dia, datas[i].mes, datas[i].ano);
  }
}

int validarDatas(Data datas[], int qtd_datas)
{
  getValidDMA(datas, qtd_datas);

  int valido = 0;
  for (int i = 0; i < qtd_datas; i++)
  {
    if (datas[i].ano < 100 && datas[i].ano > ANO_ATUAL)
    {
      datas[i].ano += 2000;
    }

    if (datas[i].ano % 4 == 0 && datas[i].ano % 100 != 0 && datas[i].ano % 400 == 0)
    {

      if (datas[i].mes == 2 && datas[i].dia <= 29)
        valido = 1;
      else if (datas[i].mes == 2 && 30 > datas[i].dia && datas[i].dia < 0)
      {
        valido = 0;
        return valido;
      }
    }
    else if (datas[i].mes == 2 && 0 < datas[i].dia && datas[i].dia < 29)
      valido = 1;

    if (datas[i].mes == 1 || datas[i].mes == 3 || datas[i].mes == 5 || datas[i].mes == 7 || datas[i].mes == 8 || datas[i].mes == 10 || datas[i].mes == 12)
      if (datas[i].dia > 0 && datas[i].dia <= 31)
        valido = 1;
    if (datas[i].mes == 4 || datas[i].mes == 6 || datas[i].mes == 9 || datas[i].mes == 11)
      if (0 < datas[i].dia && datas[i].dia <= 30)
        valido = 1;
    if (datas[i].dia < 0 || datas[i].dia > 31 || datas[i].mes > 12 || datas[i].mes < 0)
    {
      valido = 0;
      return valido;
    }

    return valido;
  }
}

void calcDistDatas(Data datas[], int qtd_datas)
{
  int dia = 0, mes = 0, ano = 0;

  if (datas[0].ano < datas[1].ano)
  {
    ano = datas[1].ano - datas[0].ano;
  }

  if (datas[0].mes < datas[1].mes)
  {
    mes = datas[1].mes - datas[0].mes;
  }

  if (datas[1].dia < datas[0].dia)
  {
    dia = datas[0].dia - datas[1].dia;
  }
  else if (datas[0].dia < datas[1].dia &&)
  {
    dia = datas[1].dia - datas[0].dia;
  }

  printf("\n %d dias - %d meses- %d anos \n", dia, mes, ano);
}

void main()
{
  Data datas[QTD_DATAS];
  int isValid;
  int i;

  for (i = 0; i < QTD_DATAS; i++)
  {
    printf("Informe a %d data (Formatos: dd/mm/aaaa d/m/aa d/m/aaaa) ", i + 1);
    fgets(datas[i].dataStr, 11, stdin);
    int ln = sizeof(datas[i].dataStr) / sizeof(char) - 1;
    datas[i].dataStr[ln] = '\0';
    getchar();

    datas[i].ano = 0;
    datas[i].mes = 0;
    datas[i].dia = 0;
  }
  isValid = validarDatas(datas, QTD_DATAS);

  if (isValid == 1)
  {
    calcDistDatas(datas, QTD_DATAS);
    printf("%02d / %02d / %02d é uma data válida. \n", datas[0].dia, datas[0].mes, datas[0].ano);
    printf("%02d / %02d / %02d é uma data válida.", datas[1].dia, datas[1].mes, datas[1].ano);
  }
  else
    printf("Datas inválidas.");
}