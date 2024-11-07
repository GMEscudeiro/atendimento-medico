#ifndef REGISTRO_H
#define REGISTRO_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

Data* inicializar_data() {
    Data *data = malloc(sizeof(Data));
    time_t rawtime;
    rawtime = time(NULL);
    struct tm *tm_local = localtime(&rawtime);

    data->dia = tm_local->tm_mday;
    data->mes = tm_local->tm_mon + 1; // Adicionando 1 para corrigir o mês
    data->ano = tm_local->tm_year + 1900; // Adicionando 1900 para corrigir o ano

    return data;
}

Registro *inicializar_registro(){
    Registro *registro = malloc(sizeof(Registro));
    printf("Digite o nome: ");
    scanf("%s", registro->nome);
    printf("Digite a idade: ");
    scanf("%d", &registro->idade);
    printf("Digite o RG (sem caracteres especiais): ");
    scanf("%s", registro->rg);
    registro->entrada = inicializar_data();
    return registro;
}

#endif