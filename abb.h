#ifndef ABB_H
#define ABB_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void in_ordem(EABB *raiz) {
  if(raiz == NULL){
    return;
  }else{
    in_ordem(raiz->filhoesq);
    printf("Nome: %s RG: %s Idade: %d Entrada: %d/%d/%d\n", raiz->dados->nome, raiz->dados->rg, raiz->dados->idade, raiz->dados->entrada->dia,
      raiz->dados->entrada->mes, raiz->dados->entrada->ano);
    in_ordem(raiz->filhodir);
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

void inserir_mes(ABB* arvore, Registro* dados){
  EABB* novo = cria_vertice(dados);
  if(arvore->raiz == NULL){
    arvore->raiz = novo;
  }else{
    EABB* atual = arvore->raiz;
    EABB* anterior = NULL;
    while(atual != NULL){
      anterior = atual;
      if(dados->entrada->mes <= atual->dados->entrada->mes){
        atual = atual->filhoesq;
      }else{
        atual = atual->filhodir;
      }
    }
    if(dados->entrada->mes <= anterior->dados->entrada->mes){
      anterior->filhoesq = novo;
    }else{
      anterior->filhodir = novo;
    }
    novo->pai = anterior;
  }
  arvore->qtde++;
}

void inserir_dia(ABB* arvore, Registro* dados){
  EABB* novo = cria_vertice(dados);
  if(arvore->raiz == NULL){
    arvore->raiz = novo;
  }else{
    EABB* atual = arvore->raiz;
    EABB* anterior = NULL;
    while(atual != NULL){
      anterior = atual;
      if(dados->entrada->dia <= atual->dados->entrada->dia){
        atual = atual->filhoesq;
      }else{
        atual = atual->filhodir;
      }
    }
    if(dados->entrada->dia <= anterior->dados->entrada->dia){
      anterior->filhoesq = novo;
    }else{
      anterior->filhodir = novo;
    }
    novo->pai = anterior;
  }
  arvore->qtde++;
}

void inserir_idade(ABB* arvore, Registro* dados){
  EABB* novo = cria_vertice(dados);
  if(arvore->raiz == NULL){
    arvore->raiz = novo;
  }else{
    EABB* atual = arvore->raiz;
    EABB* anterior = NULL;
    while(atual != NULL){
      anterior = atual;
      if(dados->idade <= atual->dados->idade){
        atual = atual->filhoesq;
      }else{
        atual = atual->filhodir;
      }
    }
    if(dados->idade <= anterior->dados->idade){
      anterior->filhoesq = novo;
    }else{
      anterior->filhodir = novo;
    }
    novo->pai = anterior;
  }
  arvore->qtde++;
}

ABB *atualiza_arvore_ano(Lista *lista) {
  ABB* novo = cria_arvore();
  ELista *atual = lista->inicio;
  while (atual != NULL){
    inserir_ano(novo, atual->dados);
    atual = atual->proximo;
  }
  return novo;
}

ABB *atualiza_arvore_mes(Lista *lista) {
  ABB* novo = cria_arvore();
  ELista *atual = lista->inicio;
  while (atual != NULL){
    inserir_mes(novo, atual->dados);
    atual = atual->proximo;
  }
  return novo;
}

ABB *atualiza_arvore_dia(Lista *lista) {
  ABB* novo = cria_arvore();
  ELista *atual = lista->inicio;
  while (atual != NULL){
    inserir_dia(novo, atual->dados);
    atual = atual->proximo;
  }
  return novo;
}

ABB *atualiza_arvore_idade(Lista *lista) {
  ABB* novo = cria_arvore();
  ELista *atual = lista->inicio;
  while (atual != NULL){
    inserir_idade(novo, atual->dados);
    atual = atual->proximo;
  }
  return novo;
}

Registro* remover_vertice(ABB* arvore, EABB* vertice) {
  if(vertice == NULL){
    return NULL;
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

void liberar_arvore(EABB* vertice) {
    if (vertice != NULL) {
        liberar_arvore(vertice->filhoesq);
        liberar_arvore(vertice->filhodir);
        free(vertice);
    }
}

#endif