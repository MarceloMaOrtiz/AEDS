#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

struct no{
    int valor;
    struct no *esq;
    struct no *dir;
};

#define COUNT 3

ArvBin *criar(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int vazia(ArvBin *raiz){
    if(raiz == NULL){
        return 1;
    }
    if(*raiz == NULL){
        return 1;
    }
    return 0;
}

int inserir(ArvBin *raiz, int num){
    if(raiz == NULL)
        return 0;
    struct no* novo;
    novo = (struct no*)malloc(sizeof(struct no));
    if(novo == NULL)
        return 0;
    novo->valor = num;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct no* atual = *raiz;
        struct no* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(num == atual->valor){
                free(novo);
                return 0; // Elemento já existe
            }
            if(num > atual->valor)
                atual = atual->dir;
            else
                atual = atual->esq; 
        }
        if(num > ant->valor)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

int eh_binaria_busca(No* raiz, No* left, No* right){
    if(raiz == NULL)
        return 1;
    if(left != NULL && raiz->valor <= left->valor)
        return 0;
    if(right != NULL && raiz->valor >= right->valor)
        return 0;
    return eh_binaria_busca(raiz->esq, left, raiz) && eh_binaria_busca(raiz->dir, raiz, right);
}

void liberar_no(struct no* no){
    if(no == NULL)
        return;
    liberar_no(no->esq);
    liberar_no(no->dir);
    free(no);
    no = NULL;
}

void liberar(ArvBin *raiz){
    if(raiz == NULL)
        return;
    liberar_no(*raiz);
    free(raiz);
}