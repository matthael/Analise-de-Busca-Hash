#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "leitura_csv.h"
#include "hash.h"
#include "testes.h"

int main() {
    int quantidade = 0;

    Produto *produtos = carregarCSV("data/dataset2.csv", &quantidade);

    if (produtos == NULL) {
        return 1;
    }

    printf("Arquivo encontrado!\n");
    printf("Total de registros carregados: %d\n", quantidade);

    TabelaHash *hash = criarHash(quantidade);

    if (hash == NULL) {
        free(produtos);
        return 1;
    }

    printf("\nCarregando tabela hash...\n");

    for (int i = 0; i < quantidade; i++) {
        inserirHash(hash, produtos[i]);
    }

    printf("Tabela hash carregada com sucesso!\n");
    printf("Tamanho da tabela hash: %d\n", hash->tamanho);
    printf("Total de colisoes: %ld\n", hash->total_colisoes);

    executarTestesHash(hash, produtos, quantidade);

    liberarHash(hash);
    free(produtos);

    return 0;
}