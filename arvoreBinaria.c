#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvoreBinaria.h"

// Inicializa a lista dinâmica
void inicializarListaDinamica(ListaDinamica* lista) {
    lista->tamanho = 0;
}

// Adiciona um novo registro na lista dinâmica
void adicionarListaDinamica(ListaDinamica* lista, Dados dados) {
    if (lista->tamanho < 100) {
        lista->dados[lista->tamanho] = dados;
        lista->tamanho++;
    } else {
        printf("Lista cheia.\n");
    }
}

// Altera um registro existente na lista dinâmica
void alterarListaDinamica(ListaDinamica* lista, int numeroRegistro, Dados novosDados, NoLista** listaOrdenada) {
    if (numeroRegistro >= 0 && numeroRegistro < lista->tamanho) {
        Dados dadosAntigos = lista->dados[numeroRegistro];
        lista->dados[numeroRegistro] = novosDados;
        
        // Atualiza a lista ordenada
        *listaOrdenada = excluirNoLista(*listaOrdenada, dadosAntigos.nome);
        *listaOrdenada = adicionarNoLista(*listaOrdenada, novosDados.nome, numeroRegistro);
    } else {
        printf("Numero de registro invalido.\n");
    }
}

// Imprime os dados de um registro específico da lista dinâmica
void imprimirListaDinamica(ListaDinamica* lista, int numeroRegistro) {
    if (numeroRegistro >= 0 && numeroRegistro < lista->tamanho) {
        Dados dados = lista->dados[numeroRegistro];
        printf("CPF: %s\n", dados.cpf);
        printf("Nome: %s\n", dados.nome);
        printf("Endereco: %s\n", dados.endereco);
        printf("Telefone: %s\n", dados.telefone);
        printf("Email: %s\n", dados.email);
    } else {
        printf("Numero de registro invalido.\n");
    }
}

// Cria um novo nó na árvore binária
NoArvore* criarNoArvore(char* cpf, int numeroRegistro) {
    NoArvore* novoNo = (NoArvore*)malloc(sizeof(NoArvore));
    strcpy(novoNo->cpf, cpf);
    novoNo->numeroRegistro = numeroRegistro;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Adiciona um novo nó na árvore binária
NoArvore* adicionarNo(NoArvore* raiz, char* cpf, int numeroRegistro) {
    if (raiz == NULL) {
        return criarNoArvore(cpf, numeroRegistro);
    }
    if (strcmp(cpf, raiz->cpf) < 0) {
        raiz->esquerda = adicionarNo(raiz->esquerda, cpf, numeroRegistro);
    } else if (strcmp(cpf, raiz->cpf) > 0) {
        raiz->direita = adicionarNo(raiz->direita, cpf, numeroRegistro);
    }
    return raiz;
}

// Busca um nó na árvore binária pelo CPF
NoArvore* buscarNo(NoArvore* raiz, char* cpf) {
    if (raiz == NULL || strcmp(raiz->cpf, cpf) == 0) {
        return raiz;
    }
    if (strcmp(cpf, raiz->cpf) < 0) {
        return buscarNo(raiz->esquerda, cpf);
    } else {
        return buscarNo(raiz->direita, cpf);
    }
}

// Encontra o menor nó da árvore binária
NoArvore* encontrarMenorNo(NoArvore* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

// Exclui um nó da árvore binária pelo CPF
NoArvore* excluirNo(NoArvore* raiz, char* cpf) {
    if (raiz == NULL) {
        return NULL;
    }
    if (strcmp(cpf, raiz->cpf) < 0) {
        raiz->esquerda = excluirNo(raiz->esquerda, cpf);
    } else if (strcmp(cpf, raiz->cpf) > 0) {
        raiz->direita = excluirNo(raiz->direita, cpf);
    } else {
        if (raiz->esquerda == NULL) {
            NoArvore* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            NoArvore* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        NoArvore* temp = encontrarMenorNo(raiz->direita);
        strcpy(raiz->cpf, temp->cpf);
        raiz->numeroRegistro = temp->numeroRegistro;
        raiz->direita = excluirNo(raiz->direita, temp->cpf);
    }
    return raiz;
}

// Libera a memória alocada para a árvore binária
void liberarArvore(NoArvore* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

// Cria um novo nó na lista duplamente ligada
NoLista* criarNoLista(char* nome, int numeroRegistro) {
    NoLista* novoNo = (NoLista*)malloc(sizeof(NoLista));
    strcpy(novoNo->nome, nome);
    novoNo->numeroRegistro = numeroRegistro;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}

// Adiciona um novo nó na lista duplamente ligada em ordem alfabética
NoLista* adicionarNoLista(NoLista* cabeca, char* nome, int numeroRegistro) {
    NoLista* novoNo = criarNoLista(nome, numeroRegistro);
    if (cabeca == NULL) {
        return novoNo;
    }
    NoLista* atual = cabeca;
    NoLista* anterior = NULL;
    // Encontra a posição correta para inserir o novo nó
    while (atual != NULL && strcmp(atual->nome, nome) < 0) {
        anterior = atual;
        atual = atual->proximo;
    }
    // Insere no início da lista
    if (anterior == NULL) {
        novoNo->proximo = cabeca;
        cabeca->anterior = novoNo;
        return novoNo;
    }
    // Insere no meio ou no final da lista
    anterior->proximo = novoNo;
    novoNo->anterior = anterior;
    if (atual != NULL) {
        novoNo->proximo = atual;
        atual->anterior = novoNo;
    }
    return cabeca;
}

// Exclui um nó da lista duplamente ligada pelo nome
NoLista* excluirNoLista(NoLista* cabeca, char* nome) {
    NoLista* atual = cabeca;
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        atual = atual->proximo;
    }
    if (atual == NULL) {
        return cabeca;
    }
    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        cabeca = atual->proximo;
    }
    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    }
    free(atual);
    return cabeca;
}

// Imprime a lista ordenada
void imprimirListaOrdenada(NoLista* cabeca) {
    NoLista* atual = cabeca;
    while (atual != NULL) {
        printf("Nome: %s, Numero de Registro: %d\n", atual->nome, atual->numeroRegistro);
        atual = atual->proximo;
    }
}

// Libera a memória alocada para a lista duplamente ligada
void liberarLista(NoLista* cabeca) {
    NoLista* atual = cabeca;
    while (atual != NULL) {
        NoLista* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}
