#include "GabrielCarvalho20212160051.h"
#include <stdio.h>
#include <string.h>

void testQ1();
void testQ2();
void testQ3();
void testQ4();
void testQ5();
void testQ6();

int main()
{
    // printf("q1\n");
    // testQ1(); // 10 testes
    // printf("q2\n");
    // testQ2(); // 35 testes
    // printf("q3\n");
    // testQ3();
    printf("q5\n");
    testQ5();
}

void testQ1()
{
    char str[11];
    Data data[1];
    strcpy(data[0].dataStr, "29/02/2015");
    printf("%d\n", validarDatas(data, 1) == 0);

    strcpy(data[0].dataStr, "29/02/2012");
    printf("%d\n", validarDatas(data, 1) == 1);

    strcpy(data[0].dataStr, "9/13/2014");
    printf("%d\n", validarDatas(data, 1) == 0);

    strcpy(data[0].dataStr, "45/4/2014");
    printf("%d\n", validarDatas(data, 1) == 0);

    strcpy(data[0].dataStr, "12/1/15");
    printf("%d\n", validarDatas(data, 1) == 1);

    strcpy(data[0].dataStr, "1/9/2016");
    printf("%d\n", validarDatas(data, 1) == 1);

    strcpy(data[0].dataStr, "//2016");
    printf("%d\n", validarDatas(data, 1) == 0);

    strcpy(data[0].dataStr, "1//20");
    printf("%d\n", validarDatas(data, 1) == 0);

    strcpy(data[0].dataStr, "1/R/2016");
    printf("%d\n", validarDatas(data, 1) == 0);

    strcpy(data[0].dataStr, "1/12/19");
    printf("%d\n", validarDatas(data, 1) == 1);
}

void testQ2()
{
    char datainicial[11], datafinal[11];
    Data datas[2];
    int qtdDias, qtdMeses, qtdAnos;
    int retorno;

    // teste 1
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datas[0].dataStr, "01/06/2015");
    strcpy(datas[1].dataStr, "01/06/2016");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 0);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 1);
    printf("\n------------------------\n");

    // teste 2 - retornos
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datas[0].dataStr, "01/30/2015");
    strcpy(datas[1].dataStr, "01/06/2016");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 2);
    printf("\n------------------------\n");

    strcpy(datas[0].dataStr, "01/3/2015");
    strcpy(datas[1].dataStr, "40/06/2016");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 3);
    printf("\n------------------------\n");

    strcpy(datas[0].dataStr, "01/06/2016");
    strcpy(datas[1].dataStr, "01/06/2015");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 4);
    printf("\n------------------------\n");

    // teste 3
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datas[0].dataStr, "06/06/2017");
    strcpy(datas[1].dataStr, "07/07/2017");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 1);
    printf("%d\n", qtdMeses == 1);
    printf("%d\n", qtdAnos == 0);
    printf("\n------------------------\n");

    // teste 4
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datas[0].dataStr, "06/06/2017");
    strcpy(datas[1].dataStr, "05/07/2018");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 29);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 1);
    printf("\n------------------------\n");

    // teste 5
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datas[0].dataStr, "26/07/2017");
    strcpy(datas[1].dataStr, "25/08/2017");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 30);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 0);
    printf("\n------------------------\n");

    // teste 6
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datas[0].dataStr, "26/06/2017");
    strcpy(datas[1].dataStr, "26/07/2017");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 0);
    printf("%d\n", qtdMeses == 1);
    printf("%d\n", qtdAnos == 0);
    printf("\n------------------------\n");

    // teste 8
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datas[0].dataStr, "27/02/2016");
    strcpy(datas[1].dataStr, "03/03/2017");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 4);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 1);
    printf("\n------------------------\n");

    // teste 9
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datas[0].dataStr, "27/02/2015");
    strcpy(datas[1].dataStr, "03/03/2016");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno);
    printf("%d\n", qtdDias == 5);
    printf("%d\n", qtdMeses == 0);
    printf("%d\n", qtdAnos == 1);
    printf("\n------------------------\n");

    // teste 10
    qtdDias = -1;
    qtdMeses = -1;
    qtdAnos = -1;

    strcpy(datas[0].dataStr, "28/01/2016");
    strcpy(datas[1].dataStr, "29/02/2016");
    retorno = calcDistDatas(datas, &qtdDias, &qtdMeses, &qtdAnos);
    printf("%d\n", retorno == 1);
    printf("%d\n", qtdDias == 1);
    printf("%d\n", qtdMeses == 1);
    printf("%d\n", qtdAnos == 0);
    printf("\n------------------------\n");
}

void testQ3()
{
    char str[250];
    strcpy(str, "Renato Lima Novais");
    printf("%d\n", qtdLetras(str, 'a', 0) == 3);
    printf("%d\n", qtdLetras(str, 'b', 0) == 0);
    printf("%d\n", qtdLetras(str, 'l', 1) == 0);
    printf("%d\n", qtdLetras(str, 'l', 0) == 1);
    printf("%d\n", qtdLetras(str, 'L', 0) == 1);

    strcpy(str, "Letícia, signifiCa fEliCIdADE");
    printf("%d\n", qtdLetras(str, 'c', 0) == 3);
    printf("%d\n", qtdLetras(str, 'C', 0) == 3);
    printf("%d\n", qtdLetras(str, 'c', 1) == 1);
    printf("%d\n", qtdLetras(str, 'C', 1) == 2);
    printf("%d\n", qtdLetras(str, 'R', 0) == 0);
    printf("%d\n", qtdLetras(str, 'e', 0) == 3);
    printf("%d\n", qtdLetras(str, 'E', 1) == 2);
    printf("%d\n", qtdLetras(str, 'S', 1) == 0);
}

void testQ5()
{
    printf("%d\n", inverterNumero(345) == 543);
    printf("%d\n", inverterNumero(78) == 87);
    printf("%d\n", inverterNumero(3) == 3);
    printf("%d\n", inverterNumero(5430) == 345);
    printf("%d\n", inverterNumero(1000) == 1);
    printf("%d\n", inverterNumero(0) == 0);
    printf("%d\n", inverterNumero(707) == 707);
    printf("%d\n", inverterNumero(80) == 8);
    printf("%d\n", inverterNumero(8) == 8);
    printf("%d\n", inverterNumero(1234) == 4321);
}
