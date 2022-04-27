#ifndef GABRIELCARVALHO20212160051_H
#define GABRIELCARVALHO20212160051_H

// Data - q1 e q2
typedef struct
{
    char dataStr[11];
    int dia;
    int mes;
    int ano;
    int bissexto;
} Data;

int convStrInt(char charValue);
int getValidDMA(Data datas[], int qtd_datas);
int qtdDiasMes(int mes, int bissexto);
int validarDatas(Data datas[], int qtd_datas);
int calcDistDatas(Data datas[], int *qtdDias, int *qtdMeses, int *qtdAnos);

// Texto - q3 e q4
int qtdLetras(char texto[], char letra, int isCaseSensitive);
int detectarPalavras(char texto[], char palavra[], int posicoes[]);

// Numeros - q5 e q6
int inverterNumero(int numero);
int acharUnidade(int valor);
int contarValor(int numeroBusca, int valor);
#endif