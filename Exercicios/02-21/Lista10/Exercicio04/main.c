// Crie um programa que dado uma string, coloque as letras dela em ordem decrescente usando o algoritmo
// quicksort.

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void imprimir(char w[], int tam){
    printf("\n[");
    for(int i = 0; i < tam; i++)
        printf("%c, ", w[i]);
    printf("]\n");
}

int particiona(char w[], int inicio, int final){
    int esq, dir;
    char pivo, aux;
    esq = inicio;
    dir = final;
    pivo = w[inicio];
    while(esq < dir){
        while(w[esq] >= pivo)
            esq++;
        while(w[dir] < pivo)
            dir --;
        if(esq < dir){
            aux = w[esq];
            w[esq] = w[dir];
            w[dir] = aux;
        }
    }
    w[inicio] = w[dir];
    w[dir] = pivo;
    return dir;
}

void quick_sort_descrescente(char w[], int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(w, inicio, fim);
        quick_sort_descrescente(w, inicio, pivo-1);
        quick_sort_descrescente(w, pivo+1, fim);
    }
}

int main() {
    char word[30];
    int len;
    printf("\n### ORDENAÇÃO DECRESCENTE ###\n");
    printf("Insira a palavra: ");
    scanf("%s", &word);
    len = strlen(word);
    imprimir(word, len);
    quick_sort_descrescente(word, 0, len-1);
    imprimir(word, len);
    return 0;
}