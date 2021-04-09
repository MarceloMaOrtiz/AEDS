#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvoreFuncionario.h"

// Inicializa a árvore
No* criaArvore(){
    No* raiz = (No*)malloc(sizeof(No)); // Aloca um endereço do No para ser a raiz
    if(raiz != NULL){ // Verifica se deu problema na alocação
        *raiz = NULL;
    }
    return raiz;
}

// Função responsável por percorrer a árvore liberando os nós
void liberaNO(struct No_Est* no){
    if(no == NULL)
        return;
    liberaNO(no->esq); // Chama recursivamente o nó da esquerda
    liberaNO(no->dir); // Chama recursivamente o nó da direita
    // PONTO DE ATENÇÃO
    // if(no->info != NULL)
    //     free(no->info); // Libera as informações do funcionário
    free(no); // Libera o Nó
    no = NULL;
}

// Libera toda a memória alocada da árvore
void liberaArvore(No* raiz){
    if(raiz == NULL)
        return;
    liberaNO(*raiz);
    free(raiz);
}

// Cria funcionário
Info* infoCria(char nome[], int cpf, char profissao[]){

    Info* info = (Info*)malloc(sizeof(Info));
    if(info != NULL){
        strcpy(info->Nome, nome);
        info->CPF = cpf;
        strcpy(info->Profissao, profissao);
    }

    return info;
}

// Insere o funcionário na árvore ordenada pelo nome
int insereArvoreNome(No* raiz, Info* info){
    if(raiz == NULL)
        return 0; // Caso raiz não esteja nem alocada
    struct No_Est* novo;
    novo = (struct No_Est*)malloc(sizeof(struct No_Est));
    if(novo == NULL)
        return 0; // Caso alocação de algum problema
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL) // Caso seja o primeiro elemento da árvore, insere
        *raiz = novo;
    else{
        struct No_Est* atual = *raiz;
        struct No_Est* ant = NULL;
        while(atual != NULL){ // Percorre a árvore
            ant = atual; // Guarda o nó anterior
            if(strcmp(info->Nome, atual->info->Nome) == 0){ // Elemento já existe
                free(novo); // Libera nó alocado e retorna -1 para avisar usuário
                return -1;
            }
            if(strcmp(info->Nome, atual->info->Nome) < 0)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        if(strcmp(info->Nome, ant->info->Nome) < 0)
            ant->esq = novo;
        else
            ant->dir = novo;
    }
    return 1;
}

// Insere o funcionário na árvore ordenada pelo cpf
int insereArvoreCPF(No* raiz, Info* info){
    if(raiz == NULL)
        return 0; // Caso raiz não esteja nem alocada
    struct No_Est* novo;
    novo = (struct No_Est*)malloc(sizeof(struct No_Est));
    if(novo == NULL)
        return 0; // Caso alocação de algum problema
    novo->info = info;
    novo->esq = NULL;
    novo->dir = NULL;
    if(*raiz == NULL) // Caso seja o primeiro elemento da árvore, insere
        *raiz = novo;
    else{
        struct No_Est* atual = *raiz;
        struct No_Est* ant = NULL;

        int cpf_atual;
        int cpf = info->CPF;

        while(atual != NULL){ // Percorre a árvore
            ant = atual; // Guarda o nó anterior

            cpf_atual = atual->info->CPF;

            if(cpf == cpf_atual){ // Elemento já existe
                free(novo); // Libera nó alocado e retorna -1 para avisar usuário
                return -2;
            }

            if(cpf < cpf_atual)
                atual = atual->esq;
            else
                atual = atual->dir;
        }
        if(cpf < cpf_atual)
            ant->esq = novo;
        else
            ant->dir = novo;
    }
    return 1;
}

