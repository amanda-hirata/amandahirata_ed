#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *proximo;
} NoListaLigada;

// Estrutura da fila
typedef struct {
    NoListaLigada *frente;
    NoListaLigada *tras;
} Fila;

// Inicializa a fila
void inicializaFila(Fila *f) {
    f->frente = NULL;
    f->tras = NULL;
}

// Enfileirar (inserir no final)
void enfileirar(Fila *f, int valor) {
    NoListaLigada *novoNo = malloc(sizeof(NoListaLigada));
    if (!novoNo) {
        printf("\nERRO de alocação de memória\n");
        exit(-1);
    }
    novoNo->numero = valor;
    novoNo->proximo = NULL;

    // Se a fila estiver vazia
    if (f->frente == NULL) {
        f->frente = novoNo;
    } else {
        f->tras->proximo = novoNo;
    }
    f->tras = novoNo;
}

// Desinfileirar (remover do início)
int desinfileirar(Fila *f, int *valor) {
    if (f->frente == NULL) {
        return 0; // Fila vazia
    }

    NoListaLigada *temp = f->frente;
    *valor = temp->numero;
    f->frente = temp->proximo;

    // Se a fila ficar vazia após remover
    if (f->frente == NULL) {
        f->tras = NULL;
    }

    free(temp);
    return 1;
}

// Frente (peek) — mostra o primeiro elemento
int frente(Fila *f, int *valor) {
    if (f->frente == NULL)
        return 0; // Fila vazia
    *valor = f->frente->numero;
    return 1;
}

// Verifica se a fila está vazia
int filavazia(Fila *f) {
    return (f->frente == NULL);
}

