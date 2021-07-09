#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

struct elemento{
    float num;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_pilha(){
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

int insere_pilha(Pilha *pi, float num){
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

int maior_menor_media(Pilha *pi, float *maior, float *menor, float *media){
    Pilha *aux = cria_pilha();
    float soma = 0;
    int cont = 0;
    Elem *elem;
    elem = *pi;
    *maior = elem->num;
    *menor = elem->num;
    while(elem != NULL){
        insere_pilha(aux, elem->num);
        soma = soma + elem->num;
        remove_pilha(pi);
        if(elem->num > *maior)
            *maior = elem->num;
        if(elem->num < *menor)
            *menor = elem->num;
        cont++;
        // printf("\nMaior: %.2f", elem->num);
        elem = *pi;
    }
    elem = *aux;
    while(elem != NULL){
        insere_pilha(pi, elem->num);
        remove_pilha(aux);
        elem = *aux;
    }
    *media = soma/cont;
    libera_pilha(aux);
    return 1;
}

void imprime_pilha(Pilha *pi){
    Elem *elem;
    elem = *pi;
    printf("\n\tPilha\n[ ");
    while(elem != NULL){
        printf("%.2f, ", elem->num);
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