#ifndef TYPES_H
#define TYPES_H

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct{
    char nome[50];
    int idade;
    char rg[9];
    Data* entrada;
} Registro;

typedef struct Celula{
    struct Celula *anterior;
    Registro *dados;
    int op;
} Celula;

typedef struct{
    Celula *topo;
    int qtde;
} Pilha;

typedef struct Elista{
    Registro* dados;
    struct Elista* proximo;
} ELista;

typedef struct EABB{
    Registro* dados;
    struct EABB *filhoesq;
    struct EABB *filhodir;
    struct EABB *pai;
} EABB;

typedef struct ABB{
    EABB* raiz;
    int qtde;
} ABB;

typedef struct{
    ELista* inicio;
    ABB *arvore_ano;
    ABB *arvore_mes;
    ABB *arvore_dia;
    ABB *arvore_idade;
    int qtde;
} Lista;

typedef struct EFila{
    Registro* dados;
    struct EFila* proximo;
    struct EFila* anterior;
} EFila;

typedef struct{
    EFila* head;
    EFila* tail;
    Pilha* pilha;
    Lista* lista;
    int qtde;
} Fila;

#endif //TYPES_H
