#include "stdio.h"
#include "stdlib.h"
#include "Lista.h"

struct lista {
    int qtd;
    struct no nos[MAX];
};

Lista* cria_lista(){
    Lista *li;
    li = (Lista*)malloc(sizeof(struct lista));
    if (li != NULL)
        li->qtd = 0;
    return li;
}

int lista_cheia(Lista* li){
    return (li->qtd == MAX);
}

int insere_lista(Lista* li, struct no no){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li->nos[li->qtd] = no;
    li->qtd++;
    return 1;
}

int insere_lista(Lista* li, struct no no, int ind){
    int i = ind;
    while(i < li->qtd){
        struct no aux = li->nos[i];
    }
}

void inssub(Lista *l1, int i1, Lista *l2, int i2, int len){
    if(l1 == NULL || l2 == NULL)
        return;
    if(l1->qtd + len >= MAX || i1 + len >= MAX || i2 + len >= MAX)
        return;
    int i = 0;
    while(i < len){
        
        i++;
    }
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    int i = 0;
    printf("\n");
    while(i < li->qtd){
        printf("%d - ", li->nos[i].num);
        i++;
    }
}

void libera_lista(Lista* li){
    free(li);
}