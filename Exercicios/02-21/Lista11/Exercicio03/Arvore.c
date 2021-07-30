#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

struct no{
    int info;
    struct no *esq;
    struct no *dir;
};

ArvBin *criar(){
    ArvBin* raiz = (ArvBin*)malloc(sizeof(ArvBin));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int inserir(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct no* novo;
    novo = (struct no*)malloc(sizeof(struct no));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct no* atual = *raiz;
        struct no* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0; // Elemento já existe
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq; 
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
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

int altura(ArvBin *raiz){
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    }
    int alt_esq = altura(&((*raiz)->esq));
    int alt_dir = altura(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

int balanceada(ArvBin *raiz, int *height){
    int lh = 0, rh = 0;
    int l = 0, r = 0;

    if(*raiz == NULL){
        *height = 0;
        return 1;
    }

    l = balanceada(&((*raiz)->esq), &lh);
    r = balanceada(&((*raiz)->dir), &rh);

    *height = (lh > rh ? lh : rh) + 1;

    if(abs(lh - rh) >= 2)
        return 0;
    else{
        if(l && r){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int perfeitamente_balanceada(ArvBin *raiz, int *height){
    int lh = 0, rh = 0;
    int l = 0, r = 0;

    if(*raiz == NULL){
        *height = 0;
        return 1;
    }

    l = perfeitamente_balanceada(&((*raiz)->esq), &lh);
    r = perfeitamente_balanceada(&((*raiz)->dir), &rh);

    *height = (lh > rh ? lh : rh) + 1;

    if(abs(lh - rh) > 0)
        return 0;
    else{
        if(l && r){
            return 1;
        }
        else{
            return 0;
        }
    }
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