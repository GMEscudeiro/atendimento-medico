#ifndef MISC_H
#define MISC_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


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
    printf("2 - Mês de registro\n");
    printf("3 - Dia de registro\n");
    printf("4 - Idade do paciente\n");
    printf("0 - Voltar\n");
}

void menuArquivo() {
    printf("1 - Carregar dados dos pacientes\n");
    printf("2 - Salvar dados dos pacientes\n");
    printf("0 - Voltar\n");
}


int salvar(Lista *lista, char nome[]) {
    FILE *arquivo = fopen(nome, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    ELista *atual = lista->inicio;
    while (atual != NULL) {
        fprintf(arquivo, "Nome: %s, Idade: %d, RG: %s, Data de Entrada: %02d/%02d/%04d\n",
                atual->dados->nome, atual->dados->idade, atual->dados->rg,
                atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
        atual = atual->proximo;
    }

    fclose(arquivo);
    printf("Dados salvos no arquivo.\n");
    return 0;
}


int carregar(Lista *lista, char nome[]) {
    FILE *arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo '%s' para leitura.\n", nome);
        return 1;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        Registro *registro = malloc(sizeof(Registro));
        registro->entrada = malloc(sizeof(Data));

        if (sscanf(linha, "Nome: %[^,], Idade: %d, RG: %[^,], Data de Entrada: %d/%d/%d",
                   registro->nome, &registro->idade, registro->rg,
                   &registro->entrada->dia, &registro->entrada->mes, &registro->entrada->ano) != 6) {
            printf("Erro ao ler linha: '%s'\n", linha);
            free(registro->entrada);
            free(registro);
            continue;
        }

        ELista *novo = inicializar_elista(registro);
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->qtde++;
    }

    fclose(arquivo);
    printf("Dados da lista carregados do arquivo.\n");
    return 0;
}


void sobre() {
    printf("Desenvolvedores:\n");
    printf("Nomes: Guilherme Escudeiro e Lucas Cabral\n");
    printf("Ciclo: 4º ciclo\n");
    printf("Curso: Ciência da Computação\n");
    printf("Disciplina: Estrutura de Dados\n");
}

#endif // MISC_H
