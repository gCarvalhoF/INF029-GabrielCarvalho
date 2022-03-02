#include <stdio.h>
#include <string.h>
#define TAM_ALUNOS 50
#define TAM_PROFESSORES 50
#define TAM_DISCIPLINAS 50

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char nome[31];
    char matricula[15];
    char cpf[14];
    char sexo;
    Data dataNascimento;
} Pessoa;

typedef struct
{
    char professor[100];
    char codigo[6];
    char nome[100];
    int semestre;
    Pessoa alunos[100];

} Disciplina;

void apagarCadastro(){};

void atualizarCadastro(){};

void cadastroPessoas()
{
    Pessoa alunos[TAM_ALUNOS];
    Pessoa professores[TAM_PROFESSORES];

    int option, i, j;
    char continuar;
    int length = sizeof(alunos) / sizeof(alunos[0]);

    printf("O que deseja cadastrar? \n\t1 - Alunos \n\t2 - Professores\n");

    printf(">> ");
    scanf("%d", &option);
    getchar();

    if (option == 1)
    {
        for (i = 0; i < 1; i++)
        {
            printf("Nome do aluno: ");
            fgets(alunos[i].nome, 31, stdin);
            size_t ln = strlen(alunos[i].nome) - 1; //size_t = unsigned integer type
            if (alunos[i].nome[ln] == '\n')
                alunos[i].nome[ln] = '\0'; // caracter de final de string
            fflush(stdin);

            printf("Digite o CPF: ");
            fgets(alunos[i].cpf, 14, stdin);
            ln = strlen(alunos[i].cpf) - 1;
            if (alunos[i].cpf[ln] == '\n')
                alunos[i].cpf[ln] = '\0';
            fflush(stdin);

            printf("Matrícula do aluno: ");
            fgets(alunos[i].matricula, 14, stdin);
            ln = strlen(alunos[i].matricula) - 1;
            if (alunos[i].matricula[ln] == '\n')
                alunos[i].matricula[ln] = '\0';
            fflush(stdin);

            printf("Digite o sexo: ");
            scanf("%c", &alunos[i].sexo);
            fflush(stdin);

            printf("Data de nascimento\n");

            printf("Dia: ");
            scanf("%d", &alunos[i].dataNascimento.dia);
            fflush(stdin);

            printf("Mês: ");
            scanf("%d", &alunos[i].dataNascimento.mes);
            fflush(stdin);

            printf("Ano: ");
            scanf("%d", &alunos[i].dataNascimento.ano);
            fflush(stdin);

            puts(alunos[i].nome);
            puts(alunos[i].matricula);
            puts(alunos[i].cpf);
            printf("%c \n", alunos[i].sexo);
            printf("%02d / %02d / %d", alunos[i].dataNascimento.dia, alunos[i].dataNascimento.mes, alunos[i].dataNascimento.ano);
            // printf("Deseja cadastrar outro aluno(a)?\n");
            // scanf("%c", &continuar);
        }
    }
};

void main()
{
    cadastroPessoas();
}
