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
void liberaNO(struct No_Est* no, int limpaInfo){
    if(no == NULL)
        return;
    liberaNO(no->esq, limpaInfo); // Chama recursivamente o nó da esquerda
    liberaNO(no->dir, limpaInfo); // Chama recursivamente o nó da direita
    if(limpaInfo == 1)
        free(no->info); // Libera as informações do funcionário
    free(no); // Libera o Nó
    no = NULL;
}

// Libera toda a memória alocada da árvore
void liberaArvore(No* raiz, int limpaInfo){
    if(raiz == NULL)
        return;
    liberaNO(*raiz, limpaInfo); // Enviando o nó raiz para a função
    free(raiz); // Libera a raiz após liberar todos os nós
}

// Cria funcionário
Info* infoCria(char nome[], int cpf, char profissao[]){

    Info* info = (Info*)malloc(sizeof(Info)); // Aloca memória para o novo Funcionário
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
        // verifica utilizado para controlar o resultado da inserção
        verifica = 0;
        verifica = insereArvoreCPF(raiz_cpf, info);
        if(verifica != 1)
            // Caso haja falha na inserção da Arvore CPF é necessário corrigir a árvore Nome
            removeNoArvoreNome(raiz_nome, info->Nome, 1);
    }
    else
        free(info); // Libera a memória alocada

    return verifica;
}

// Função responsável por tratar os 3 tipos de remoção
struct No_Est* removeNoAtual(struct No_Est* atual, int limpaInfo){
    struct No_Est *no1, *no2;
    // Casos com 0 ou 1 nó filhos
    if(atual->esq == NULL){
        no2 = atual->dir;
        if(limpaInfo == 1)
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
    if(limpaInfo == 1)
        free(atual->info);
    free(atual); 
    return no2; // Retorna o novo nó que será linkado ao nó anterior ao removido
}

// Função Responsável por buscar o nó a ser removido baseado no nome
int removeNoArvoreNome(No* raiz, char nome[], int limpaInfo){
    if(raiz == NULL)
        return 0;
    struct No_Est* ant = NULL; // Para corrigir o apontamento dos nós
    struct No_Est* atual = *raiz; // Nó que será removido
    while(atual != NULL){ // Percorre a árvore até o fim ou encontrar o nó que possue o mesmo nome
        if(strcmp(nome, atual->info->Nome) == 0){ // Checa se o nome da busca é igual o nome presente no nó
            if(atual == *raiz) // Caso o nó seja raiz, motivo pelo qual foi utilizado * no typedef
                // Envia o nó para ser removido e recebe como retorno o nó correto
                *raiz = removeNoAtual(atual, limpaInfo);
            else{
        // Verifica se o nó atual é da esquerda ou da direita em relação ao anterior para manter o link da árvore
                if(ant->esq == atual)
                    // Envia o nó para ser removido e recebe como retorno o novo apontamento
                    ant->esq = removeNoAtual(atual, limpaInfo);
                else
                    ant->dir = removeNoAtual(atual, limpaInfo);
            }
            return 1;
        }
        ant = atual; // Atualiza o nó anterior, já que o nó atual é diferente do da busca
        // Retorna um valor < 0 caso a primeira letra diferente entre a 1ª palavra e a 2ª for menor
        if(strcmp(nome, atual->info->Nome) < 0)
            atual = atual->esq; // Vai para esquerda, atualizando o nó que será removido
        else
            atual = atual->dir;
    }
    return 0;
}

// Função Responsável por buscar o nó a ser removido baseado no cpf
// Segue a mesma lógica do removeNoArvoreNome, a diferença é que a verificação é entre inteiros
int removeNoArvoreCPF(No* raiz, int cpf, int limpaInfo){
    if(raiz == NULL)
        return 0;
    struct No_Est* ant = NULL;
    struct No_Est* atual = *raiz;
    int cpf_atual;
    while(atual != NULL){
        cpf_atual = atual->info->CPF;
        if(cpf == cpf_atual){
            if(atual == *raiz)
                *raiz = removeNoAtual(atual, limpaInfo);
            else{
                if(ant->esq == atual)
                    ant->esq = removeNoAtual(atual, limpaInfo);
                else
                    ant->dir = removeNoAtual(atual, limpaInfo);
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
int limpaArvore(No* raiz, int limpaInfo){
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    if(*raiz != NULL){
        limpaArvore(&((*raiz)->esq), limpaInfo);
        limpaArvore(&((*raiz)->dir), limpaInfo);
        if(limpaInfo == 1) // Só libera a Info quando for liberar a última árvore
            free((*raiz)->info); // Libera as infos
        free(*raiz); // Libera o conteúdo da raiz, no caso o nó de fato, mas mantém a raiz existindo
    }
    return 1;
}

// Remove todos os funcionários
int removerFuncionarios(No* raiz_nome, No* raiz_cpf){
    int verifica = 0;
    verifica = limpaArvore(raiz_nome, 0);
    *raiz_nome = NULL; // Seta o apontamento da raiz para NULL
    if(verifica == 1){
        verifica = limpaArvore(raiz_cpf, 1);
        *raiz_cpf = NULL;
    }
    return verifica;
}

void inverteArvore(No* raiz){
    if(raiz == NULL)
        return;
    if(*raiz == NULL)
        return;
    struct No_Est *no_aux;
    no_aux = (*raiz)->esq;
    (*raiz)->esq = (*raiz)->dir;
    (*raiz)->dir = no_aux;
    inverteArvore(&((*raiz)->esq));
    inverteArvore(&((*raiz)->dir));
}