#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

TabelaHash* criarHash(int tamanho) {
    TabelaHash *hash = malloc(sizeof(TabelaHash));

    if (!hash) {
        printf("Erro ao criar tabela hash.\n");
        return NULL;
    }

    hash->tamanho = tamanho;
    hash->total_colisoes = 0;
    hash->tabela = calloc(tamanho, sizeof(No*));

    if (!hash->tabela) {
        printf("Erro ao alocar tabela hash.\n");
        free(hash);
        return NULL;
    }

    return hash;
}

int funcaoHash(int x, int m) {
    if (x < 0) {
        x = -x;
    }

    return (x * 31) % m;
}

void inserirHash(TabelaHash *hash, Produto produto) {
    int indice = funcaoHash(produto.id, hash->tamanho);

    if (hash->tabela[indice] != NULL) {
        hash->total_colisoes++;
    }

    No *novo = malloc(sizeof(No));

    if (!novo) {
        printf("Erro ao inserir na tabela hash.\n");
        return;
    }

    novo->produto = produto;
    novo->proximo = hash->tabela[indice];
    hash->tabela[indice] = novo;
}

Produto* buscarHash(TabelaHash *hash, int id) {
    int indice = funcaoHash(id, hash->tamanho);

    No *atual = hash->tabela[indice];

    while (atual != NULL) {
        if (atual->produto.id == id) {
            return &atual->produto;
        }

        atual = atual->proximo;
    }

    return NULL;
}

void liberarHash(TabelaHash *hash) {
    if (!hash) {
        return;
    }

    for (int i = 0; i < hash->tamanho; i++) {
        No *atual = hash->tabela[i];

        while (atual != NULL) {
            No *temp = atual;
            atual = atual->proximo;
            free(temp);
        }
    }

    free(hash->tabela);
    free(hash);
}