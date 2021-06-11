#include <stdlib.h>
#include <stdio.h>
#include "TConjunto.h"

struct tconjunto{
    int tamanho;
    int elementos[20];
};

TConjunto* cria_conjunto(int tam){
    TConjunto* tc = (TConjunto*)malloc(sizeof(TConjunto));
    if (tc != NULL){
        tc->tamanho = tam;
    }
    return tc;
}

void ler_dados(TConjunto* tc) {
    printf("\n\n\tInsira os valores!!\n\n");
    for (int i = 0; i < tc->tamanho; i++){
        printf("\tPosicao %d: ", i);
        scanf("%d", &(tc->elementos[i]));
    }
}

void imprimir_conjunto(TConjunto* tc) {
    printf("\n\n\t[ ");
    for (int i = 0; i < tc->tamanho; i++) {
        printf("%d, ", tc->elementos[i]);
    }
    printf("]\n\n");
}

void uniao_conjuntos(TConjunto *tc1, TConjunto* tc2){
    int tamanho_max = tc1->tamanho + tc2->tamanho;
    int *uniao;
    uniao = (int*)malloc(tamanho_max*sizeof(int));

    int perc_uniao = 0;

    for (int i = 0; i < tc1->tamanho; i++){
        int pertence = 0;
        for (int j = 0; j < perc_uniao; j++){
            if (tc1->elementos[i] == uniao[j]){
                pertence = 1;
                j = perc_uniao;
            }
        }
        if (!pertence){
            uniao[perc_uniao] = tc1->elementos[i];
            perc_uniao++;
        }
    }
    for (int i = 0; i < tc2->tamanho; i++){
        int pertence = 0;
        for (int j = 0; j < perc_uniao; j++){
            if (tc2->elementos[i] == uniao[j]){
                pertence = 1;
                j = perc_uniao;
            }
        }
        if (!pertence){
            uniao[perc_uniao] = tc2->elementos[i];
            perc_uniao++;
        }
    }

    printf("\n\n\t[ ");
    for (int i = 0; i < perc_uniao; i++) {
        printf("%d, ", uniao[i]);
    }
    printf("]\n\n");

    free(uniao);
}

void intersecao_conjuntos(TConjunto* tc1, TConjunto* tc2){
    int tamanho_max = tc1->tamanho + tc2->tamanho;

    if (tc1->tamanho < tc2->tamanho)
        tamanho_max = tc1->tamanho;
    else
        tamanho_max = tc2->tamanho;

    int *intersecao;
    intersecao = (int*)malloc(tamanho_max*sizeof(int));

    int perc_intersecao = 0;

    for (int i = 0; i < tc1->tamanho; i++){
        int pertence = 0;
        for (int j = 0; j < tc2->tamanho; j++){
            if (tc1->elementos[i] == tc2->elementos[j]) {
                for (int z = 0; z < perc_intersecao; z++) {
                    if (tc1->elementos[i] == intersecao[z])
                        pertence = 1;
                        z = perc_intersecao;
                }
                if (!pertence) {
                    intersecao[perc_intersecao] = tc1->elementos[i];
                    perc_intersecao++;
                }
                j = tc2->tamanho;
            }
        }
    }
    printf("\n\n\t[ ");
    for (int i = 0; i < perc_intersecao; i++) {
        printf("%d, ", intersecao[i]);
    }
    printf("]\n\n");

    free(intersecao);
}

void iguais_conjuntos(TConjunto* tc1, TConjunto* tc2){

    int index[20];
    int perc_index = 0;

    if (tc1->tamanho != tc2->tamanho){
        printf("\n\n\tOs conjuntos não são iguais!\n\n");
        return;
    }

    for (int i = 0; i < tc1->tamanho; i++) {
        int iguais = 0;
        for (int j = 0; j < tc2->tamanho; j++) {
            int teste_index = 0;
            for (int z = 0; z < perc_index; z++){
                if (index[z] == j) {
                    z = perc_index;
                    teste_index = 1;
                }
            }
            if (!teste_index) {
                if (tc1->elementos[i] == tc2->elementos[j]){
                    iguais = 1;
                    index[perc_index] = j;
                    perc_index++;
                    j = tc2->tamanho;
                }
            }
        }
        if (!iguais) {
            printf("\n\n\tOs conjuntos não são iguais!\n\n");
            return;
        }
    }
    printf("\n\n\tOs conjuntos são iguais!\n\n");
}

void libera_conjunto(TConjunto* tc){
    free(tc);
}