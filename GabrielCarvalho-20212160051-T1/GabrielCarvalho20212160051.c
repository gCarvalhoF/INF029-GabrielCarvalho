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

Data getValidDMA(char dataStr[])
{
  int i, j, barraCount;
  Data data;

  data.ano = 0;
  data.mes = 0;
  data.dia = 0;
  data.bissexto = 0;

  barraCount = 0;
  for (j = 0; j < 11; j++)
  {
    if (data.dataStr[j] == '/')
    {
      barraCount++;
      continue;
    }

    if (barraCount == 0 && data.dataStr[j] != '/' && data.dataStr[j + 1] != '/')
    {
      data.dia = convStrInt(data.dataStr[j]) * 10 + convStrInt(data.dataStr[j + 1]);
    }
    else if (data.dia == 0)
    {
      data.dia = convStrInt(data.dataStr[j]);
    }

    if (barraCount == 1 && data.dataStr[j] != '/' && data.dataStr[j + 1] != '/')
    {
      data.mes = convStrInt(data.dataStr[j]) * 10 + convStrInt(data.dataStr[j + 1]);
    }
    else if (barraCount == 1 && data.mes == 0)
    {
      data.mes = convStrInt(data.dataStr[j]);
    }

    if (barraCount == 2 && data.dataStr[j] != '/' && data.ano == 0 && data.dataStr[j + 2] != '\n')
    {
      data.ano = convStrInt(data.dataStr[j]) * 1000 + convStrInt(data.dataStr[j + 1]) * 100 + convStrInt(data.dataStr[j + 2]) * 10 + convStrInt(data.dataStr[j + 3]);
    }
    else if (barraCount == 2 && data.ano == 0 && data.dataStr[j + 2] == '\n')
    {
      data.ano = convStrInt(data.dataStr[j]) * 10 + convStrInt(data.dataStr[j + 1]);
    }
  }

  data.valido = 1;
  return data;
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

int q1(char dataStr[])
{
  int valido = 0;
  Data data = getValidDMA(dataStr);

  if (data.valido < 0)
  {
    valido = 0;
    return valido;
  }

  if (data.ano < 100 && data.ano > ANO_ATUAL)
  {
    data.ano += 2000;
  }

  if (data.ano % 400 == 0)
  {
    data.bissexto = 1;
  }
  else if (data.ano % 4 == 0 && data.ano % 100 != 0)
  {
    data.bissexto = 1;
  }

  if (data.bissexto == 1 && data.mes == 2 && data.dia <= 29)
    valido = 1;
  else if (data.bissexto == 0 && data.mes == 2 && data.dia < 28)
  {
    valido = 1;
  }
  else if (data.bissexto == 0 && data.mes == 2 && data.dia > 28)
  {
    valido = 0;
    return valido;
  }

  if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12)
    if (data.dia > 0 && data.dia <= 31)
      valido = 1;
  if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11)
    if (0 < data.dia && data.dia <= 30)
      valido = 1;
  if (data.dia < 0 || data.dia > 31 || data.mes > 12 || data.mes < 0)
  {
    valido = 0;
    return valido;
  }

  return valido;
}

DiasMesesAnos q2(char dataInicialStr[], char dataFinalStr[])
{
  int i;
  Data data;
  Data dataInicial = getValidDMA(dataInicialStr);
  Data dataFinal = getValidDMA(dataFinalStr);

  if (dataInicial.valido == 0)
    data.dma.retorno = 2;
  else if (dataFinal.valido == 0)
    data.dma.retorno = 3;

  data.dma.qtdDias = dataFinal.dia - dataInicial.dia;
  data.dma.qtdMeses = dataFinal.mes - dataInicial.mes;
  data.dma.qtdAnos = dataFinal.ano - dataInicial.ano;

  if (data.dma.qtdMeses < 0)
  {
    data.dma.qtdAnos--;
    data.dma.qtdMeses += 12;
  }

  if (data.dma.qtdDias < 0)
  {
    data.dma.qtdMeses--;
    data.dma.qtdDias = qtdDiasMes(dataInicial.mes, dataFinal.bissexto) - dataInicial.dia + dataFinal.dia;
  }

  if (data.dma.qtdDias < 0 || data.dma.qtdMeses < 0 || data.dma.qtdAnos < 0)
    data.dma.retorno = 4;
  data.dma.retorno = 1;
  return data.dma;
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