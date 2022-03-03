class Pessoa():
    def __init__(self, nome, matricula, cpf, sexo, dataNascimento):
        self.nome = nome
        self.matricula = matricula
        self.cpf = cpf
        self.sexo = sexo
        self.dataNascimento = dataNascimento

    def __str__(self):
        return self.nome

def cadastroPessoas():
    pessoas = []
    nome = input("Nome: ")
    matricula = input("Matricula: ")
    cpf = input("Cpf: ")
    sexo = input("Sexo: ")
    dataNascimento = input("DataNascimento: ")

    pessoa = Pessoa(nome, matricula, cpf, sexo, dataNascimento)
    pessoas.append(pessoa)

    return pessoas


alunos = []
alunos.append(cadastroPessoas())

print(alunos)
