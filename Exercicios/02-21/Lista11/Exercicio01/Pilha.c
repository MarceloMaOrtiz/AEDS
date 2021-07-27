#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

struct no{
    int indice;
    struct no *prox;
};
typedef struct no No;

Pilha *criar(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    if(p != NULL)
        *p = NULL;
    return p;
}

int vazia(Pilha *p){
    if(p == NULL || *p == NULL)
        return 1;
    return 0;
}

int inserir(Pilha *p, int n){
    if(p == NULL)
        return 0;
    No* no = (No*)malloc(sizeof(No));
    if(no == NULL)
        return 0;
    no->indice = n;
    no->prox = (*p);
    *p = no;
    return 1;
}

int consultar(Pilha *p, int *n){
    if(p == NULL)
        return 0;
    if((*p) == NULL)
        return 0;
    *n = (*p)->indice;
    return 1;
}

int remover(Pilha *p){
    if(p == NULL)
        return 0;
    if((*p) == NULL)
        return 0;
    No *no = (*p);
    *p = no->prox;
    free(no);
    return 1;
}

void liberar(Pilha *p){
    if(p != NULL){
        No *no;
        while((*p) != NULL){
            no = *p;
            *p = (*p)->prox;
            free(no);
        }
        free(p);
    }
}