#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

Pilha *start_stack(){
  Pilha *stack = malloc(sizeof(Pilha));
  stack->topo = NULL;
  stack->qtde = 0;
  return stack;
}

Celula *inicializarCelula(Registro *dados, int op){
  Celula *celula = malloc(sizeof(Celula));
  celula->dados = dados;
  celula->op = op;
  celula->anterior = NULL;
  return celula;
}

void push(Pilha *stack, Registro* dados, int op){
  Celula *novo = inicializarCelula(dados, op);
  if(stack->qtde != 0){
    novo->anterior = stack->topo;
  }
  stack->topo = novo;
  stack->qtde++;
}

Celula *pop(Pilha *stack){
  if(stack->qtde == 0){
    return NULL;
  }
  Celula *temp = stack->topo;
  stack->topo = temp->anterior;
  free(temp);
  stack->qtde--;
  return temp;
}

#endif