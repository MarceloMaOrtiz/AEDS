#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "ArvoreEleitor.h"

struct No_Est{
    Info *info;
    struct No_Est *esq;
    struct No_Est *dir;
};

// Cria o ponteiro raiz
ArvoreEleitor* criaArvore(){
    ArvoreEleitor* raiz = (ArvoreEleitor*)malloc(sizeof(ArvoreEleitor));
    if(raiz != NULL){ // Verifica se a alocação deu certo
        *raiz = NULL;
    }
    return raiz;
}

// Verifica se Eleitor existe - Função auxiliar
int eleitorExiste(ArvoreEleitor* raiz, int titulo){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 0;
    No* atual = *raiz;
    while(atual != NULL){
        if(atual->info->titulo == titulo)
            return 1;
        if(atual->info->titulo > titulo)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}

// Cria um Eleitor - Função auxiliar
Info* criaEleitor(int titulo, char nome[]){
    Info* eleitor = (Info*)malloc(sizeof(Info));
    if(info != NULL){
        info->titulo = titulo;
        strcpy(eleitor->Nome, nome);
        info->voto = 0;
    }
}

// Insere o Eleitor na Arvore
int insereArvore(ArvoreEleitor* raiz, int titulo, char nome){

}

// Função responsável por remover o nó
No* removeNoAtual(No* atual){
    No *no1, *no2;
    // Casos com 0 ou 1 nó filhos
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual->info);
        free(atual);
        return no2;
    }
    // Procura filho mais a direita na sub-árvore da esquerda
    no1 = atual; // Utilizado para evitar uma situação específica onde o nó mais a direita possui um filho
    no2 = atual->esq; // associa a sub-árvore da esquerda
    while(no2->dir != NULL){ // Procura o nó mais a direita
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){ // Caso o no1 não seja o nó removido é necessário fazer uma correção
        no1->dir = no2->esq; // Como o nó mais a direita será removido, o nó anterior irá apontar para o nó da esquerda do no2
        no2->esq = atual->esq; // Novo nó aponta para sub-árvore da esquerda do nó removido
    }
    no2->dir = atual->dir; // Corrige o apontamento do novo posicionamento do nó em relação a sub-arvore da direita
    free(atual->info);
    free(atual); 
    return no2; // Retorna o novo nó que será linkado ao nó anterior ao removido
}

// Remove o Eleitor da Arvore
int removeEleitorArvore(ArvoreEleitor* raiz, int titulo){
    if(raiz == NULL)
        return 0;
    No* ant = NULL;
    No* atual = *raiz;
    while(atual != NULL){
        if(titulo == atual->info->titulo){
            if(atual == *raiz)
                *raiz = removeNoAtual(atual);
            else{
                if(ant->esq == atual)
                    ant->esq = removeNoAtual(atual);
                else
                    ant->dir = removeNoAtual(atual);
            }
            return 1;
        }
        ant = atual;
        if(titulo < atual->info->titulo)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}

int novaVotacao(ArvoreEleitor* raiz){

}

int votar(ArvoreEleitor* raiz, int titulo, int voto){

}

int retiraVoto(ArvoreEleitor* raiz, int titulo){

}

void resultadoParcial(ArvoreEleitor* raiz){

}

void mostrarVotantes(ArvoreEleitor* raiz){
    
}

// Função auxiliar para percorrer a árvore liberando os nós
void liberaNo(No* no){
    if(no == NULL)
        return;
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no->info);
    free(no);
}

// Destroi a árvore
void liberaArvore(ArvoreEleitor* raiz){
    if(raiz == NULL)
        return;
    liberaNo(*raiz);
    free(raiz);
}

