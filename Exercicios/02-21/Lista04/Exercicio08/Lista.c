#include "stdio.h"
#include "stdlib.h"
#include "Lista.h"

struct no{
    struct dado valor;
    struct no *prox;
};
typedef struct no No;

Lista* cria_lista(){
    Lista *li = (Lista*)malloc(sizeof(Lista));
    if(li == NULL)
        *li = NULL;
    return li;
}

int insere_lista(Lista *li, struct dado d){
    if(li == NULL)
        return 0;
    No *no = (No*)malloc(sizeof(No));
    if(no == NULL)
        return 0;
    no->valor = d;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no;
    }
    else{
        No *aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = no;
    }
    return 1;
}

void troca(Lista *li, struct dado d){
    if(li == NULL)
        return;
    No *aux = *li, *ant;
    int busca = 0;
    while(aux->prox != NULL && !busca){
        if(aux->valor.num == d.num)
            busca = 1;
        else{
            ant = aux;
            aux = aux->prox;
        }
    }
    if(aux->prox != NULL){
        No *aux_pos = aux->prox->prox;
        if(ant == NULL){
            (*li) = aux->prox;
            aux->prox->prox = aux;
            aux->prox = aux_pos;
        }else{
            ant->prox = aux->prox;
            aux->prox->prox = aux;
            aux->prox = aux_pos;
        }
    }
}

void imprime_lista(Lista *li){
    No *aux = *li;
    printf("\n");
    while(aux != NULL){
        printf("%d - ", aux->valor.num);
        aux = aux->prox;
    }
    printf("\n");
}

void libera_lista(Lista *li){
    if(li != NULL){
        No *aux;
        while((*li) != NULL){
            aux = (*li);
            (*li) = (*li)->prox;
            free(aux);
        }
        free(li);
    }
}