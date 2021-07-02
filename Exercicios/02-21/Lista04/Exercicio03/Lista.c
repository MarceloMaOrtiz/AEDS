#include "stdio.h"
#include "stdlib.h"
#include "Lista.h"

struct lista {
    int qtd;
    struct dado dados[MAX];
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

int insere_lista(Lista* li, struct dado d){
    if(li == NULL)
        return 0;
    if(lista_cheia(li))
        return 0;
    li->dados[li->qtd] = d;
    li->qtd++;
    return 1;
}

int insere_lista_indice(Lista* li, struct dado d, int ind){
    if(li == NULL)
        return 0;
    struct dado atual, pos;
    atual = li->dados[ind];
    int i = ind;
    while(i < li->qtd){
        pos = li->dados[i+1];
        li->dados[i+1] = atual;
        atual = pos;
        i++;
    }
    li->dados[ind] = d;
    li->qtd++;
    return 1;
}

void inssub(Lista *l1, int i1, Lista *l2, int i2, int len){
    if(l1 == NULL || l2 == NULL)
        return;
    if(l1->qtd + len >= MAX || i1 + len >= MAX || i2 + len >= MAX)
        return;
    int i = 0;
    while(i < len){
        struct dado dado2 = l2->dados[i2+i];
        insere_lista_indice(l1, dado2, i1+i);
        i++;
    }
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    int i = 0;
    printf("\n");
    while(i < li->qtd){
        printf("%d - ", li->dados[i].num);
        i++;
    }
}

void libera_lista(Lista* li){
    free(li);
}