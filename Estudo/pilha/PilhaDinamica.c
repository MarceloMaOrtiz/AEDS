// O tipo de dados pilha
// Implementar as suas funções

#include "stdlib.h"
#include "stdio.h"
#include "aluno.h"
#include "PilhaDinamica.h"

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

PilhaDinamica* cria_pilha_dinamica(){
    PilhaDinamica* pi = (PilhaDinamica*)malloc(sizeof(PilhaDinamica));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

int tamanho_pilha_dinamica(PilhaDinamica* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int pilha_dinamica_vazia(PilhaDinamica* pi){
    if(pi == NULL || *pi == NULL)
        return 1;
    return 0;
}

int insere_pilha_dinamica(PilhaDinamica* pi, struct aluno al){
    if(pi == NULL)
        return 0;
    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int consulta_topo_pilha_dinamica(PilhaDinamica* pi, struct aluno *al){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int remove_pilha_dinamica(PilhaDinamica* pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

void libera_pilha_dinamica(PilhaDinamica* pi){
    if(pi != NULL){
        Elem *no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}