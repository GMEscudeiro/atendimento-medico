#include <registro.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef LISTA
#define LISTA

typedef struct Elista{
    Registro* dados;
    struct Elista* proximo;
} ELista;

typedef struct{
    ELista* inicio;
    int qtde;
} Lista;

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
    while (atual != NULL && atual->dados->rg != rg){
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
    }
    printf("\n");
}

void remover_paciente(Lista *lista){
    printf("Digite o RG (sem caracteres especiais): ");
    char rg[9];
    scanf("%s", rg);
    ELista *atual = lista->inicio;
    ELista *anterior = NULL;
    while (atual != NULL && atual->dados->rg != rg){
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
            case 2:
                printf("Digite a nova idade: ");
                scanf("%s", paciente->dados->idade);
            case 3:
                printf("Digite a RG: ");
                scanf("%s", paciente->dados->rg);
            case 4:
                int opcaoData;
                printf("Qual deseja alterar: ");
                printf("1 - Dia\n");
                printf("2 - Mes\n");
                printf("3 - Ano\n");
                scanf("%d", &opcaoData);
                switch (opcaoData) {
                    case 1:
                        printf("Digite o novo dia: ");
                    scanf("%d", paciente->dados->entrada->dia);
                    case 2:
                        printf("Digite o novo mes: ");
                    scanf("%d", paciente->dados->entrada->mes);
                    case 3:
                        printf("Digite o novo ano: ");
                    scanf("%d", paciente->dados->entrada->ano);
                }
        }
    }
}
#endif