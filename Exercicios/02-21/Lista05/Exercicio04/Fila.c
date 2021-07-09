#include "stdlib.h"
#include "stdio.h"
#include "Fila.h"

struct elemento{
    struct contato cont;
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

int insere_fila(Fila *fi, struct contato c){
    if(fi == NULL)
        return 0;
    Elem *elem = (Elem*)malloc(sizeof(Elem));
    if(elem == NULL)
        return 0;
    elem->cont = c;
    elem->prox = NULL;
    if(fi->final == NULL)
        fi->inicio = elem;
    else
        fi->final->prox = elem;
    fi->final = elem;
    fi->qtd++;
}

int remove_fila(Fila *fi){
    if(fi == NULL || fi->inicio == NULL)
        return 0;
    Elem *elem = fi->inicio;
    fi->inicio = fi->inicio->prox;
    if(fi->inicio == NULL)
        fi->final = NULL;
    printf("\n## Proximo da Fila ##\n");
    printf("\tID: %d\n", elem->cont.ID);
    printf("\tNome: %s\n", elem->cont.nome);
    printf("\tTelefone: %d\n", elem->cont.tel);
    free(elem);
    fi->qtd--;
    return 1;
}

void libera_fila(Fila *fi){
    if(fi != NULL){
        Elem *elem;
        while(fi->inicio != NULL){
            elem = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(elem);
        }
        free(fi);
    }
}