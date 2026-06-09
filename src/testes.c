#include <stdio.h>
#include <time.h>
#include "testes.h"

#define TESTES 1000
#define REPETICOES 3

void executarTestesHash(TabelaHash *hash, Produto *produtos, int quantidade) {
    int ids[TESTES];
    double tempoTotalExecucoes = 0.0;

    for (int i = 0; i < 250; i++) {
        ids[i] = produtos[i].id;
    }

    for (int i = 250; i < 500; i++) {
        ids[i] = produtos[(quantidade / 2) + (i - 250)].id;
    }

    for (int i = 500; i < 750; i++) {
        ids[i] = produtos[(quantidade - 250) + (i - 500)].id;
    }

    for (int i = 750; i < 1000; i++) {
        ids[i] = -i;
    }

    for (int r = 0; r < REPETICOES; r++) {
        printf("\n================ EXECUCAO %d de %d ================\n",
               r + 1, REPETICOES);

        clock_t inicio = clock();

        for (int i = 0; i < TESTES; i++) {
            buscarHash(hash, ids[i]);
        }

        clock_t fim = clock();

        double tempoTotal = (double)(fim - inicio) / CLOCKS_PER_SEC;
        double tempoMedio = tempoTotal / TESTES;

        printf("Quantidade de buscas: %d\n", TESTES);
        printf("Tempo total da execucao: %.9f segundos\n", tempoTotal);
        printf("Tempo medio por busca: %.12f segundos\n", tempoMedio);

        tempoTotalExecucoes += tempoTotal;
    }

    double tempoMedioFinal = tempoTotalExecucoes / REPETICOES;
    double tempoMedioPorBuscaFinal = tempoMedioFinal / TESTES;

    printf("\n================ RESULTADOS FINAIS HASH ================\n");
    printf("Tempo medio total: %.9f segundos\n", tempoMedioFinal);
    printf("Tempo medio por busca: %.12e segundos\n", tempoMedioPorBuscaFinal);
}