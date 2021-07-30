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

void buscar(ArvBin *raiz, int cod){
    if(raiz == NULL)
        return;
    struct no *atual = *raiz;
    while(atual != NULL){
        if(cod == atual->prod.cod){
            printf("O Produto %d custa R$ %.2f.", atual->prod.cod, atual->prod.preco);
            return;
        }
        if(cod > atual->prod.cod)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    printf("Produto %d nao encontrado.", cod);
    return;
}

struct no* remove_atual(struct no* atual){
    struct no *no1, *no2;
    // Casos com 0 ou 1 nó
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    // Procura filho mais a direita na sub-árvore da esquerda
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // Copia o filho mais a direita a sub-árvore da esquerda
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remover(ArvBin *raiz, int cod){
    if(raiz == NULL)
        return 0;
    struct no* ant = NULL;
    struct no* atual = *raiz;
    while(atual != NULL){
        if(cod == atual->prod.cod){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(cod > atual->prod.cod)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
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