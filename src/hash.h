#ifndef HASH_H
#define HASH_H

#include "produto.h"

typedef struct No {
    Produto produto;
    struct No *proximo;
} No;

typedef struct {
    No **tabela;
    int tamanho;
    long total_colisoes;
} TabelaHash;

TabelaHash* criarHash(int tamanho);
int funcaoHash(int x, int m);
void inserirHash(TabelaHash *hash, Produto produto);
Produto* buscarHash(TabelaHash *hash, int id);
void liberarHash(TabelaHash *hash);

#endif