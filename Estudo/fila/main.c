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