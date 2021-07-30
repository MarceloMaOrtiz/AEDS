#include "stdio.h"
#include "stdlib.h"
#include "Produtos.h"
#include "Arvore.h"

struct no{
    Produto prod;
    struct no *esq;
    struct no *dir;
};
typedef struct no No;

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

int inserir(ArvBin *raiz, int cod, float preco){
    if(raiz == NULL)
        return 0;
    struct no* novo;
    novo = (struct no*)malloc(sizeof(struct no));
    if(novo == NULL)
        return 0;
    novo->prod.cod = cod;
    novo->prod.preco = preco;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct no* atual = *raiz;
        struct no* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(cod == atual->prod.cod){
                free(novo);
                return 0; // Elemento já existe
            }
            if(cod > atual->prod.cod)
                atual = atual->dir;
            else
                atual = atual->esq; 
        }
        if(cod > ant->prod.cod)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

void desenhar_2d(ArvBin *raiz, int espaco){
    if(*raiz == NULL)
        return;
    espaco += COUNT;

    desenhar_2d(&((*raiz)->dir), espaco);

    printf("\n");
    for(int i = COUNT; i < espaco; i++)
        printf(" ");
    printf("%d\n", (*raiz)->prod.cod);

    desenhar_2d(&((*raiz)->esq), espaco);
}

void desenhar(ArvBin *raiz){
    desenhar_2d(raiz, 0);
}

void pre_ordem(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d -", (*raiz)->prod.cod);
        pre_ordem(&((*raiz)->esq));
        pre_ordem(&((*raiz)->dir));
    }
}

void pos_ordem(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        pos_ordem(&((*raiz)->esq));
        pos_ordem(&((*raiz)->dir));
        printf("%d - ", (*raiz)->prod.cod);
    }
}

void central(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        central(&((*raiz)->esq));
        printf("%d -", (*raiz)->prod.cod);
        central(&((*raiz)->dir));
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