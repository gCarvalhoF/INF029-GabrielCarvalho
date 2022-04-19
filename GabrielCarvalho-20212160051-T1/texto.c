#include <stdio.h>
#include <string.h>
#define TAM_TEXTO 250

int qtdLetras(char texto[], char letra)
{
    int i;
    int qtd_letras = 0;

    for (i = 0; i < strlen(texto); i++)
    {

        if (letra == texto[i])
        {
            qtd_letras++;
        }
    }
    return qtd_letras;
}

int detectarPalavra(char texto[], char palavra[])
{
    int tam_palavra = strlen(palavra) - 1;
    int tam_text = strlen(texto) - 1;
    int i, j, k;

    for (i = 0; i <= tam_text; i++)
    {
        for (j = 0; j <= tam_palavra; j++)
        {
            if (texto[i] != palavra[j])
                break;

            if (texto[i] == palavra[j] && texto[i + tam_palavra] == palavra[j + tam_palavra])
                for (k = 0; k <= tam_palavra; k++)
                {
                    if (texto[k] != palavra[k])
                        break;
                }

            printf("A palavra '%s' aparece no texto nas posicoes: \nPosicao inicial: %d \nPosicao final: %d", palavra, i + 1, i + tam_palavra);
        }
    }
}

void mainTexto()
{
    char texto[TAM_TEXTO], palavra[TAM_TEXTO];
    char letra;
    int qtd_letras, option;

    printf("Informe o texto que deseja analisar: \n");
    fgets(texto, TAM_TEXTO, stdin);
    int ln = strlen(texto) - 2;
    texto[ln] = '\0';

    printf("O que deseja fazer com esse texto? \n1- Contar a quatidade de uma certa letra \n2- Procurar uma palavra específica\n");
    scanf("%d", &option);

    if (option == 1)
    {
        printf("Agora, informe a letra que deseja contar: ");
        getchar();
        scanf("%c", &letra);

        qtd_letras = qtdLetras(texto, letra);
        printf("%c aparece %d vezes", letra, qtd_letras);
    }
    else
    {
        printf("Agora, informe a palavra a ser procurada: ");
        getchar();
        fgets(palavra, TAM_TEXTO, stdin);
        int ln = strlen(palavra) - 2;
        texto[ln] = '\0';

        detectarPalavra(texto, palavra);
    }
}