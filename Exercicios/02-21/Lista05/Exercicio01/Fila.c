#include "stdio.h"
#include "stdlib.h"
#include "Fila.h"

struct elemento{
    struct processo proc;
    struct elemento *prox;
};
typedef struct elemento Elem;

struct fila{
    Elem *inicio;
    Elem *final;
    int qtd;
};

Fila* cria_fila(){
    Fila* fi = (Fila*)malloc(sizeof(Fila));
    if(fi != NULL){
        fi->inicio = NULL;
        fi->final = NULL;
        fi->qtd = 0;
    }
}

int insere_fila(Fila* fi, struct processo p){
    if(fi == NULL)
        return 0;
    Elem *elem = (Elem*)malloc(sizeof(Elem));
    if(elem == NULL)
        return 0;
    elem->proc = p;
    elem->prox = NULL;
    if(fi->final == NULL)
        fi->inicio = elem;
    else
        fi->final->prox = elem;
    fi->final = elem;
    fi->qtd++;
    return 1;
}

int remove_fila(Fila* fi){
    if(fi == NULL || fi->inicio == NULL)
        return 0;
    Elem *elem = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->final == NULL)
        fi->final = NULL;
    free(elem);
    fi->qtd--;
    return 1;
}

void imprimir_fila(Fila* fi){
    if(fi == NULL || fi->inicio == NULL)
        return;
    Elem *elem = fi->inicio;
    printf("\n\t### Fila ###\n");
    printf("[ ");
    while(elem != NULL){
        printf("ID = %d; ", elem->proc.ID);
        elem = elem->prox;
    }
    printf("]\n\n");
}

int tamanho_fila(Fila* fi){
    if(fi == NULL || fi->inicio == NULL)
        return 0;
    return fi->qtd;
}

void libera_fila(Fila *fi){
    if(fi != NULL) {
        Elem *elem;
        while(fi->inicio != NULL){
            elem = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(elem);
        }
        free(fi);
    }
}

