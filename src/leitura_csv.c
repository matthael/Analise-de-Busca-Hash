#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura_csv.h"

Produto* carregarCSV(const char* nomeArquivo, int* quantidade) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    int capacidade = 100;
    *quantidade = 0;

    Produto *vetor = malloc(capacidade * sizeof(Produto));

    if (!vetor) {
        printf("Erro de alocacao de memoria.\n");
        fclose(arquivo);
        return NULL;
    }

    char linha[256];

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo)) {
        Produto p;
        char categoria[100];

        if (sscanf(linha, "%d,%50[^,],\"%99[^\"]\",%f",
                   &p.id, p.nome, categoria, &p.valor) == 4) {
            strncpy(p.categoria, categoria, 30);
            p.categoria[30] = '\0';
        }
        else if (sscanf(linha, "%d,%50[^,],%30[^,],%f",
                        &p.id, p.nome, p.categoria, &p.valor) == 4) {
        }
        else {
            continue;
        }

        if (*quantidade >= capacidade) {
            capacidade *= 2;

            Produto *temp = realloc(vetor, capacidade * sizeof(Produto));

            if (!temp) {
                printf("Erro ao realocar memoria.\n");
                free(vetor);
                fclose(arquivo);
                return NULL;
            }

            vetor = temp;
        }

        vetor[*quantidade] = p;
        (*quantidade)++;

        if ((*quantidade % 1000) == 0) {
            printf("\rRegistros carregados: %d", *quantidade);
            fflush(stdout);
        }
    }

    printf("\nLeitura concluida com sucesso!\n");

    fclose(arquivo);
    return vetor;
}