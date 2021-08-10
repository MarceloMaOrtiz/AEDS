// Definir
//  - Tipo de dado Árvore
//  - Implementar as suas funções
//  - Com exceção da "inserão" e "remoção" as funções são iguais a da ABB

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

#define RED 1
#define BLACK 0

struct no{
    int info;
    int cor;
    struct no *esq;
    struct no *dir;
};

ArvLLRB* cria_ArvLLRB(){
    ArvLLRB* raiz = (ArvLLRB*)malloc(sizeof(ArvLLRB));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int cor(struct no *h){
    if(h == NULL)
        return BLACK;
    else
        return h->cor;
}

// Função administrativa, responsável por alterar a cor do pai e seus filhos
void troca_cor(struct no *h){
    h->cor = !h->cor;
    if(h->esq != NULL)
        h->esq->cor = !h->esq->cor;
    if(h->dir != NULL)
        h->dir->cor = !h->dir->cor;
}

struct no* rotaciona_esquerda(struct no* a){
    struct no* b = a->dir;
    a->dir = b->esq;
    b->esq = a;
    b->cor = a->cor;
    a->cor = RED;
    return b;
}

struct no* rotaciona_direita(struct no* a){
    struct no* b = a->esq;
    a->esq = b->dir;
    b->dir = a;
    b->cor = a->cor;
    a->cor = RED;
    return b;
}

struct no* move_dois_esq_red(struct no* h){
    troca_cor(h);
    if(cor(h->dir->esq) == RED){
        h->dir = rotaciona_direita(h->dir);
        h = rotaciona_esquerda(h);
        troca_cor(h);
    }
    return h;
}

struct no* move_dois_dir_red(struct no* h){
    troca_cor(h);
    if(cor(h->esq->esq) == RED){
        h = rotaciona_direita(h);
        troca_cor(h);
    }
    return h;
}

struct no* balancear(struct no* h){
    // Nó Vermelho é sempre filho à esqueda
    if(cor(h->dir) == RED)
        h = rotaciona_esquerda(h);
    if(h->esq != NULL && cor(h->dir) == RED && cor(h->esq->esq) == RED)
        h = rotaciona_direita(h);
    if(cor(h->esq) == RED && cor(h->dir) == RED)
        troca_cor(h);
}

struct no* insere_no(struct no *h, int valor, int *resp){
    if(h == NULL){
        struct no *novo;
        novo = (struct no*)malloc(sizeof(struct no));
        if(novo == NULL){
            *resp = 0;
            return NULL;
        }
        novo->info = valor;
        novo->cor = RED;
        novo->dir = NULL;
        novo->esq = NULL;
        *resp = 1;
        return novo;
    }
    if(valor == h->info)
        *resp = 0;
    else{
        if(valor < h->info)
            h->esq = insere_no(h->esq, valor, resp);
        else
            h->dir = insere_no(h->dir, valor, resp);
    }   
    if(cor(h->dir) == RED && cor(h->esq) == BLACK)
        h = rotaciona_esquerda(h);
    if(cor(h->esq) == RED && cor(h->esq->esq) == RED)
        h = rotaciona_direita(h);
    if(cor(h->esq) == RED && cor(h->dir) == RED)
        troca_cor(h);
    return h;
}

int insere_ArvLLRB(ArvLLRB *raiz, int valor){
    int resp;
    *raiz = insere_no(*raiz, valor, &resp);
    if((*raiz) != NULL)
        (*raiz)->cor = BLACK;
    return resp;
}

int consulta_ArvLLRB(ArvLLRB *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct no* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info)
            return 1;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

struct no* procura_menor(struct no *atual){
    struct no *no1 = atual;
    struct no *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1; 
}

struct no* remove_menor(struct no *atual){
    if(atual->esq == NULL){
        free(atual);
        return NULL;
    }
    if(cor(atual->esq) == BLACK && cor(atual->esq->esq) == BLACK)
        atual = move_dois_esq_red(atual);
    atual->esq = remove_menor(atual->esq);
    return balancear(atual);
}

struct no* remove_no(struct no *h, int valor){
    if(valor < h->info){
        if(cor(h->esq) == BLACK && cor(h->esq->esq) == BLACK)
            h = move_dois_esq_red(h);
        h->esq = remove_no(h->esq, valor);
    }else{
        if(cor(h->esq) == RED)
            h = rotaciona_direita(h);
        if(valor == h->info && (h->dir == NULL)){
            free(h);
            return NULL;
        }
    }
    if(cor(h->dir) == BLACK && cor(h->dir->esq) == BLACK)
        h = move_dois_dir_red(h);
    if(valor == h->info){
        struct no *x = procura_menor(h->dir);
        h->info = x->info;
        h->dir = remove_menor(h->dir);
    }else
        h->dir = remove_no(h->dir, valor);
    return balancear(h);
}

int remove_ArvLLRB(ArvLLRB *raiz, int valor){
    if(consulta_ArvLLRB(raiz, valor)){
        struct no* h = *raiz;
        *raiz = remove_no(h, valor);
        if(*raiz != NULL)
            (*raiz)->cor = BLACK;
        return 1;
    }else
        return 0;
}

// Função responsável por percorrer a árvore liberando os nós
void libera_no(struct no* no){
    if(no == NULL)
        return;
    libera_no(no->esq);
    libera_no(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvLLRB(ArvLLRB* raiz){
    if(raiz == NULL)
        return;
    libera_no(*raiz);
    free(raiz);
}

