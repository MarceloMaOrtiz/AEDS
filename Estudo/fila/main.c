// Fila
//  - Sequência de elementos do mesmo tipo
//      - Tipo especial de lista
//          - Inserções e exclusões de elementos ocorrem nas extremidades da lista
//              - Insere de um lado (inicio), e remove do outro (final)
//  - Aplicações
//      - Controle de Fluxo
//      - Recursos compartilhados (Impressora, transações de BDs, ...)
//  - Operações básicas (Dependendo do tipo de alocação de memória utilizada - Estática ou Dinâmica)
//      - Criação da Fila
//      - Inserção de um elemento no final
//      - Remoção de um elemento no inicio
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
//  - Fila de Prioridade
//      - Tipo especial de fila que generaliza a ideia de "ordenação"
//      - Os elementos inseridos na fila possuem um dado extra
//          - A Prioridade
//              - Valor que determina a posição do elemento na fila
//      - Aplicações
//          - Qualquer problema em que seja preciso estabelecer uma 
//              prioridade de acesso
//          - Exemplos
//              - Processos em um processador
//              - Filas de pacientes
//              - Sistemas Operacionais (manipulação de interrupções)
//              - Algoritmo de Dijkstra
//              - Compressão de Dados (código de Huffman)
//      - Operações
//          - Criação da Fila
//          - Inserção de um elemento na fila com prioridade
//          - Remoção do elemento da fila com maior prioridade
//          - Acesso do elemento do início da fila (maior prioridade)
//          - Destruição da Fila
//      - Operações dependem da implementação
//          - Lista Dinâmica Encadeada
//              - Inserção -> O(n)
//              - Remoção -> O(1)
//          - Array desordenado
//              - Inserção -> O(1)
//              - Remoção -> O(n)
//          - Array ordenado
//              - Inserção -> O(n)
//              - Remoção -> O(1)
//          - Heap Binária
//              - Inserção -> O(log(n))
//              - Remoção -> O(log(n))
//      - Será desenvolvida uma Fila de Prioridade Estática
//          - Utiliza a mesma estrutura da Lista Sequencial Estática
//              - Utiliza um array par armazenar os elementos
//          - O uso do array permite que seja utilizada a mesma estrutura
//              para duas implementações distintas. (Basta mudar a implementação
//              da inserção, remoção e consulta)
//              - Array Ordenado
//                  - Elementos na fila são ordenados de forma crescente dentro
//                  do array
//                  - Elemento de maior prioridade estará no final do array
//                  - Elemento de menor prioridade estará no incio do array
//              - Heap Binária
//                  - Permite simular uma árvore binária completa ou quase completa
//                      (Exceção no último nível)
//                  - pai(i)
//                      - filho_esq = 2*i + 1
//                      - filho_dir = 2*i + 2
//                  - O pai tem sempre uma prioridade maior ou igual à prioridade
//                      de seus filhos

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "aluno.h"
#include "FilaEstatica.h"
#include "FilaDinamica.h"
#include "FilaPrioridadeEstatica.h"


int main(){
    struct aluno dados_aluno;
    dados_aluno.matricula = 123;
    strcpy(dados_aluno.nome, "Marcelo");
    dados_aluno.n1 = 8;
    dados_aluno.n2 = 9;
    dados_aluno.n3 = 10;
    int x;

    FilaEstatica *fe;

    fe = cria_fila_estatica();
    x = insere_fila_estatica(fe, dados_aluno);
    x = consulta_fila_estatica(fe, &dados_aluno);
    x = remove_fila_estatica(fe);
    libera_fila_estatica(fe);

    printf("\nFim da Fila Estatica\n");

    // Fila Dinâmica
    //  - É possível utilizar um Nó Descritor
    //      - Representando o início, final e uma indicação de final de fila

    FilaDinamica *fd;
    fd = cria_fila_dinamica();
    x = insere_fila_dinamica(fd, dados_aluno);
    x = consulta_fila_dinamica(fd, &dados_aluno);
    x = remove_fila_dinamica(fd);
    libera_fila_dinamica(fd);

    printf("\nFim da Fila Dinâmica\n");

    // Fila de Prioridade

    FilaPrio* fp_array;

    char nome[30];

    fp_array = cria_fila();
    x = insere_fila_array(fp_array, "Marcelo", 10);
    x = insere_fila_array(fp_array, "Sama", 8);
    x = insere_fila_array(fp_array, "Ravena", 12);
    x = insere_fila_array(fp_array, "Walter", 9);
    x = remove_fila_array(fp_array);
    x = consulta_fila_array(fp_array, nome);

    libera_fila(fp_array);

    FilaPrio* fp_heap;
    fp_heap = cria_fila();
    x = insere_fila_heap(fp_heap, "Marcelo", 10);
    x = insere_fila_heap(fp_heap, "Sama", 8);
    x = insere_fila_heap(fp_heap, "Ravena", 12);
    x = insere_fila_heap(fp_heap, "Walter", 9);
    x = remove_fila_heap(fp_heap);
    x = consulta_fila_heap(fp_heap, nome);

    libera_fila(fp_heap);

    printf("\nFim da Fila de Prioridade\n");

    printf("\nFim\n");

    return 0;
}