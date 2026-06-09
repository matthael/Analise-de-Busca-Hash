#include <stdio.h>
#include <time.h>
#include "testes.h"

#define REPETICOES 3
#define TAMANHO_INTERVALO 1000

double testarIntervaloHash(TabelaHash *hash, Produto *produtos, int inicio, int fim) {
    clock_t tempo_inicio = clock();

    for (int i = inicio; i <= fim; i++) {
        buscarHash(hash, produtos[i].id);
    }

    clock_t tempo_fim = clock();

    return (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
}

double testarInexistentesHash(TabelaHash *hash) {
    clock_t tempo_inicio = clock();

    for (int i = 0; i < TAMANHO_INTERVALO; i++) {
        buscarHash(hash, -i - 1);
    }

    clock_t tempo_fim = clock();

    return (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;
}

void executarTestesHash(TabelaHash *hash, Produto *produtos, int quantidade) {
    double somaTempoTotal = 0.0;

    int inicio1 = 0;
    int inicio2 = 2000;
    int inicio3 = 4000;

    int meioBase = quantidade / 2;
    int meio1 = meioBase;
    int meio2 = meioBase + 2000;
    int meio3 = meioBase + 4000;

    int final1 = quantidade - 10000;
    int final2 = quantidade - 8000;
    int final3 = quantidade - 6000;

    int totalBuscasPorExecucao = 10000;

    for (int execucao = 1; execucao <= REPETICOES; execucao++) {
        printf("\n================ EXECUCAO %d de %d ================\n", execucao, REPETICOES);

        double tempoTotalExecucao = 0.0;

        printf("\n[INICIO]\n");

        printf("Intervalo 1: posicoes %d a %d | IDs %d a %d\n",
               inicio1, inicio1 + 999, produtos[inicio1].id, produtos[inicio1 + 999].id);
        double tempoInicio = testarIntervaloHash(hash, produtos, inicio1, inicio1 + 999);

        printf("Intervalo 2: posicoes %d a %d | IDs %d a %d\n",
               inicio2, inicio2 + 999, produtos[inicio2].id, produtos[inicio2 + 999].id);
        tempoInicio += testarIntervaloHash(hash, produtos, inicio2, inicio2 + 999);

        printf("Intervalo 3: posicoes %d a %d | IDs %d a %d\n",
               inicio3, inicio3 + 999, produtos[inicio3].id, produtos[inicio3 + 999].id);
        tempoInicio += testarIntervaloHash(hash, produtos, inicio3, inicio3 + 999);

        printf("Tempo do bloco [INICIO]: %.6f segundos\n", tempoInicio);
        tempoTotalExecucao += tempoInicio;

        printf("\n[MEIO]\n");

        printf("Intervalo 1: posicoes %d a %d | IDs %d a %d\n",
               meio1, meio1 + 999, produtos[meio1].id, produtos[meio1 + 999].id);
        double tempoMeio = testarIntervaloHash(hash, produtos, meio1, meio1 + 999);

        printf("Intervalo 2: posicoes %d a %d | IDs %d a %d\n",
               meio2, meio2 + 999, produtos[meio2].id, produtos[meio2 + 999].id);
        tempoMeio += testarIntervaloHash(hash, produtos, meio2, meio2 + 999);

        printf("Intervalo 3: posicoes %d a %d | IDs %d a %d\n",
               meio3, meio3 + 999, produtos[meio3].id, produtos[meio3 + 999].id);
        tempoMeio += testarIntervaloHash(hash, produtos, meio3, meio3 + 999);

        printf("Tempo do bloco [MEIO]: %.6f segundos\n", tempoMeio);
        tempoTotalExecucao += tempoMeio;

        printf("\n[FINAL]\n");

        printf("Intervalo 1: posicoes %d a %d | IDs %d a %d\n",
               final1, final1 + 999, produtos[final1].id, produtos[final1 + 999].id);
        double tempoFinal = testarIntervaloHash(hash, produtos, final1, final1 + 999);

        printf("Intervalo 2: posicoes %d a %d | IDs %d a %d\n",
               final2, final2 + 999, produtos[final2].id, produtos[final2 + 999].id);
        tempoFinal += testarIntervaloHash(hash, produtos, final2, final2 + 999);

        printf("Intervalo 3: posicoes %d a %d | IDs %d a %d\n",
               final3, final3 + 999, produtos[final3].id, produtos[final3 + 999].id);
        tempoFinal += testarIntervaloHash(hash, produtos, final3, final3 + 999);

        printf("Tempo do bloco [FINAL]: %.6f segundos\n", tempoFinal);
        tempoTotalExecucao += tempoFinal;

        printf("\n[INEXISTENTES]\n");
        printf("Busca de 1000 IDs inexistentes\n");

        double tempoInexistentes = testarInexistentesHash(hash);

        printf("Tempo do bloco [INEXISTENTES]: %.6f segundos\n", tempoInexistentes);
        tempoTotalExecucao += tempoInexistentes;

        printf("\nTempo total da execucao %d: %.6f segundos\n",
               execucao, tempoTotalExecucao);

        somaTempoTotal += tempoTotalExecucao;
    }

    double tempoMedioTotal = somaTempoTotal / REPETICOES;
    double tempoMedioPorBusca = tempoMedioTotal / totalBuscasPorExecucao;

    printf("\n================ RESULTADOS FINAIS HASH ================\n");
    printf("Tempo medio total: %.6f segundos\n", tempoMedioTotal);
    printf("Tempo medio por busca: %.12e segundos\n", tempoMedioPorBusca);
}