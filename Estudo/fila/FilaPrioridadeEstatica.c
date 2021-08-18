#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "FilaPrioridadeEstatica.h"

struct paciente{
    char nome[30];
    int prio;
};

// Definição tipo de Fila de Prioridade
struct fila_prioridade{
    int qtd;
    struct paciente dados[MAX];
};

FilaPrio* cria_fila(){
    FilaPrio* fp;
    fp = (FilaPrio*)malloc(sizeof(struct fila_prioridade));
    if(fp != NULL)
        fp->qtd = 0;
    return fp;
}

int esta_cheia(FilaPrio* fp){
    if(fp == NULL)
        return -1;
    return (fp->qtd == MAX);
}

int insere_fila_array(FilaPrio* fp, char* nome, int prio){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)
        return 0;
    int i = fp->qtd-1;
    while(i >= 0 && fp->dados[i].prio >= prio){
        fp->dados[i+1] = fp->dados[i];
        i--;
    }
    strcpy(fp->dados[i+1].nome, nome);
    fp->dados[i+1].prio = prio;
    fp->qtd++;
    return 1;
}

int consulta_fila_array(FilaPrio* fp, char* nome){
    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome, fp->dados[fp->qtd-1].nome);
    return 1;
}

int remove_fila_array(FilaPrio* fp){
    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;
    fp->qtd--;
    return 1;
}

void promover_elemento(FilaPrio* fp, int filho){
    int pai;
    struct paciente temp;
    pai = (filho-1)/2;
    while((filho > 0) && (fp->dados[pai].prio <= fp->dados[filho].prio)){
        temp = fp->dados[filho];
        fp->dados[filho] = fp->dados[pai];
        fp->dados[pai] = temp;

        filho = pai;
        pai = (pai-1)/2;
    }
}

int insere_fila_heap(FilaPrio* fp, char* nome, int prio){
    if(fp == NULL)
        return 0;
    if(fp->qtd == MAX)
        return 0;
    strcpy(fp->dados[fp->qtd].nome, nome);
    fp->dados[fp->qtd].prio = prio;
    promover_elemento(fp, fp->qtd);
    fp->qtd++;
    return 1;
}

int consulta_fila_heap(FilaPrio* fp, char* nome){
    if(fp == NULL || fp->qtd == 0)
        return 0;
    strcpy(nome, fp->dados[0].nome);
    return 1;
}

void rebaixar_elemento(FilaPrio* fp, int pai){
    struct paciente temp;
    int filho = 2*pai + 1;
    while(filho < fp->qtd){
        if(filho < fp->qtd-1)
            if(fp->dados[filho].prio < fp->dados[filho+1].prio)
                filho++;
        if(fp->dados[pai].prio >= fp->dados[filho].prio)
            break;
        temp = fp->dados[pai];
        fp->dados[pai] = fp->dados[filho];
        fp->dados[filho] = temp;
        pai = filho;
        filho = 2*pai + 1;
    }
}

int remove_fila_heap(FilaPrio* fp){
    if(fp == NULL)
        return 0;
    if(fp->qtd == 0)
        return 0;
    fp->qtd--;
    fp->dados[0] = fp->dados[fp->qtd];
    rebaixar_elemento(fp, 0);
    return 1;
}


void libera_fila(FilaPrio* fp){
    free(fp);
}