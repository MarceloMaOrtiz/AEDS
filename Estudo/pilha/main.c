// Pilha
//  - Sequência de elementos do mesmo tipo
//      - Tipo especial de lista
//          - Inserções e exclusões de elementos ocorrem na extremidade da lista
//              - Insere de um lado (inicio), e remove do mesmo lado (inicio)
//  - Aplicações
//      - Análise de uma expressão matemática
//      - Avaliação de uma expressão pós-fixa
//      - Converter uma expressão in-fixa para pós-fixa
//      - Converter um numero decimal para binário
//  - Operações básicas (Dependendo do tipo de alocação de memória utilizada - Estática ou Dinâmica)
//      - Criação da Fila
//      - Inserção de um elemento no inicio
//      - Remoção de um elemento do inicio
//      - Acessso ao elemento do início
//      - Destruição da fila
//  - Alocação Estática
//      - Espaço de memória é alocado no momento da compilação
//      - Exige a definição do número máximo de elementos
//      - Acesso sequencial, elementos consecutivos na memória
//  - Alocação Dinâmica
//      - Espaço de memória alocado em tempo de execução
//      - Acesso encadeado
//          - Cada elemento pode estar em uma área distinta da memória

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "aluno.h"
#include "PilhaEstatica.h"
#include "PilhaDinamica.h"

int main(){
    struct aluno dados_aluno, ler_dados_aluno;
    dados_aluno.matricula = 123;
    strcpy(dados_aluno.nome, "Marcelo");
    dados_aluno.n1 = 8;
    dados_aluno.n2 = 9;
    dados_aluno.n3 = 10;
    int x;

    PilhaEstatica* pe;
    pe = cria_pilha_estatica();
    x = insere_pilha_estatica(pe, dados_aluno);
    x = consulta_topo_pilha_estatica(pe, &ler_dados_aluno);
    x = remove_pilha_estatica(pe);
    libera_pilha_estatica(pe);

    printf("\nFim da Pilha Estatica\n");

    PilhaDinamica* pd;
    pd = cria_pilha_dinamica();
    x = insere_pilha_dinamica(pd, dados_aluno);
    x = consulta_topo_pilha_dinamica(pd, &ler_dados_aluno);
    x = remove_pilha_dinamica(pd);
    libera_pilha_dinamica(pd);

    printf("\nFim da Pilha Dinâmica\n");

    printf("\nFim\n");
}