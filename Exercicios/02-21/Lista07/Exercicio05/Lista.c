#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Lista.h"

struct no{
    char nome[30];
    struct no *prox;
};
typedef struct no No;

ListaNomes* cria_lista(){
    ListaNomes *li = (ListaNomes*)malloc(sizeof(ListaNomes));
    if(li != NULL)
        *li = NULL;
    return li;
}

int insere_lista_ordenado(ListaNomes *li, char *nome){
    if(li == NULL)
        return 0;
    No* no = (No*)malloc(sizeof(No));
    if(no == NULL)
        return 0;
    strcpy(no->nome, nome);
    if((*li) == NULL){
        printf("\nPRIMEIRO\n");
        no->prox = NULL;
        *li = no;
    }
    else{
        No* no_aux = *li;
        No* no_ant = NULL;
        printf("\nNOME: %s", nome);
        printf("\nNO: %s", no_aux->nome);
        printf("\nCOMP: %d\n", strcmp(nome, no_aux->nome));
        while(no_aux->prox != NULL && strcmp(nome, no_aux->nome) > 0){
            no_ant = no_aux;
            no_aux = no_aux->prox;
        }
        if(no_aux->prox == NULL){
            if(strcmp(nome, no_aux->nome) < 0){
                if(no_aux == (*li)){
                    no->prox = no_aux;
                    (*li) = no;
                }
                else{
                    no->prox = no_aux;
                    no_ant->prox = no;
                }
            }
            else{
                no->prox = NULL;
                no_aux->prox = no;
            }
        }
        else{
            if(no_aux == (*li)){
                no->prox = no_aux;
                (*li) = no;
            }
            else{
                no->prox = no_aux;
                no_ant->prox = no;
            }
        }
    }
    return 1;
}

void imprime_lista(ListaNomes *li){
    if(li == NULL)
        return;
    if((*li) == NULL)
        return;
    No* no = *li;
    printf("\n[");
    while(no != NULL){
        printf("%s, ", no->nome);
        no = no->prox;
    }
    printf("]\n");
}

void libera_lista(ListaNomes *li){
    if(li != NULL){
        No* aux;
        while((*li) != NULL){
            aux = (*li);
            (*li) = (*li)->prox;
            free(aux);
        }
        free(li);
    }
}