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

int iguais(Pilha *p1, Pilha *p2){
    if(p1 == NULL && p2 == NULL)
        return 0;
    Pilha *aux1, *aux2;
    aux1 = cria_pilha();
    aux2 = cria_pilha();
    Elem *elem1, *elem2;
    elem1 = *p1;
    elem2 = *p2;
    while(elem1 != NULL){
        if(elem1->num != elem2->num){
            elem1 = *aux1;
            elem2 = *aux2;
            while(elem1 != NULL){
                insere_pilha(p1, elem1->num);
                insere_pilha(p2, elem2->num);
                remove_pilha(aux1);
                remove_pilha(aux2);
                elem1 = *aux1;
                elem2 = *aux2;
            }
            libera_pilha(aux1);
            libera_pilha(aux2);
            return 0;
        }
        insere_pilha(aux1, elem1->num);
        insere_pilha(aux2, elem2->num);
        remove_pilha(p1);
        remove_pilha(p2);
        elem1 = *p1;
        elem2 = *p2;
    }
    int igual = 1;
    if(elem2 != NULL)
        igual = 0;
    elem1 = *aux1;
    elem2 = *aux2;
    while(elem1 != NULL){
        insere_pilha(p1, elem1->num);
        insere_pilha(p2, elem2->num);
        remove_pilha(aux1);
        remove_pilha(aux2);
        elem1 = *aux1;
        elem2 = *aux2;
    }
    libera_pilha(aux1);
    libera_pilha(aux2);
    if(!igual)
        return 0;
    return 1;
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