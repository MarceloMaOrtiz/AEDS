// Definir
//  - Tipo de dado Árvore
//  - Implementar as suas funções
//  - Com exceção da "inserão" e "remoção" as funções são iguais a da ABB

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

struct no{
    int info;
    int alt; // Altura da sub-árvore
    struct no *esq;
    struct no *dir;
};

ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*)malloc(sizeof(ArvAVL));
    if(raiz != NULL){
        *raiz = NULL;
    }
    return raiz;
}

int alt_no(struct no* no){
    if(no == NULL)
        return -1;
    else
        return no->alt;
}

int fatorBalanceamento_no(struct no* no){
    return labs(alt_no(no->esq) - alt_no(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

void rotacaoLL(ArvAVL* raiz){
    struct no *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq),
                            alt_no((*raiz)->dir))
                            + 1;
    no->alt = maior(alt_no(no->esq),
                        (*raiz)->alt)
                        + 1;
    *raiz = no;
}

void rotacaoRR(ArvAVL* raiz){
    struct no *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq),
                            alt_no((*raiz)->dir))
                            + 1;
    no->alt = maior(alt_no(no->esq),
                        (*raiz)->alt)
                        + 1;
    *raiz = no;
}

void rotacaoLR(ArvAVL* raiz){
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

void rotacaoRL(ArvAVL* raiz){
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

int insere_ArvAVL(ArvAVL* raiz, int valor){
    int res;
    if(*raiz == NULL){
        struct no *novo;
        novo = (struct no*)malloc(sizeof(struct no));
        if(novo == NULL)
            return 0;
        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct no *atual = *raiz;
    if(valor < atual->info){
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){
            if(fatorBalanceamento_no(atual) >= 2){
                if(valor < (*raiz)->esq->info)
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
        }
    }else{
        if(valor > atual->info){
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){
                if(fatorBalanceamento_no(atual) >= 2){
                    if(valor > (*raiz)->dir->info)
                        rotacaoRR(raiz);
                    else
                        rotacaoRL(raiz);
                }
            }
        }else{
            printf("\nValor Duplicado.\n");
            return 0;
        }
    }
    atual->alt = maior(alt_no(atual->esq),
                            alt_no(atual->dir))
                            + 1;
    return res;
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

int remove_ArvAVL(ArvAVL* raiz, int valor){
    if(*raiz == NULL){
        printf("\nValor não existe!! \n");
        return 0;
    }
    int res;
    if(valor < (*raiz)->info){
        res = remove_ArvAVL(&(*raiz)->esq, valor);
        if(res == 1){
            if(fatorBalanceamento_no(*raiz) >= 2){
                if(alt_no((*raiz)->dir->esq) <= alt_no((*raiz)->dir->dir))
                    rotacaoRR(raiz);
                else
                    rotacaoRL(raiz);
            }
        }
    }
    if(valor > (*raiz)->info){
        res = remove_ArvAVL(&(*raiz)->dir, valor);
        if(res == 1){
            if(fatorBalanceamento_no(*raiz) >= 2){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq))
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
        }
    }
    if((*raiz)->info == valor){
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){
            struct no *velho = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(velho);
        }else{
            struct no *temp = procura_menor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_no(*raiz) >= 2){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq))
                    rotacaoLL(raiz);
                else
                    rotacaoLR(raiz);
            }
            return 1;
        }
        return res;
    }
}

int consulta_ArvAVL(ArvAVL* raiz, int valor){
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

// Função responsável por percorrer a árvore liberando os nós
void libera_no(struct no* no){
    if(no == NULL)
        return;
    libera_no(no->esq);
    libera_no(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_no(*raiz);
    free(raiz);
}