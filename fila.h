#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
#include "types.h"

EFila *cria_efila(Registro *registro){
  EFila *efila = malloc(sizeof(EFila));
  efila->proximo = NULL;
  efila->anterior = NULL;
  efila->dados = registro;
  return efila;
}

Fila *cria_fila(Pilha *pilha, Lista *lista){
  Fila *fila = malloc(sizeof(Fila));
  fila->head = NULL;
  fila->tail = NULL;
  fila->pilha = pilha;
  fila->lista = lista;
  fila->qtde = 0;
  return fila;
}

void enqueue(Fila *fila){
    printf("Digite o RG do paciente: ");
    char rg[9];
    scanf("%s", rg);
    ELista *paciente = procura_paciente(fila->lista, rg);
    if(paciente != NULL) {
        Registro *dados = paciente->dados;
        EFila *efilaNova = cria_efila(dados);
        if(fila->head == NULL){
            fila->head = efilaNova;
        }else{
            fila->tail->proximo = efilaNova;
            efilaNova->anterior = fila->tail;
        }
        fila->tail = efilaNova;
        fila->qtde++;
        push(fila->pilha, dados, 0);
        printf("Paciente %s adicionado a fila\n", paciente->dados->nome);
    }else {
        printf("Paciente nao encontrado\n");
    }

}

void desfaz_enqueue(Fila *fila) {
    EFila *temp = fila->tail;
    fila->tail->anterior->proximo = NULL;
    fila->tail = fila->tail->anterior;
    free(temp);
}

Registro* dequeue(Fila *fila){
    if(fila->head == NULL){
        printf("Fila vazia\n");
        return NULL;
    }
    Registro* valor = fila->head->dados; // variavel que ira ser retornada
    EFila *temp = fila->head; // efila que sera removida
    push(fila->pilha, valor, 1);
    if(fila->head->proximo == NULL){
        fila->tail = NULL;
    }else{
        fila->head = fila->head->proximo;
    }
    free(temp);
    fila->qtde--;
    return valor;
}

void desfaz_dequeue(Fila *fila, Registro *dados) {
    EFila *novo = cria_efila(dados);
    fila->head->anterior = novo;
    novo->proximo = fila->head;
    fila->head = novo;
}

void show(Fila *fila){
    EFila *atual = fila->head;
    printf("Fila de atendimento: ");
    while(atual != NULL){
        printf("%s", atual->dados->nome);
        atual = atual->proximo;
    }
    printf("\n");
}

void operacao(Pilha *stack, Fila *fila) {
    Celula *ultima = stack->topo;
    if(ultima != NULL) {
        char opcao;
        printf("Ultima operacao realizada:\n");
        if(ultima->op == 0) {
            printf("Adicionou o paciente: %s\n", ultima->dados->nome);
            printf("Deseja desfaze-la? (s/n): ");
            scanf(" %c", &opcao);
            if(opcao == 's') {
                pop(stack);
                desfaz_enqueue(fila);
            }
        }else {
            printf("Removeu o paciente: %s\n", ultima->dados->nome);
            printf("Deseja desfaze-la? (s/n): ");
            scanf(" %c", &opcao);
            if(opcao == 's') {
                Celula *valor = pop(stack);
                desfaz_dequeue(fila, valor->dados);
            }
        }
    }
    else {
        printf("Nenhuma operacao.\n");
    }
}
#endif