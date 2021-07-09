#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Pilha.h"

struct elemento{
    struct carro car;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_pilha(){
    Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

int tamanho_pilha(Pilha* pi){
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int insere_pilha(Pilha *pi, struct carro c){
    if(pi == NULL)
        return 0;
    Elem* elem = (Elem*)malloc(sizeof(Elem));
    if(elem == NULL)
        return 0;
    elem->car = c;
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

int remove_carro_pilha(Pilha *pi, struct carro c){
    Pilha *aux = cria_pilha();
    int manobras;
    Elem *elem;
    elem = *pi;
    while(strcmp(elem->car.placa, c.placa) != 0){
        elem->car.manobras++;
        insere_pilha(aux, elem->car);
        remove_pilha(pi);
        elem = *pi;
    }
    manobras = elem->car.manobras;
    remove_pilha(pi);
    elem = *aux;
    while((*aux) != NULL){
        insere_pilha(pi, elem->car);
        remove_pilha(aux);
        elem = *aux;
    }
    return manobras;
}

void imprime_pilha(Pilha *pi){
    Elem *elem;
    elem = *pi;
    printf("\n\tPilha\n[ ");
    while(elem != NULL){
        printf("%s, %d - ", elem->car.placa, elem->car.manobras);
        elem = elem->prox;
    }
    printf("]\n");
}

int processa_entradas(struct entrada entradas[], int tam){
    Pilha *pilha = cria_pilha();
    for(int i = 0; i < tam; i++){
        if(entradas[i].sentido == 'E'){
            printf("\n\tCarro %s chegou!", entradas[i].car.placa);
            if(tamanho_pilha(pilha) < 10){
                insere_pilha(pilha, entradas[i].car);
                printf(" Estacionado.\n");
            }
            else{
                printf(" Estacionamento cheio. Carro partiu.\n");
            }
        }else{
            int manobras;
            manobras = remove_carro_pilha(pilha, entradas[i].car);
            printf("\n\tCarro %s saiu! Manobras: %d\n", entradas[i].car.placa, manobras);
        }
    }
    libera_pilha(pilha);
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