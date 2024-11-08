#include <stdio.h>
#include "lista.h"
#include "abb.h"
#include "pilha.h"
#include "fila.h"
#include "misc.h"
#include "types.h"


int main(void) {

    ABB *arvore_ano = cria_arvore();
    ABB *arvore_mes = cria_arvore();
    ABB *arvore_dia = cria_arvore();
    ABB *arvore_idade = cria_arvore();

    Lista *lista = inicializar_lista(arvore_ano, arvore_mes, arvore_dia, arvore_idade);
    Pilha *pilha = start_stack();
    Fila *fila = cria_fila(pilha, lista);

    int cod;

    cod = carregar(lista, "pacientes.dat");

    if (cod == 1) {
        printf("Arquivo de clientes não encontrado, criando novo arquivo.\n");
    }

    int opcao;
    char rg[9];

    do {

        menuPrincipal();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                menuCadastrar();
                int opcaoCadastro;
                printf("Escolha uma opcao: ");
                scanf("%d", &opcaoCadastro);
                switch (opcaoCadastro) {
                    case 1:
                        cadastrar_paciente(lista);
                        break;
                    case 2:
                        mostra_paciente(lista);
                        break;
                    case 3:
                        mostrar_lista(lista);
                        break;
                    case 4:
                        atualiza_paciente(lista);
                        break;
                    case 5:
                        remover_paciente(lista);
                        break;
                    default:
                        printf("Opcao invalida\n");
                }
                break;

            case 2:
                menuAtendimento();
                int opcaoAtendimento;
                printf("Escolha uma opcao: ");
                scanf("%d", &opcaoAtendimento);
                switch (opcaoAtendimento) {
                    case 1:
                        enqueue(fila);
                        break;
                    case 2:
                        dequeue(fila);
                        break;
                    case 3:
                        show(fila);
                        break;
                    default:
                        printf("Opcao invalida\n");
                }
                break;

            case 3:
                menuPesquisa();
                int opcaoPesquisa;
                printf("Escolha uma opcao: ");
                scanf("%d", &opcaoPesquisa);
                switch (opcaoPesquisa) {
                    case 1:
                        arvore_ano = atualiza_arvore_ano(lista);
                        if(arvore_ano->qtde == 0) {
                            printf("Arvore Vazia\n");
                            break;
                        }
                        in_ordem(arvore_ano->raiz);
                        break;
                    case 2:
                        arvore_mes = atualiza_arvore_mes(lista);
                        if(arvore_mes->qtde == 0) {
                            printf("Arvore Vazia\n");
                            break;
                        }
                        in_ordem(arvore_mes->raiz);
                        break;
                    case 3:
                        arvore_dia = atualiza_arvore_dia(lista);
                        if(arvore_dia->qtde == 0) {
                            printf("Arvore Vazia\n");
                            break;
                        }
                        in_ordem(arvore_dia->raiz);
                        break;
                    case 4:
                        arvore_idade = atualiza_arvore_idade(lista);
                        if(arvore_idade->qtde == 0) {
                            printf("Arvore Vazia\n");
                            break;
                        }
                        in_ordem(arvore_idade->raiz);
                        break;
                    default:
                        printf("Opcao invalida\n");
                }
                break;

            case 4:
                operacao(pilha, fila);
                break;

            case 5: {
                menuArquivo();
                int opcaoArquivo;
                printf("Escolha uma opcao: ");
                scanf("%d", &opcaoArquivo);
                switch (opcaoArquivo) {
                    case 1:
                        if (carregar(lista, "pacientes.dat") == 0) {
                            printf("Pacientes carregados com sucesso!\n");
                        } else {
                            printf("Erro ao carregar os pacientes.\n");
                        }
                        break;
                    case 2:
                        if (salvar(lista, "pacientes.dat") == 0) {
                            printf("Pacientes salvos com sucesso!\n");
                        } else {
                            printf("Erro ao salvar os pacientes.\n");
                        }
                        break;
                    default:
                        printf("Opcao invalida!\n");
                }
                break;
            }

            case 6:
                sobre();
                break;

            case 0:
                printf("Saindo\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
