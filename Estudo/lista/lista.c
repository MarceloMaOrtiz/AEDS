// Operações básica de uma lista
//  - Criação
//  - Inserção
//  - Exclusão
//  - Acesso
//  - Destruição
//  - etc...

// Alocação da Memória
// Estática (Vetor)
//  - Exige a definição do número máximo
//  - Espaço de memória é alocada no momento da compilação
//  - Acesso sequencial
//      - Elementos consecutivos na memória
//      - É possível acessar um elemento através do índice
// Dinâmica
//  - Cresce ou diminui a medida que nova funções são executadas
//  - Espaço de memória alocado em tempo de execução
//  - Acesso encadeado
//      - Cada elemento pode estar em uma área distinta da memória
//      - Necessário percorrer todos elementos antecessores até chegar no elemento desejado

// Bibliotecas para auxiliar no debug do segmentation fault
// Link: https://stackoverflow.com/questions/77005/how-to-automatically-generate-a-stacktrace-when-my-program-crashes/77336#77336
#include <execinfo.h>
#include <signal.h>
#include <unistd.h>

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "aluno.h"
#include "ListaSequencial.h"
#include "ListaDinEncad.h"
#include "ListaDinEncadDupla.h"

// $ gcc -g -rdynamic ./test.c -o test
void handler(int sig) {
    void *array[10];
    size_t size;

    // get void*'s for all entries on the stack
    size = backtrace(array, 10);

    // print out all the frames to stderr
    fprintf(stderr, "Error: signal %d:\n", sig);
    backtrace_symbols_fd(array, size, STDERR_FILENO);
    exit(1);
}

void baz() {
    int *foo = (int*)-1; // make a bad pointer
    printf("%d\n", *foo);       // causes segfault
}

void bar() { baz(); }
void foo() { bar(); }

