#include <stdio.h>
#include "testes.h"
#include "hash.h"

void executar_testes(void) {
    printf("Executando testes base...\n");
    printf("Hash de 'teste': %u\n", hash_function("teste"));
}
