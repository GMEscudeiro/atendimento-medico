#include <registro.h>

#ifndef FILA
#define FILA

typedef struct EFila{
    Registro* dados;
    struct EFila* proximo;
} EFila;

typedef struct{
    EFila* head;
    EFila* tail;
    int qtde;
} Fila;

EFila *cria_efila(Registro *registro){
  EFila *efila = malloc(sizeof(EFila));
  efila->proximo = NULL;
  efila->dados = registro;
  return efila;
}

Fila *cria_fila(){
  Fila *fila = malloc(sizeof(Fila));
  fila->head = NULL;
  fila->tail = NULL;
  fila->qtde = 0;
  return fila;
}

void enqueue(Lista *lista, Fila *fila, int valor){
    printf("Digite o RG do paciente: ");
    char rg[9];
    scanf("%s", rg);
    ELista *paciente = procura_paciente(lista, rg);
    Registro *dados = paciente->dados;
    EFila *efilaNova = cria_efila(dados);
    if(fila->head == NULL){
        fila->head = efilaNova;
    }else{
        fila->tail->proximo = efilaNova;
    }
    fila->tail = efilaNova;
    fila->qtde++;
}

Registro* dequeue(Fila *fila){
    if(fila->head == NULL){
        return -1;
    }
    Registro* valor = fila->head->dados; // variavel que ira ser retornada
    EFila *temp = fila->head; // efila que sera removida
    fila->head = fila->head->proximo;
    if(fila->head->proximo == NULL){
        fila->tail = NULL;
    }
    free(temp);
    fila->qtde--;
    return valor;
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
#endif