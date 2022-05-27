#ifndef GABRIELCARVALHO20212160051_H
#define GABRIELCARVALHO20212160051_H

// Data - q1 e q2
typedef struct
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;
} DiasMesesAnos;

typedef struct
{
    char dataStr[11];
    int dia;
    int mes;
    int ano;
    int bissexto;
    int valido;
    DiasMesesAnos dma;
} Data;

int convStrInt(char charValue);
Data getValidDMA(char dataStr[]);
int qtdDiasMes(int mes, int bissexto);
int q1(char data[]);
DiasMesesAnos q2(char dataInicialStr[], char dataFinalStr[]);

// Texto - q3 e q4
int q3(char texto[], char letra, int isCaseSensitive);
int q4(char texto[], char palavra[], int posicoes[]);

// Numeros - q5 e q6
int q5(int numero);
int acharUnidade(int valor);
int q6(int valor, int numeroBusca);
#endif