#include <stdio.h>

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

void validarData(char data[], int dataValida[])
{
  int i, barraCount = 0;
  int dia = 0, mes = 0, ano = 0;

  for (i = 0; i < 10; i++)
  {
    if (data[i] == '/')
    {
      barraCount++;
      continue;
    }

    if (barraCount == 0 && data[i] != '/' && data[i + 1] != '/')
    {
      printf("Dia: %c - %c \n", data[i], data[i + 1]);
      dia = convStrInt(data[i]) * 10 + convStrInt(data[i + 1]);
    }
    else if (dia == 0)
    {
      dia = convStrInt(data[i]);
    }

    if (barraCount == 1 && data[i] != '/' && data[i + 1] != '/')
    {
      printf("Mes: %c - %c \n", data[i], data[i + 1]);
      mes = convStrInt(data[i]) * 10 + convStrInt(data[i + 1]);
    }
    else if (mes == 0)
    {
      mes = convStrInt(data[i]);
    }

    if (barraCount == 2 && data[i] != '/' && data[i + 3] != '\0')
    {
      printf("Ano: %c - %c - %c - %c \n", data[i], data[i + 1], data[i + 2], data[i + 3]);
      ano = convStrInt(data[i]) * 1000 + convStrInt(data[i + 1]) * 100 + convStrInt(data[i + 2]) * 10 + convStrInt(data[i + 3]);
    }
    else if (ano == 0)
    {
      ano = convStrInt(data[i]) * 10 + convStrInt(data[i + 1]);
    }
  }

  dataValida[0] = dia;
  dataValida[1] = mes;
  dataValida[2] = ano;
}

void main()
{
  char dataStr[11];
  int dataValida[3];

  printf("Informe a data (Formatos: dd/mm/aaaa d/m/aa d/m/aaaa) ");
  fgets(dataStr, 11, stdin);
  int ln = sizeof(dataStr) / sizeof(char) - 1;
  if (dataStr[ln] == '\n')
    dataStr[ln] = '\0';

  printf("%d", ln);

  validarData(dataStr, dataValida);

  printf("%02d / %02d / %4d", dataValida[0], dataValida[1], dataValida[2]);
}