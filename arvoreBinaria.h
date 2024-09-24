#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

// Definição da estrutura de dados para armazenar informações do usuário
typedef struct {
    char cpf[12];
    char nome[50];
    char endereco[100];
    char telefone[15];
    char email[50];
} Dados;

// Definição da estrutura de nó da árvore binária
typedef struct NoArvore {
    char cpf[12];
    int numeroRegistro;
    struct NoArvore* esquerda;
    struct NoArvore* direita;
} NoArvore;

// Definição da estrutura de nó da lista duplamente ligada
typedef struct NoLista {
    char nome[50];
    int numeroRegistro;
    struct NoLista* anterior;
    struct NoLista* proximo;
} NoLista;

// Definição da estrutura da lista dinâmica
typedef struct {
    Dados dados[100];
    int tamanho;
} ListaDinamica;

// Declarações das funções de manipulação da lista dinâmica
void inicializarListaDinamica(ListaDinamica* lista);
void adicionarListaDinamica(ListaDinamica* lista, Dados dados);
void alterarListaDinamica(ListaDinamica* lista, int numeroRegistro, Dados novosDados, NoLista** listaOrdenada);
void imprimirListaDinamica(ListaDinamica* lista, int numeroRegistro);

// Declarações das funções de manipulação da árvore binária
NoArvore* adicionarNo(NoArvore* raiz, char* cpf, int numeroRegistro);
NoArvore* buscarNo(NoArvore* raiz, char* cpf);
NoArvore* excluirNo(NoArvore* raiz, char* cpf);
void liberarArvore(NoArvore* raiz);

// Declarações das funções de manipulação da lista duplamente ligada
NoLista* criarNoLista(char* nome, int numeroRegistro);
NoLista* adicionarNoLista(NoLista* cabeca, char* nome, int numeroRegistro);
NoLista* excluirNoLista(NoLista* cabeca, char* nome);
void imprimirListaOrdenada(NoLista* cabeca);
void liberarLista(NoLista* cabeca);

#endif // ARVOREBINARIA_H
