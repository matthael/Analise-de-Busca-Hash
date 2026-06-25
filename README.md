# Analise-de-Busca-Hash

# Sistema de Busca com Tabela Hash

## Descrição do Projeto

Este projeto foi desenvolvido para a disciplina de **Projeto Integrador II**, com o objetivo de implementar e avaliar o desempenho de uma **Tabela Hash** para busca de registros em grandes volumes de dados.

O sistema realiza a leitura de um dataset contendo **200.003 registros**, armazena os dados em uma estrutura Hash e executa operações de busca para medir sua eficiência. Posteriormente, os resultados foram comparados com uma implementação anterior baseada em **Busca Sequencial**, permitindo uma análise comparativa entre as duas abordagens.

---

## Objetivos

* Implementar uma estrutura de dados do tipo Tabela Hash.
* Carregar um dataset com mais de 200 mil registros.
* Realizar buscas por chaves específicas.
* Medir o desempenho da estrutura.
* Comparar os resultados com a Busca Sequencial.
* Avaliar a eficiência da função hash utilizada.

---

## Tecnologias Utilizadas

* Linguagem C
* Compilador GCC
* Visual Studio Code
* Estruturas de Dados

  * Tabela Hash
  * Vetores
  * Busca Sequencial

---

## Estrutura do Projeto

Estrutura do projeto criada com as pastas principais:

- data/
- src/
- artigo/
- README.md
- Makefile

---

## Funcionamento

### 1. Carregamento dos Dados

O sistema realiza a leitura do dataset fornecido pelo professor e carrega todos os registros para a estrutura Hash.

Quantidade de registros processados:

```
200.003 registros
```

---

### 2. Inserção na Tabela Hash

Cada registro recebe uma posição calculada por meio da função hash implementada.

```
indice = funcaoHash(chave);
```

A função hash é responsável por distribuir os registros dentro da tabela, reduzindo a ocorrência de colisões e aumentando a eficiência das consultas.

---

### 3. Busca de Registros

Após a construção da tabela, o sistema realiza buscas em diferentes posições do conjunto de dados para avaliar o desempenho da estrutura.

As consultas são executadas utilizando diretamente o índice calculado pela função hash.

---

## Resultados Obtidos

### Quantidade de Registros

| Métrica              | Valor   |
| -------------------- | ------- |
| Registros carregados | 200.003 |

### Colisões

| Métrica           | Valor |
| ----------------- | ----- |
| Total de colisões | 0     |

### Tempo Total das Execuções

| Execução | Tempo   |
| -------- | ------- |
| 1        | 0,003 s |
| 2        | 0,003 s |
| 3        | 0,000 s |
| Média    | 0,002 s |

### Tempo Médio por Busca

```text
0,0000002 segundos
```

---

## Comparação com Busca Sequencial

| Métrica               | Busca Sequencial | Tabela Hash |
| --------------------- | ---------------- | ----------- |
| Registros carregados  | 200.003          | 200.003     |
| Tempo médio total     | 5,251333 s       | 0,002 s     |
| Tempo médio por busca | 0,000583 s       | 0,0000002 s |
| Complexidade Teórica  | O(n)             | O(1)        |
| Escalabilidade        | Baixa            | Alta        |

---

## Complexidade Computacional

### Busca Sequencial

```text
Melhor caso: O(1)
Caso médio: O(n)
Pior caso: O(n)
```

### Tabela Hash

```
Melhor caso: O(1)
Caso médio: O(1)
Pior caso: O(n)
```

O pior caso da Tabela Hash ocorre apenas quando existe um grande número de colisões, situação que não foi observada nos testes realizados.

---

## Principais Vantagens da Tabela Hash

* Busca extremamente rápida.
* Tempo de acesso praticamente constante.
* Excelente desempenho em grandes volumes de dados.
* Alta escalabilidade.
* Ausência de colisões durante os testes.

---

## Limitações

* Maior consumo de memória.
* Dependência da qualidade da função hash.
* Possível degradação em cenários com muitas colisões.

---

## Conclusão

Os testes realizados demonstraram que a implementação utilizando Tabela Hash apresentou desempenho significativamente superior ao método de Busca Sequencial. Enquanto a Busca Sequencial apresentou crescimento linear do tempo de execução, a Tabela Hash manteve tempo praticamente constante mesmo trabalhando com mais de 200 mil registros.

Os resultados confirmam que a utilização de Tabelas Hash é uma solução eficiente para sistemas que exigem alta performance em operações de busca e recuperação de dados.

---

## Autores

* Bruno Nóbrega Souza
* Matheus Ferreira da Silva Ponte
* Guilherme Alves Castro

Instituto de Educação Superior de Brasília (IESB)

Projeto Integrador II – Ciência da Computação