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

int troca_elementos(Lista* li, int i, int j){
    if(li == NULL)
        return 0;
    if(i >= li->qtd || j >= li->qtd)
        return 0;
    struct dado aux;
    aux = li->dados[i];
    li->dados[i] = li->dados[j];
    li->dados[j] = aux;
    return 1;
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