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

int troca_elementos(Lista* li, struct no el1, struct no el2){
    if(li == NULL)
        return 0;
    struct no aux;
    int i = 0;
    while(i < li->qtd && li->nos[i].num != el1.num){
        i++;
    }
    int j = 0;
    while(j < li->qtd && li->nos[j].num != el2.num){
        j++;
    }
    if (i == li->qtd || j == li->qtd)
        return 0;
    aux = li->nos[i];
    li->nos[i] = li->nos[j];
    li->nos[j] = aux;
    return 1;
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