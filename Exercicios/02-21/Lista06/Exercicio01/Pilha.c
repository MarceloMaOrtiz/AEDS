#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

struct elemento{
    struct TipoItem item;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_pilha(){
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

int insere_pilha(Pilha *pi, struct TipoItem item){
    if(pi == NULL)
        return 0;
    Elem* elem = (Elem*)malloc(sizeof(Elem));
    if(elem == NULL)
        return 0;
    elem->item = item;
    elem->prox = (*pi);
    *pi = elem;
    return 1;
}

int remove_pilha(Pilha *pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *elem = *pi;
    *pi = elem->prox;
    free(elem);
    return 1;
}

int remove_item_pilha(Pilha *pi, struct TipoItem item){
    Pilha *aux = cria_pilha();
    Elem *elem;
    elem = *pi;
    while(elem->item.chave != item.chave){
        insere_pilha(aux, elem->item);
        remove_pilha(pi);
        elem = *pi;
    }
    remove_pilha(pi);
    elem = *aux;
    while((*aux) != NULL){
        insere_pilha(pi, elem->item);
        remove_pilha(aux);
        elem = *aux;
    }
    return 1;
}

void imprime_pilha(Pilha *pi){
    Elem *elem;
    elem = *pi;
    printf("\n\tPilha\n[ ");
    while(elem != NULL){
        printf("%c, ", elem->item.chave);
        elem = elem->prox;
    }
    printf("]\n");
}

void libera_pilha(Pilha *pi){
    if(pi != NULL){
        Elem *elem;
        while((*pi) != NULL){
            elem = *pi;
            *pi = (*pi)->prox;
            free(elem);
        }
        free(pi);
    }
}