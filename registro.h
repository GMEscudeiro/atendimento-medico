#ifndef REGISTRO_H
#define REGISTRO_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "types.h"

Data *inicializar_data(){
    Data *data = malloc(sizeof(Data));
    time_t rawtime;
    rawtime = time(NULL);
    struct tm *tm_local = localtime(&rawtime);

    data->dia = tm_local->tm_mday;
    data->mes = tm_local->tm_mon;
    data->ano = tm_local->tm_year;
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