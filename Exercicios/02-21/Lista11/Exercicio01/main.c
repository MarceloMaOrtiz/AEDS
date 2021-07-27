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
    int i = 0, dir, esq, print = 0;
    printf("\n[ ");
    inserir(pi, i);
    do{
        while(i < tam){
            esq = i*2 + 1;
            dir = i*2 + 2;
            if(esq < tam)
                inserir(pi, esq);
            if(dir < tam)
                inserir(pi, dir);
            i = esq;
            
        }
        consultar(pi, &i);
        printf("%d, ", arv[i]);
        remover(pi);
    }while(!vazia(pi));
    printf("%d, ", arv[0]);
    printf("]\n\n");
    liberar(pi);
}

int main(){
    int arvore_vetor[9] = {3, 5, 2, 1, 8, 9, 4, 7, 6};
    printf("\n### Pre-Ordem ###\n");
    pre_ordem(arvore_vetor, 9);
    printf("\n### Pos-Ordem ###\n");
    pos_ordem(arvore_vetor, 9);
    return 0;
}

