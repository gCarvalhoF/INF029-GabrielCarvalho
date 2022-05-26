#include <stdio.h>
#include <string.h>
#include <math.h>
#include "GabrielCarvalho20212160051.h"
#define ANO_ATUAL 22
#define QTD_DATAS 2

// Datas - q1 e q2
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
  else
    return -1;

  return intValue;
}

int getValidDMA(char data[])
{
  int i, j, barraCount;


  data.ano = 0;
  datas[i].mes = 0;
  datas[i].dia = 0;
  datas[i].bissexto = 0;

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

  return 1;
}

int qtdDiasMes(int mes, int bissexto)
{

  if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    return 31;

  if (mes == 2 && bissexto == 0)
    return 28;
  else if (mes == 2 && bissexto == 1)
  {
    return 29;
  }

  if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    return 30;
}

int q1(char data[])
{
  int valido = 0;

  if (getValidDMA(datas) < 0)
  {
    valido = 0;
    return valido;
  }

  
  if (datas[i].ano < 100 && datas[i].ano > ANO_ATUAL)
  {
    datas[i].ano += 2000;
  }

  if (datas[i].ano % 400 == 0)
  {
    datas[i].bissexto = 1;
  }
  else if (datas[i].ano % 4 == 0 && datas[i].ano % 100 != 0)
  {
    datas[i].bissexto = 1;
  }

  if (datas[i].bissexto == 1 && datas[i].mes == 2 && datas[i].dia <= 29)
    valido = 1;
  else if (datas[i].bissexto == 0 && datas[i].mes == 2 && datas[i].dia < 28)
  {
    valido = 1;
  }
  else if (datas[i].bissexto == 0 && datas[i].mes == 2 && datas[i].dia > 28)
  {
    valido = 0;
    return valido;
  }

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

int q2(Data datas[], int *qtdDias, int *qtdMeses, int *qtdAnos)
{
  int i;
  q1(datas, 2);

  Data dataUnica[1];
  for (i = 0; i < 2; i++)
  {
    strcpy(dataUnica[0].dataStr, datas[i].dataStr);

    if (i == 0 && q1(dataUnica, 1) == 0)
      return 2;
    else if (i == 1 && q1(dataUnica, 1) == 0)
      return 3;
  }

  *qtdDias = datas[1].dia - datas[0].dia;
  *qtdMeses = datas[1].mes - datas[0].mes;
  *qtdAnos = datas[1].ano - datas[0].ano;

  if (*qtdMeses < 0)
  {
    *qtdAnos--;
    *qtdMeses += 12;
  }

  if (*qtdDias < 0)
  {
    *qtdMeses--;
    *qtdDias = qtdDiasMes(datas[0].mes, datas[1].bissexto) - datas[0].dia + datas[1].dia;
  }

  if (*qtdDias < 0 || *qtdMeses < 0 || *qtdAnos < 0)
    return 4;
  return 1;
}

// Textos - q3 e q4
#define TAM_TEXTO 250

int q3(char texto[], char letra, int isCaseSensitive)
{
  int i;
  int qtd_letras = 0;
  char letraCase = letra;

  if (isCaseSensitive != 1)
  {
    if ((letra >= 65) && (letra <= 90))
    {
      letraCase -= ('A' - 'a');
    }
    else if ((letra >= 97) && (letra <= 122))
    {
      letraCase += ('A' - 'a');
    }
  }

  for (i = 0; i < strlen(texto); i++)
  {

    if (letra == texto[i] || (letraCase == texto[i] && isCaseSensitive != 1))
    {
      qtd_letras++;
    }
  }
  return qtd_letras;
}

int q4(char texto[], char palavra[], int posicoes[])
{
  int tam_palavra = strlen(palavra);
  int tam_text = strlen(texto);
  int i, j, k;
  int ocorrencias = 0, acentos = 0;
  int pIn, pFin;

  for (i = 0; i < tam_text; i++)
  {

    if (texto[i] < 0 && texto[i + 1] < 0)
    {
      acentos++;
    }
    if (texto[i] == palavra[j])
    {
      j++;

      if (j == tam_palavra)
      {
        pIn = ocorrencias * 2;
        pFin = ocorrencias * 2 + 1;

        posicoes[pIn] = i - j + 2;
        posicoes[pFin] = i + 1 - acentos;

        ocorrencias++;
        j = 0;
      }
    }
    else
      j = 0;
  }

  return ocorrencias;
}

// Numeros - q5 e q6

int q5(int numero)
{
  int inverso;
  int mNum, cNum, dNum, uNum;
  int mInv, cInv, dInv, uInv;

  mNum = numero / 1000;
  cNum = (numero % 1000) / 100;
  dNum = (numero % 100) / 10;
  uNum = numero % 10;

  mInv = uNum * 1000;
  cInv = dNum * 100;
  dInv = cNum * 10;
  uInv = mNum;

  inverso = mInv + cInv + dInv + uInv;

  if (inverso % 1000 == 0)
    inverso = inverso / 1000;
  else if (inverso % 100 == 0)
    inverso = inverso / 100;
  else if (inverso % 10 == 0)
    inverso = inverso / 10;

  return inverso;
}

int acharUnidade(int valor)
{
  int unidade = 1;

  while (unidade <= valor)
    unidade *= 10;
  unidade = unidade / 10;

  return unidade;
}

int q6(int valor, int numeroBusca)
{
  int unidadesValor = 1, unidadesNumeroBusca = 1;
  int ocorrencias = 0;
  int resto = -1;
  int i, j;

  unidadesValor = acharUnidade(valor);
  unidadesNumeroBusca = acharUnidade(numeroBusca);

  while (unidadesValor >= unidadesNumeroBusca)
  {
    resto = (valor / (unidadesValor / unidadesNumeroBusca));
    if (resto == numeroBusca)
    {
      ocorrencias++;
      unidadesValor /= unidadesNumeroBusca;
      valor %= unidadesValor;
    }
    else
    {
      valor %= unidadesValor;
      unidadesValor /= 10;
    }
  }
  return ocorrencias;
}