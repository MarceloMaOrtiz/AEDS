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

int max_no(ArvBin* raiz){
    if(*raiz == NULL)
        return -1215752191;

    int res = (*raiz)->valor;
    int left_res = max_no(&((*raiz)->esq));
    int right_res = max_no(&((*raiz)->dir));
    if(left_res > res)
        res = left_res;
    if(right_res > res)
        res = right_res;
    return res;
}

int min_no(ArvBin* raiz){
    if(*raiz == NULL)
        return 1215752191;

    int res = (*raiz)->valor;
    int left_res = min_no(&((*raiz)->esq));
    int right_res = min_no(&((*raiz)->dir));
    if(left_res < res)
        res = left_res;
    if(right_res < res)
        res = right_res;
    return res;
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