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

int troca_elementos(Lista *li, int ind1, int ind2){
    if(li == NULL)
        return 0;
    No *aux1, *aux1_ant = NULL, *aux2, *aux2_ant = NULL;
    No *aux = *li, *aux_ant = NULL;
    int i = 0;
    while(aux != NULL){
        if(i == ind1){
            aux1 = aux;
            aux1_ant = aux_ant;
        }
        if(i == ind2){
            aux2 = aux;
            aux2_ant = aux_ant;
        }
        aux_ant = aux;
        aux = aux->prox;
        i++;
    }
    if(aux1 != NULL && aux2 != NULL){
        aux = aux1->prox;
        aux1_ant->prox = aux2;
        aux1->prox = aux2->prox;
        aux2_ant->prox = aux1;
        aux2->prox = aux;
    }
    return 1;
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