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

Lista *inicializar_lista() {
    Lista *lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
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
        printf("Idade: %d\n", paciente->dados->idade);
        printf("RG: %s\n", paciente->dados->rg);
        printf("Entrada: %02d/%02d/%04d\n", paciente->dados->entrada->dia,paciente->dados->entrada->mes,paciente->dados->entrada->ano);
    }
}

void mostrar_lista(Lista *lista) {
    ELista *atual = lista->inicio;
    printf("Pacientes cadastrados:\n");
    while (atual != NULL){
        printf("Nome: %s\n", atual->dados->nome);
        printf("Idade: %d\n", atual->dados->idade);
        printf("RG: %s\n", atual->dados->rg);
        printf("Entrada: %02d/%02d/%04d\n", atual->dados->entrada->dia,atual->dados->entrada->mes,atual->dados->entrada->ano);
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
        printf("Paciente não encontrado\n");
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

void atualiza_paciente(Lista *lista) {
    printf("Digite o RG (sem caracteres especiais): ");
    char rg[9];
    scanf("%s", rg);
    ELista *paciente = procura_paciente(lista, rg);
    if (paciente == NULL) {
        printf("Paciente nao encontrado\n");
    } else {
        int opcao;
        printf("Escolha qual dado deseja atualizar:\n");
        printf("1 - Nome\n");
        printf("2 - Idade\n");
        printf("3 - RG\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o novo nome: ");
                scanf("%s", paciente->dados->nome);
                printf("Nome alterado!\n");
                break;
            case 2:
                printf("Digite a nova idade: ");
                scanf("%d", &paciente->dados->idade);
                printf("Idade alterada!\n");
                break;
            case 3:
                printf("Digite o novo RG: ");
                scanf("%s", paciente->dados->rg);
                printf("RG alterado!\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    }
}


#endif