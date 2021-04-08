#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvoreFuncionario.h"

struct Info_Est{
    int CPF;
    char Nome[50];
    char Profissao[30];
};

struct No_Est{
    Info *info;
    struct No_Est *esq;
    struct No_Est *dir;
};

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
                return -1;
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

int adicionaFuncionario(No* raiz_nome, No* raiz_cpf, char nome[], int cpf, char profissao[]){

    Info* info = infoCria(nome, cpf, profissao); // Cria Funcionário

    // Insere Funcionário na arvore ordenada por nome
    // verifica utilizado para controlar o resultado da inserção
    int verifica;
    
    verifica = insereArvoreNome(raiz_nome, info);

    if(verifica == 1)
        // Insere Funcionário na arvore ordenada por CPF
        // verific utilizado para controlar o resultado da inserção
        verifica = insereArvoreCPF(raiz_cpf, info);

    return verifica;
}