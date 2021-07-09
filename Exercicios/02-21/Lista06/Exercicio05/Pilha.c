#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

struct elemento{
    int num;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_pilha(){
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

int insere_pilha(Pilha *pi, int num){
    if(pi == NULL)
        return 0;
    Elem* elem = (Elem*)malloc(sizeof(Elem));
    if(elem == NULL)
        return 0;
    elem->num = num;
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

Pilha* inverte(Pilha *pi){
    Pilha *aux = cria_pilha();
    Elem *elem;
    elem = *pi;
    while(elem != NULL){
        insere_pilha(aux, elem->num);
        remove_pilha(pi);
        elem = *pi;
    }
    return aux;
}

void imprime_pilha(Pilha *pi){
    Elem *elem;
    elem = *pi;
    printf("\n\tPilha\n[ ");
    while(elem != NULL){
        printf("%d, ", elem->num);
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