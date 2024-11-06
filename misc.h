#ifndef MISC_H
#define MISC_H
#include <stdio.h>
#include <stdlib.h>

void menuPrincipal() {
    printf("1 - Cadastrar\n");
    printf("2 - Atendimento\n");
    printf("3 - Pesquisa\n");
    printf("4 - Desfazer\n");
    printf("5 - Carregar/Salvar\n");
    printf("6 - Sobre\n");
    printf("0 - Sair\n");
}

void menuCadastrar() {
    printf("1 - Cadastrar novo paciente\n");
    printf("2 - Consultar paciente cadastrado\n");
    printf("3 - Mostrar lista completa\n");
    printf("4 - Atualizar dados de paciente\n");
    printf("5 - Remover paciente\n");
    printf("0 - Voltar\n");
}

void menuAtendimento() {
    printf("1 - Enfileirar paciente\n");
    printf("2 - Desenfileirar paciente\n");
    printf("3 - Mostrar fila\n");
    printf("0 - Voltar\n");
}

void menuPesquisa() {
    printf("Mostrar registros ordenados por:\n");
    printf("1 - Ano de registro\n");
    printf("2 - Mes de registro\n");
    printf("3 - Dia de registro\n");
    printf("4 - Idade do paciente\n");
    printf("0 - Voltar\n");
}

void menuArquivo() {
    printf("1 - Carregar dados dos pacientes\n");
    printf("2 - Salvar dados dos pacientes\n");
    printf("0 - Voltar\n");
}

void carregar() {
}

void salvar() {

}

void sobre() {
    printf("Desenvolvedores: \n");
    printf("Nomes: Guilherme Escudeiro e Lucas Cabral\n");
    printf("Ciclo: 4º ciclo\n");
    printf("Curso: Ciencia da Computacao\n");
    printf("Disciplina: Estrutura de Dados\n");
    printf("Data: 08/11/2024\n");
}

#endif //MISC_H
