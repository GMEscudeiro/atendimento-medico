#include <stdio.h>
#include <stdlib.h>
#include <registro.h>
#include <lista.h>
#include <fila.h>
#include <abb.h>
#include <pilha.h>

int main(void) {
    
    Lista *lista = inicializa_lista();
    Fila *fila = inicializaFila();
    int opcao;
    char rg[20];

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserir(lista);
                break;
            case 2:
                printf("Digite o RG do paciente a ser consultado: ");
                scanf(" %19s", rg);
                consultar(lista, rg);
                break;
            case 3:
                listar(lista);
                break;
            case 4:
                printf("Digite o RG do paciente a ser atualizado: ");
                scanf(" %19s", rg);
                atualizar(lista, rg);
                break;
            case 5:
                printf("Digite o RG do paciente a ser removido: ");
                scanf(" %19s", rg);
                remover(lista, rg);
                break;
            case 6:
                enqueue(fila);
                break;
            case 7:
                dequeue(fila);
                break;
            case 8:
                show(fila);
                break;
            case 9:
                printf("Saindo\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 9);
    return 0;
}