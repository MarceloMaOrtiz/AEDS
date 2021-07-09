#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

struct elemento{
    char letra;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_pilha(){
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

int insere_pilha(Pilha *pi, char c){
    if(pi == NULL)
        return 0;
    Elem* elem = (Elem*)malloc(sizeof(Elem));
    if(elem == NULL)
        return 0;
    elem->letra = c;
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

Pilha* inverte_letras(Pilha *pi){
    Pilha *resultado = cria_pilha();
    Pilha *aux_min = cria_pilha();
    Elem *elem, *elem_min;
    remove_pilha(pi);
    remove_pilha(pi);
    elem = *pi;
    while(elem != NULL){
        if(elem->letra == ' '){
            elem_min = *aux_min;
            while(elem_min != NULL){
                insere_pilha(resultado, elem_min->letra);
                remove_pilha(aux_min);
                elem_min = *aux_min;
            }
            insere_pilha(resultado, ' ');
        }else{
            insere_pilha(aux_min, elem->letra);
        }
        remove_pilha(pi);
        elem = *pi;
    }
    elem_min = *aux_min;
    while(elem_min != NULL){
        insere_pilha(resultado, elem_min->letra);
        remove_pilha(aux_min);
        elem_min = *aux_min;
    }
    libera_pilha(aux_min);
    return resultado;
}

void imprime_pilha(Pilha *pi){
    Elem *elem;
    elem = *pi;
    printf("\n\tPilha\n");
    while(elem != NULL){
        printf("%c", elem->letra);
        elem = elem->prox;
    }
    printf("\n");
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