int main(){
    signal(SIGSEGV, handler);   // install our handler

    // Lista Sequencial Estática - Vetor
    //  - O sucessor ocupa a posição física seguinte
    //  - Vantagens
    //      - Acesso rápido e direto aos elementos (ìndice)
    //      - Tempo constante para acessar um elemento
    //      - Facilidade de modificar informações
    //  - Desvantagens
    //      - Difinição prévia
    //      - Dificuldade de inserção e remoção de um elemento entre elementos
    //  - 3 Tipos de Inserção e Remoção variando com a posição na lista
    //      - Início
    //      - Meio
    //      - Fim
    //  - 2 Tipos de Consultas
    //      - Pela posição -> Direta
    //      - Pelo conteúdo -> Busca
    ListaSequencial *ls;
    ls = cria_lista_sequencial();
    struct aluno dados_aluno;
    struct aluno* dados_aluno_busca;
    dados_aluno_busca = (struct aluno*)malloc(sizeof(struct aluno));
    dados_aluno.matricula = 123;
    strcpy(dados_aluno.nome, "Marcelo");
    dados_aluno.n1 = 10;
    dados_aluno.n2 = 10;
    dados_aluno.n2 = 10;
    int x;
    x = insere_lista_sequencial_final(ls, dados_aluno);
    x = insere_lista_sequencial_inicio(ls, dados_aluno);
    x = insere_lista_sequencial_ordenada(ls, dados_aluno);
    x = consulta_lista_sequencial_pos(ls, 1, dados_aluno_busca);
    x = consulta_lista_sequencial_mat(ls, 123, dados_aluno_busca);
    x = remove_lista_sequencial_final(ls);
    x = remove_lista_sequencial_inicio(ls);
    x = remove_lista_sequencial(ls, dados_aluno);
    libera_lista_sequencial(ls);
    printf("\nFim Lista Sequencial\n");

    // Lista Dinâmica Encadeada
    //  - Cada elemento é tratado como um ponteiro que é alocado dinâmicamente
    //      - Para guardar o primeiro elemento será utilizado um ponteiro para ponteiro
    //      para auxiliar a mudança no início da lista, mudando somente o conteúdo do ponteiro
    //      inicial
    //  - Cada elemento aponta para o seu sucessor
    //  - É utilizado um ponteiro especial para o primeiro elemento
    //  - Ultimo elemento aponta para NULL
    //  - Vantagens
    //      - Melhor utilização dos recursos da memória
    //      - Nao precisa movimentar os elementos nas operações de inserção e remoção
    //  - Desvantagens
    //      - Acesso indireto aos elementos
    //          - Necessidade de percorres a lista para acessar algum nó
    //  - 3 Tipos de Inserção e Remoção variando com a posição na lista
    //      - Início
    //      - Meio
    //      - Fim
    //  - 2 Tipos de Consultas
    //      - Pela posição -> Direta
    //      - Pelo conteúdo -> Busca

    struct aluno dados_aluno_din;
    struct aluno* dados_aluno_busca_din;
    dados_aluno_busca_din = (struct aluno*)malloc(sizeof(struct aluno));
    dados_aluno_din.matricula = 123;
    strcpy(dados_aluno_din.nome, "Marcelo");
    dados_aluno_din.n1 = 10;
    dados_aluno_din.n2 = 10;
    dados_aluno_din.n2 = 10;
    ListaDinEncad* ld = cria_lista_din();
    x = insere_lista_din_inicio(ld, dados_aluno_din);
    x = insere_lista_din_fim(ld, dados_aluno_din);
    x = insere_lista_din_ordenada(ld, dados_aluno_din);
    x = consulta_lista_din_pos(ld, 1, dados_aluno_busca_din);
    x = consulta_lista_din_mat(ld, 123, dados_aluno_busca_din);
    x = remove_lista_din_inicio(ld);
    x = remove_lista_din_fim(ld);
    x = remove_lista_din(ld, dados_aluno_din);
    libera_lista_din(ld);
    printf("\nFim Lista Dinâmica Encadeada\n");

    // Lista Dinâmica Duplamente Encadeada
    //  - Cada elemento aponta para seu sucessor e antecessor
    //  - OBS: Usa um ponteiro especial para o primeiro elemento da lista e uma indicação
    //      de final de lista, nos dois sentidos.
    //  - Vantagens
    //      - Melhor utilização dos recursos de memória
    //      - Não precisa movimentar os elementos nas operações de inserção e remoção
    //  - Desvantagens
    //      - Acesso indireto aos elementos
    //      - Necessidade de percorrer a lista para acessar um elemento
    //  - 3 Tipos de Inserção e Remoção variando com a posição na lista
    //      - Início
    //      - Meio
    //      - Fim
    //  - 2 Tipos de Consultas
    //      - Pela posição -> Direta
    //      - Pelo conteúdo -> Busca

    struct aluno dados_aluno_din_dupla;
    struct aluno* dados_aluno_busca_din_dupla;
    dados_aluno_busca_din_dupla = (struct aluno*)malloc(sizeof(struct aluno));
    dados_aluno_din_dupla.matricula = 123;
    strcpy(dados_aluno_din_dupla.nome, "Marcelo");
    dados_aluno_din_dupla.n1 = 10;
    dados_aluno_din_dupla.n2 = 10;
    dados_aluno_din_dupla.n2 = 10;
    ListaDinEncadDupla* ldd = cria_lista_din_dupla();
    x = insere_lista_din_dupla_inicio(ldd, dados_aluno_din_dupla);
    x = insere_lista_din_dupla_fim(ldd, dados_aluno_din_dupla);
    x = insere_lista_din_dupla_ordenada(ldd, dados_aluno_din_dupla);
    x = consulta_lista_din_dupla_pos(ldd, 1, dados_aluno_busca_din);
    x = consulta_lista_din_dupla_mat(ldd, 123, dados_aluno_busca_din);
    x = remove_lista_din_dupla_inicio(ldd);
    x = remove_lista_din_dupla_fim(ldd);
    x = remove_lista_din_dupla(ldd, dados_aluno_din_dupla);
    libera_lista_din_dupla(ldd);
    printf("\nFim Lista Dinâmica Duplamente Encadeada\n");

    printf("\nFim\n");
    return 0;
}