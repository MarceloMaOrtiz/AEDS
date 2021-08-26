#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "Pilha.h"

struct no{
    int numero;
    struct no *prox;
};
typedef struct no No;

No** cria(){
    No **novo = (No**)malloc(sizeof(No*));
    if(novo != NULL)
        *novo = NULL;
    return novo;
}

int vazia(No** head){
    if(head == NULL || *head == NULL)
        return 1;
    return 0;
}

int tamanho_pilha(No** head){
    if(vazia(head))
        return 0;
    int cont;
    No *aux = *head;
    while(aux != NULL){
        cont++;
        aux = aux->prox;
    }
    return cont;
}

void push(No** head, int num){
    if(head == NULL)
        return;
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL)
        return;
    novo->numero = num;
    novo->prox = *head;
    *head = novo;
}

int pop(No** head){
    if(vazia(head))
        return -1;
    int numero;
    No* topo = *head;
    numero = topo->numero;
    *head = topo->prox;
    free(topo);
    return numero;
    
}

int peek(No** head){
    if(vazia(head))
        return -1;
    return (*head)->numero;
}

void imprime_pilha(No** head){
    if(!vazia(head)){
        No* topo = *head;
        printf("\n[ ");
        while(topo != NULL){
            if(topo->prox == NULL)
                printf("%d ", topo->numero);
            else
                printf("%d | ", topo->numero);
            topo = topo->prox;
        }
        printf("]\n");
    }
}

void esvazia(No** head){
    if(head == NULL)
        return;
    while(*head != NULL)
        pop(head);
}

void libera(No** head){
    if(head != NULL){
        No* aux;
        while((*head) != NULL){
            aux = *head;
            *head = (*head)->prox;
            free(aux);
        }
        free(head);
    }
}