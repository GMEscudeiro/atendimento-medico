#include <stdio.h>
#include <stdlib.h>
#include <registro.h>

typedef struct EABB{
  Registro* dados
  struct EABB* filhoesq;
  struct EABB* filhodir;
} EABB;

typedef struct ABB{
  EABB* raiz;
  int qtde;
} ABB;

void in_ordem(EABB *raiz) {
  if(raiz == NULL){
    return;
  }else{
    in_ordem(raiz->esq);
    printf("%d ", raiz->valor);
    in_ordem(raiz->dir);
  }
}

void pre_ordem(EABB *raiz) {
  if(raiz == NULL){
    return;
  }else{
    printf("%d ", raiz->valor);
    pre_ordem(raiz->esq);
    pre_ordem(raiz->dir);
  }
}

void pos_ordem(EABB *raiz) {
  if(raiz == NULL){
    return;
  }else{
    pos_ordem(raiz->esq);
    pos_ordem(raiz->dir);
    printf("%d ", raiz->valor);
  }
}

EABB *cria_vertice(int valor){
  EABB* novo = malloc(sizeof(EABB));
  novo->dir = NULL;
  novo->esq = NULL;
  novo->pai = NULL;
  novo->valor = valor;

  return novo;
}

ABB *cria_arvore(){
  ABB* arvore = malloc(sizeof(ABB));
  arvore->raiz = NULL;
  arvore->qtde = 0;

  return arvore;
}

void inserir(ABB* arvore, int valor){
  EABB* novo = cria_vertice(valor);
  if(arvore->raiz == NULL){
    arvore->raiz = novo;
  }else{
    EABB* atual = arvore->raiz;
    EABB* anterior = NULL;
    while(atual != NULL){
      anterior = atual;
      if(valor <= atual->valor){
        atual = atual->esq;
      }else{
        atual = atual->dir;
      }
    }
    if(valor <= anterior->valor){
      anterior->esq = novo;
    }else{
      anterior->dir = novo;
    }
    novo->pai = anterior;
  }
  arvore->qtde++;
}

int remover_vertice(ABB* arvore, EABB* vertice) {
  if(vertice == NULL){
    return -1;
  }
  int tempvalor = vertice->valor;
  if(vertice->esq == NULL && vertice->dir == NULL){
    if(arvore->raiz == vertice){
      arvore->raiz = NULL;
    }else if(vertice->pai->esq == vertice){
      vertice->pai->esq = NULL;
    }else{
      vertice->pai->dir = NULL;
    }
    free(vertice);
  }else{
    if(vertice->esq == NULL || vertice->dir == NULL){
      if(vertice->esq != NULL){
        if(arvore->raiz == vertice){
          arvore->raiz = vertice->esq;
          vertice->esq->pai = NULL;
        }else{
          vertice->esq->pai = vertice->pai;
          if(vertice->pai->esq == vertice){
            vertice->pai->esq = vertice->esq;
          }else{
            vertice->pai->dir = vertice->esq;
          }
        }
      }else{
        if(arvore->raiz == vertice){
          arvore->raiz = vertice->dir;
          vertice->dir->pai = NULL;
        }else{
          vertice->dir->pai = vertice->pai;
          if(vertice->pai->esq == vertice){
            vertice->pai->esq = vertice->dir;
          }else{
            vertice->pai->dir = vertice->dir;
          }
        }
      }
      free(vertice);
    }else{
      EABB* proximo = vertice->esq;
      while(proximo->dir != NULL){
        proximo = proximo->dir;
      }
      vertice->valor = proximo->valor;
      remover_vertice(arvore, proximo);
    }
  }
  arvore->qtde--;
  return tempvalor;
}

EABB *buscar_valor(ABB* arvore, int valor){
  EABB* atual = arvore->raiz;
  while(atual != NULL){
    if(valor < atual->valor){
      atual = atual->esq;
    }else if(valor > atual->valor){
      atual = atual->dir;
    }else{
      return atual;
    }
  }
  return NULL;
}

void liberar_arvore(EABB* vertice) {
    if (vertice != NULL) {
        liberar_arvore(vertice->esq);
        liberar_arvore(vertice->dir);
        free(vertice);
    }
}