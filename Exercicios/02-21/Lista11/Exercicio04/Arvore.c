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

void no_insercao(ArvBin *raiz, struct no *no, int altura_arv, int altura, int *teste){
    if(raiz == NULL)
        return;
    if(*teste == 1){
        return;
    }
    if((*raiz)->esq == NULL && (*raiz)->dir != NULL && altura_arv - altura >= 1){
        no = *raiz;
        *teste = 1;
        return;
    }
    if((*raiz)->esq != NULL && (*raiz)->dir == NULL && altura_arv - altura >= 1){
        no = *raiz;
        *teste = 1;
        return;
    }
    if((*raiz)->esq == NULL && (*raiz)->dir == NULL){
        if(altura_arv - altura >= 1){
            no = *raiz;
            *teste = 1;
            return;
        }else{
            no = *raiz;
            return;
        }
    }
    no_insercao(&((*raiz)->esq), no, altura_arv, altura+1, teste);
    no_insercao(&((*raiz)->dir), no, altura_arv, altura+1, teste);

}

int inserir_balanceada(ArvBin *raiz, int num){
    int altura_arv = altura(raiz);
    int teste = 0;
    struct no *no_ins;
    no_ins = (struct no*)malloc(sizeof(struct no));
    no_insercao(raiz, no_ins, altura_arv, 0, &teste);
    struct no* novo;
    novo = (struct no*)malloc(sizeof(struct no));
    if(novo == NULL)
        return 0;
    novo->info = num;
    novo->esq = NULL;
    novo->dir = NULL;
    if(no_ins->esq == NULL)
        no_ins->esq = novo;
    else
        no_ins->dir = novo;
    return 1;
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