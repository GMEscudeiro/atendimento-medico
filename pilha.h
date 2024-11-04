#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
  struct Celula *anterior;
  char valor;
} Celula;

typedef struct{
  Celula *topo;
  int qtde;
} Stack;

Stack *start_stack(){
  Stack *stack = malloc(sizeof(Stack));
  stack->topo = NULL;
  stack->qtde = 0;
  return stack;
}

Celula *inicializarCelula(char valor){
  Celula *celula = malloc(sizeof(Celula));
  celula->valor = valor;
  celula->anterior = NULL;
  return celula;
}

void push(Stack *stack, char valor){
  Celula *novo = inicializarCelula(valor);
  if(stack->qtde != 0){
    novo->anterior = stack->topo;
  }
  stack->topo = novo;
  stack->qtde++;
}

char pop(Stack *stack){
  if(stack->qtde == 0){
    return -1;
  }
  Celula *temp = stack->topo;
  char valor = temp->valor;
  stack->topo = temp->anterior;
  free(temp);
  stack->qtde--;
  return valor;
}

void mostrarStack(Stack *stack){
  Celula *atual = stack->topo;
  while(atual != NULL){
    printf("%c", atual->valor);
    atual = atual->anterior;
  }
  printf("\n");
}

int verifica(Stack *stack){
  Stack *abertos = start_stack();
  int chaves = 0;
  int colchetes = 0;
  int parenteses = 0;
  do{
    char valor = pop(stack);
    if(valor == '}'){
      push(abertos, valor);
      if(abertos->topo->anterior != NULL && abertos->topo->anterior->valor == ']'){
        return 0;
      }
      chaves++;
    }else if(valor == ']'){
      push(abertos, valor);
      if(abertos->topo->anterior != NULL && abertos->topo->anterior->valor == ')'){
        return 0;
      }
      colchetes++;
    }else if(valor == ')'){
      push(abertos, valor);
      parenteses++;
    }
    if(valor == '('){
      char ultimo = pop(abertos);

      if(ultimo != ')'){
        return 0;
      }
      parenteses--;
    }
    if(valor == '['){
      char ultimo = pop(abertos);
      if(ultimo != ']'){
        return 0;
      }
      colchetes--;
    }
    if(valor == '{'){
      char ultimo = pop(abertos);
      if(ultimo != '}'){
        return 0;
      }
      chaves--;
    }
  }while(stack->qtde != 0);
  if(colchetes > 0 || parenteses > 0 || chaves > 0){
      return 0;
    }
  return 1;
}

int main(void) {
    Stack *stack = start_stack();
    char expr[100];
    fgets(expr, sizeof(expr), stdin);
    
    for(int i=0; i<100; i++){
        if(expr[i] == '\0'){
            break;
        }
        push(stack, expr[i]);
    }
    

    int verificador = verifica(stack);
    if(verificador){
      printf("correto");
    }else{
      printf("incorreto");
    }
    
    return 0;
}
