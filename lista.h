#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "registro.h"
#include "abb.h"
#include "types.h"

ELista *inicializar_elista(Registro *registro){
  ELista *elista = malloc(sizeof(ELista));
  elista->proximo = NULL;
  elista->dados = registro;
  return elista;
}

Lista *inicializar_lista(ABB *arvore_ano, ABB *arvore_mes, ABB *arvore_dia, ABB *arvore_idade) {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->arvore_ano = arvore_ano;
    lista->arvore_mes = arvore_mes;
    lista->arvore_dia = arvore_dia;
    lista->arvore_idade = arvore_idade;
    lista->qtde = 0;
    return lista;
}

void cadastrar_paciente(Lista *lista) {
    Registro *registro = inicializar_registro();
    ELista *novo = inicializar_elista(registro);
    if (lista->inicio == NULL){
        lista->inicio = novo;
        lista->qtde++;
    } else{
        novo->proximo = lista->inicio;
        lista->inicio = novo;
        lista->qtde++;
    }
    inserir_ano(lista->arvore_ano, registro);
    inserir_mes(lista->arvore_mes, registro);
    inserir_dia(lista->arvore_dia, registro);
    inserir_idade(lista->arvore_idade, registro);
}

ELista *procura_paciente(Lista *lista, char rg[]){
    ELista *atual = lista->inicio;
    while (atual != NULL && strcmp(atual->dados->rg, rg) != 0){
        atual = atual->proximo;
    }
    if(atual == NULL){
        return NULL;
    }
    return atual;
}

void mostra_paciente(Lista *lista) {
    printf("Digite o RG (sem caracteres especiais): ");
    char rg[9];
    scanf("%s", rg);
    ELista *paciente = procura_paciente(lista, rg);
    if(paciente == NULL){
        printf("Paciente não encontrado\n");
    }else {
        printf("Nome: %s\n", paciente->dados->nome);
        printf("Idade: %i\n", paciente->dados->idade);
        printf("RG: %s\n", paciente->dados->rg);
        printf("Entrada: %i/%i/%i\n", paciente->dados->entrada->dia,paciente->dados->entrada->mes,paciente->dados->entrada->ano);
    }
}

void mostrar_lista(Lista *lista) {
    ELista *atual = lista->inicio;
    printf("Pacientes cadastrados:\n");
    while (atual != NULL){
        printf("Nome: %s\n", atual->dados->nome);
        printf("Idade: %i\n", atual->dados->idade);
        printf("RG: %s\n", atual->dados->rg);
        printf("Entrada: %i/%i/%i\n", atual->dados->entrada->dia,atual->dados->entrada->mes,atual->dados->entrada->ano);
        atual = atual->proximo;
    }
    printf("\n");
}

void remover_paciente(Lista *lista){
    printf("Digite o RG (sem caracteres especiais): ");
    char rg[9];
    scanf("%s", rg);
    ELista *atual = lista->inicio;
    ELista *anterior = NULL;
    while (atual != NULL && strcmp(atual->dados->rg, rg) != 0){
        anterior = atual;
        atual = atual->proximo;
    }
    if(atual == NULL){
        printf("Paciente não encontrado");
    }else{
        if (anterior == NULL && atual->proximo == NULL){
        lista->inicio = NULL;
        lista->qtde--;
        }
        else if (anterior == NULL){
            lista->inicio = atual->proximo;
            lista->qtde--;
        }else{
            anterior->proximo = atual->proximo;
            lista->qtde--;
        }
    }
}

void *atualiza_paciente(Lista *lista) {
    printf("Digite o RG (sem caracteres especiais): ");
    char rg[9];
    scanf("%s", rg);
    ELista *paciente = procura_paciente(lista, rg);
    if(paciente == NULL){
        printf("Paciente nao encontrado\n");
    }else {
        int opcao;
        printf("Escolha qual dado deseja atualizar:\n");
        printf("1 - Nome\n");
        printf("2 - Idade\n");
        printf("3 - RG\n");
        printf("4 - Entrada\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("Digite o novo nome: ");
                scanf("%s", paciente->dados->nome);
                printf("Nome alterado!");
                break;
            case 2:
                printf("Digite a nova idade: ");
                scanf("%d", &paciente->dados->idade);
                printf("Idade alterada!");
                break;
            case 3:
                printf("Digite a RG: ");
                scanf("%s", paciente->dados->rg);
                printf("RG alterado!");
                break;
            case 4:
                int opcaoData;
                printf("Qual deseja alterar: \n");
                printf("1 - Dia\n");
                printf("2 - Mes\n");
                printf("3 - Ano\n");
                scanf("%d", &opcaoData);
                switch (opcaoData) {
                    case 1:
                        printf("Digite o novo dia: ");
                        scanf("%d", &paciente->dados->entrada->dia);
                        printf("Dia alterado!\n");
                        break;
                    case 2:
                        printf("Digite o novo mes: ");
                        scanf("%d", &paciente->dados->entrada->mes);
                        printf("Mes alterado!\n");
                        break;
                    case 3:
                        printf("Digite o novo ano: ");
                        scanf("%d", &paciente->dados->entrada->ano);
                        printf("Ano alterado!\n");
                        break;
                    default:
                        printf("Opcao invalida!\n");
                     break;
                }
                break;
        }
    }
}
#endif