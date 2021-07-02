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

void inssub(Lista *l1, int i1, Lista *l2, int i2, int len){
    if(l1 == NULL || l2 == NULL)
        return;
    Lista *nova_lista = cria_lista();
    No *aux1 = *l1;
    No *aux2 = *l2;
    int i = 1;
    while(i < i1){
        aux1 = aux1->prox;
        i++;
    }
    i = 0;
    while(i < i2){
        aux2 = aux2->prox;
        i++;
    }
    i = 0;
    while(i < len){
        insere_lista(nova_lista, aux2->valor);
        aux2 = aux2->prox;
        i++;
    }
    No *aux_nova = *nova_lista;
    No *aux = aux1->prox;
    aux1->prox = aux_nova;
    while(aux_nova->prox != NULL)
        aux_nova = aux_nova->prox;
    aux_nova->prox = aux;
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