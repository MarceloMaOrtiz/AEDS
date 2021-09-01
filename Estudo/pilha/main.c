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