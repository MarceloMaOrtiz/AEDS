// O Sucessor de um elemento ocupa a posição física seguinte
// O tipo de dados pilha
// Implementar as suas funções

#include "stdlib.h"
#include "stdio.h"
#include "aluno.h"
#include "PilhaEstatica.h"

struct pilha_estatica{
    int qtd;
    struct aluno dados[MAX];
};

PilhaEstatica* cria_pilha_estatica(){
    PilhaEstatica *pi = (PilhaEstatica*)malloc(sizeof(PilhaEstatica));
    if(pi != NULL)
        pi->qtd = 0;
    return pi;
}

int pilha_estatica_vazia(PilhaEstatica* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == 0);
}

int pilha_estatica_cheia(PilhaEstatica* pi){
    if(pi == NULL)
        return -1;
    return (pi->qtd == MAX);
}

int insere_pilha_estatica(PilhaEstatica* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    if(pilha_estatica_cheia(pi))
        return 0;
    pi->dados[pi->qtd] = al;
    pi->qtd++;
    return 1;
}

int consulta_topo_pilha_estatica(PilhaEstatica* pi, struct aluno *al){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    *al = pi->dados[pi->qtd - 1];
    return 1;
}

int remove_pilha_estatica(PilhaEstatica* pi){
    if(pi == NULL || pi->qtd == 0)
        return 0;
    pi->qtd--;
    return 1;
}

void libera_pilha_estatica(PilhaEstatica* pi){
    free(pi);
}