// Implemente, na linguagem C, uma versão iterativa (não-recursiva) dos caminhamentos pré-ordem, pós-ordem
// e central. Dica: utilize a TAD Pilha para simular a pilha de recursão.

#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

void pre_ordem(int arv[], int tam){
    Pilha *pi = criar();
    int i = 0, dir, esq;
    printf("\n[ ");
    inserir(pi, i);
    do{
        while(i < tam){
            printf("%d, ", arv[i]);
            esq = i*2 + 1;
            dir = i*2 + 2;
            
            if(dir < tam)
                inserir(pi, dir);
            i = esq;
        }
        consultar(pi, &i);
        remover(pi);
    }while(!vazia(pi));
    printf("]\n\n");
    liberar(pi);
}

void pos_ordem(int arv[], int tam){
    Pilha *pi = criar();
    int atual = 0, ant = -1;
    printf("\n[ ");
    while(atual != -1 || !vazia(pi)){
        if(atual != -1){
            inserir(pi, atual);
            atual = atual * 2 + 1;
            if(atual >= tam)
                atual = -1;
        }
        else{
            consultar(pi, &atual);
            int dir = atual * 2 + 2;
            if(dir >= tam)
                dir = -1;
            if(dir == -1 || dir == ant){
                printf("%d, ", arv[atual]);
                remover(pi);
                ant = atual;
                atual = -1;
            }else
                atual = dir;
        }
    }
    printf("]\n\n");
    liberar(pi);
}

void central(int arv[], int tam){
    Pilha *pi = criar();
    int atual = 0;
    printf("\n[ ");
    while(1){
        if(atual != -1){
            inserir(pi, atual);
            atual = atual * 2 + 1;
            if(atual >= tam)
                atual = -1;
        }else{
            if(vazia(pi))
                break;
            consultar(pi, &atual);
            remover(pi);
            printf("%d, ", arv[atual]);
            atual = atual * 2 + 2;
            if(atual >= tam)
                atual = -1;
        }
    }
    printf("]\n\n");
    liberar(pi);
}

int main(){
    int arvore_vetor[9] = {3, 5, 2, 1, 8, 9, 4, 7, 6};
    printf("\n### Pre-Ordem ###\n");
    pre_ordem(arvore_vetor, 9);
    printf("\n### Pos-Ordem ###\n");
    pos_ordem(arvore_vetor, 9);
    printf("\n### Central ###\n");
    central(arvore_vetor, 9);
    return 0;
}

