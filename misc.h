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


int salvar(Lista *lista, char nome[]) {
    FILE *arquivo = fopen(nome, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    ELista *atual = lista->inicio;

    while (atual != NULL) {
        fwrite(&atual->dados, sizeof(Registro), 1, arquivo);
        atual = atual->proximo;
    }

    fclose(arquivo);
    return 0;
}


int carregar(Lista *lista, char nome[]) {
    FILE *arquivo = fopen(nome, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    Registro paciente;
    while (fread(&paciente, sizeof(Registro), 1, arquivo)) {
        Registro *novo_paciente = malloc(sizeof(Registro));
        if (novo_paciente == NULL) {
            printf("Erro ao alocar memória para o paciente.\n");
            fclose(arquivo);
            return 1;
        }
        memcpy(novo_paciente, &paciente, sizeof(Registro));
        novo_paciente->entrada = malloc(sizeof(Data));
        if (novo_paciente->entrada == NULL) {
            printf("Erro ao alocar memória para a data de entrada.\n");
            free(novo_paciente);
            fclose(arquivo);
            return 1;
        }
        ELista *novo = inicializar_elista(novo_paciente);
        if (lista->inicio == NULL) {
            lista->inicio = novo;
        } else {
            ELista *atual = lista->inicio;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novo;
        }

        lista->qtde++;
    }

    fclose(arquivo);
    return 0;
}





void sobre() {
    Data *data = inicializar_data();
    printf("Desenvolvedores: \n");
    printf("Nomes: Guilherme Escudeiro e Lucas Cabral\n");
    printf("Ciclo: 4º ciclo\n");
    printf("Curso: Ciencia da Computacao\n");
    printf("Disciplina: Estrutura de Dados\n");
    printf("Data: %d/%d/%d\n", data->dia, data->mes, data->ano);
}

#endif //MISC_H
