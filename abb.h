#include <stdio.h>
#include <stdlib.h>
#include <registro.h>

typedef struct EABB{
  Registro* dados;
  struct EABB* filhoesq;
  struct EABB* filhodir;
  struct EABB* pai;
} EABB;

typedef struct ABB{
  EABB* raiz;
  int qtde;
} ABB;

void in_ordem(EABB *raiz) {
  if(raiz == NULL){
    return;
  }else{
    in_ordem_ano(raiz->filhoesq);
    printf("%d ", raiz->valor);
    in_ordem_ano(raiz->filhodir);
  }
}


EABB *cria_vertice(Registro* dados){
  EABB* novo = malloc(sizeof(EABB));
  novo->filhodir = NULL;
  novo->filhoesq = NULL;
  novo->pai = NULL;
  novo->dados = dados;

  return novo;
}

ABB *cria_arvore(){
  ABB* arvore = malloc(sizeof(ABB));
  arvore->raiz = NULL;
  arvore->qtde = 0;

  return arvore;
}

void inserir_ano(ABB* arvore, Registro* dados){
  EABB* novo = cria_vertice(dados);
  if(arvore->raiz == NULL){
    arvore->raiz = novo;
  }else{
    EABB* atual = arvore->raiz;
    EABB* anterior = NULL;
    while(atual != NULL){
      anterior = atual;
      if(dados->entrada->ano <= atual->dados->entrada->ano){
        atual = atual->filhoesq;
      }else{
        atual = atual->filhodir;
      }
    }
    if(dados->entrada->ano <= anterior->dados->entrada->ano){
      anterior->filhoesq = novo;
    }else{
      anterior->filhodir = novo;
    }
    novo->pai = anterior;
  }
  arvore->qtde++;
}

Registro* remover_vertice(ABB* arvore, EABB* vertice) {
  if(vertice == NULL){
    return -1;
  }
  Registro *tempvalor = vertice->dados;
  if(vertice->filhoesq == NULL && vertice->filhodir == NULL){
    if(arvore->raiz == vertice){
      arvore->raiz = NULL;
    }else if(vertice->pai->filhoesq == vertice){
      vertice->pai->filhoesq = NULL;
    }else{
      vertice->pai->filhodir = NULL;
    }
    free(vertice);
  }else{
    if(vertice->filhoesq == NULL || vertice->filhodir == NULL){
      if(vertice->filhoesq != NULL){
        if(arvore->raiz == vertice){
          arvore->raiz = vertice->filhoesq;
          vertice->filhoesq->pai = NULL;
        }else{
          vertice->filhoesq->pai = vertice->pai;
          if(vertice->pai->filhoesq == vertice){
            vertice->pai->filhoesq = vertice->filhoesq;
          }else{
            vertice->pai->filhodir = vertice->filhoesq;
          }
        }
      }else{
        if(arvore->raiz == vertice){
          arvore->raiz = vertice->filhodir;
          vertice->filhodir->pai = NULL;
        }else{
          vertice->filhodir->pai = vertice->pai;
          if(vertice->pai->filhoesq == vertice){
            vertice->pai->filhoesq = vertice->filhodir;
          }else{
            vertice->pai->filhodir = vertice->filhodir;
          }
        }
      }
      free(vertice);
    }else{
      EABB* proximo = vertice->filhoesq;
      while(proximo->filhodir != NULL){
        proximo = proximo->filhodir;
      }
      vertice->dados = proximo->dados;
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
      atual = atual->filhoesq;
    }else if(valor > atual->valor){
      atual = atual->filhodir;
    }else{
      return atual;
    }
  }
  return NULL;
}

void liberar_arvore(EABB* vertice) {
    if (vertice != NULL) {
        liberar_arvore(vertice->filhoesq);
        liberar_arvore(vertice->filhodir);
        free(vertice);
    }
}