// Função responsável por adicionar usuário em ambas as árvores
int adicionaFuncionario(No* raiz_nome, No* raiz_cpf, char nome[], int cpf, char profissao[]){

    Info* info = infoCria(nome, cpf, profissao); // Cria Funcionário

    // Insere Funcionário na arvore ordenada por nome
    // verifica utilizado para controlar o resultado da inserção
    int verifica = 0;
    
    verifica = insereArvoreNome(raiz_nome, info);

    if(verifica == 1){
        // Insere Funcionário na arvore ordenada por CPF
        // verific utilizado para controlar o resultado da inserção
        verifica = 0;
        verifica = insereArvoreCPF(raiz_cpf, info);
        if(verifica != 1)
            // Caso haja falha na inserção da Arvore CPF é necessário corrigir a árvore Nome
            removeNoArvoreNome(raiz_nome, info->Nome);
    }

    return verifica;
}

// Função responsável por tratar os 3 tipos de remoção
struct No_Est* removeNoAtual(struct No_Est* atual){
    struct No_Est *no1, *no2;
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

// Função Responsável por buscar o nó a ser removido baseado no nome
int removeNoArvoreNome(No* raiz, char nome[]){
    if(raiz == NULL)
        return 0;
    struct No_Est* ant = NULL;
    struct No_Est* atual = *raiz;
    while(atual != NULL){
        if(strcmp(nome, atual->info->Nome) == 0){
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
        if(strcmp(nome, atual->info->Nome) < 0)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}

// Função Responsável por buscar o nó a ser removido baseado no cpf
int removeNoArvoreCPF(No* raiz, int cpf){
    if(raiz == NULL)
        return 0;
    struct No_Est* ant = NULL;
    struct No_Est* atual = *raiz;
    int cpf_atual;
    while(atual != NULL){
        cpf_atual = atual->info->CPF;
        if(cpf == cpf_atual){
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
        if(cpf < cpf_atual)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    return 0;
}

// Retorna a Info de um Nó utilizando o Nome como busca
Info buscaNoNome(No* raiz, char nome[]){
    struct No_Est* atual = *raiz;
    while(atual != NULL){
        if(strcmp(nome, atual->info->Nome) == 0)
            return *(atual->info);
        if(strcmp(nome, atual->info->Nome) < 0)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    Info retorno_vazio;
    strcpy(retorno_vazio.Nome, "Warning");
    retorno_vazio.CPF = -1;
    strcpy(retorno_vazio.Profissao, "NULL");
    return retorno_vazio;
}

// Retorna a Info de um Nó utilizando o CPF como busca
Info buscaNoCPF(No* raiz, int cpf){
    int cpf_atual;
    struct No_Est* atual = *raiz;
    while(atual != NULL){
        cpf_atual = atual->info->CPF;
        if(cpf == cpf_atual)
            return *(atual->info);
        if(cpf < cpf_atual)
            atual = atual->esq;
        else
            atual = atual->dir;
    }
    Info retorno_vazio;
    strcpy(retorno_vazio.Nome, "Warning");
    retorno_vazio.CPF = -1;
    strcpy(retorno_vazio.Profissao, "NULL");
    return retorno_vazio;
}

// Exibe todos os funcionários em Ordem Crescente
void exibirEmOrdemArvore(No* raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        exibirEmOrdemArvore(&((*raiz)->esq));
        printf("\tNome: %s\n", (*raiz)->info->Nome);
        printf("\tCPF: %d\n", (*raiz)->info->CPF);
        printf("\tProfissão: %s\n\n", (*raiz)->info->Profissao);
        exibirEmOrdemArvore(&((*raiz)->dir));
    }
}

// Limpa árvore
int limpaArvore(No* raiz){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    if(*raiz != NULL){
        limpaArvore(&((*raiz)->esq));
        limpaArvore(&((*raiz)->dir));
        free(*raiz);
    }
    return 1;
}

// Remove todos os funcionários
int removerFuncionarios(No* raiz_nome, No* raiz_cpf){
    int verifica = 0;
    verifica = limpaArvore(raiz_nome);
    *raiz_nome = NULL;
    if(verifica == 1){
        verifica = limpaArvore(raiz_cpf);
        *raiz_cpf = NULL;
    }
    return verifica;
}