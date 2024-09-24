#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvoreBinaria.h"
#include "arvoreBinaria.c"

int main() {
    NoArvore* raiz = NULL;  // Raiz da árvore binária
    ListaDinamica listaDinamica;  // Lista dinâmica para armazenar os dados
    NoLista* listaOrdenada = NULL;  // Lista ligada para manter os registros ordenados por nome
    Dados dados;
    int opcao;
    char cpf[12];

    // Inicializa a lista dinâmica
    inicializarListaDinamica(&listaDinamica);

    while (1) {
        // Exibe o menu de opções
        printf("\nSistema de Gerenciamento\n");
        printf("1. Adicionar\n");
        printf("2. Alterar\n");
        printf("3. Excluir\n");
        printf("4. Procurar\n");
        printf("5. Relatorio\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 6) {
            liberarArvore(raiz);
            liberarLista(listaOrdenada);
            printf("Saindo...\n");
            break;
        }

        switch (opcao) {
            case 1:
                // Adicionar novo registro
                printf("Digite o CPF: ");
                scanf("%s", cpf);
                if (buscarNo(raiz, cpf) != NULL) {
                    printf("CPF ja cadastrado.\n");
                } else {
                    // Solicita os outros dados
                    printf("Digite o Nome: ");
                    scanf("%s", dados.nome);
                    printf("Digite o Endereco: ");
                    scanf("%s", dados.endereco);
                    printf("Digite o Telefone: ");
                    scanf("%s", dados.telefone);
                    printf("Digite o Email: ");
                    scanf("%s", dados.email);
                    strcpy(dados.cpf, cpf);
                    int numeroRegistro = listaDinamica.tamanho;  // Número do registro na lista dinâmica
                    adicionarListaDinamica(&listaDinamica, dados);
                    raiz = adicionarNo(raiz, cpf, numeroRegistro);
                    listaOrdenada = adicionarNoLista(listaOrdenada, dados.nome, numeroRegistro);
                    printf("Registro adicionado com sucesso.\n");
                }
                break;
            case 2:
                // Alterar registro existente
                printf("Digite o CPF: ");
                scanf("%s", cpf);
                NoArvore* no = buscarNo(raiz, cpf);
                if (no == NULL) {
                    printf("CPF nao cadastrado.\n");
                } else {
                    // Solicita os novos dados
                    printf("Digite o novo Nome: ");
                    scanf("%s", dados.nome);
                    printf("Digite o novo Endereco: ");
                    scanf("%s", dados.endereco);
                    printf("Digite o novo Telefone: ");
                    scanf("%s", dados.telefone);
                    printf("Digite o novo Email: ");
                    scanf("%s", dados.email);
                    strcpy(dados.cpf, cpf);
                    alterarListaDinamica(&listaDinamica, no->numeroRegistro, dados, &listaOrdenada);
                    printf("Registro alterado com sucesso.\n");
                }
                break;
            case 3:
                // Excluir registro
                printf("Digite o CPF: ");
                scanf("%s", cpf);
                NoArvore* noExclusao = buscarNo(raiz, cpf);
                if (noExclusao == NULL) {
                    printf("CPF nao cadastrado.\n");
                } else {
                    Dados dadosExclusao = listaDinamica.dados[noExclusao->numeroRegistro];
                    raiz = excluirNo(raiz, cpf);
                    listaOrdenada = excluirNoLista(listaOrdenada, dadosExclusao.nome);
                    printf("Registro excluido com sucesso.\n");
                }
                break;
            case 4:
                // Procurar registro pelo CPF
                printf("Digite o CPF: ");
                scanf("%s", cpf);
                NoArvore* noBusca = buscarNo(raiz, cpf);
                if (noBusca == NULL) {
                    printf("CPF nao cadastrado.\n");
                } else {
                    imprimirListaDinamica(&listaDinamica, noBusca->numeroRegistro);
                }
                break;
            case 5:
                // Imprimir relatório de todos os registros ordenados por nome
                imprimirListaOrdenada(listaOrdenada);
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }

    return 0;
}
