// Mostre o passo a passo da ordenação dos vetores abaixo utilizando as seguintes ordenações:
// a) BubbleSort
// b) InsertionSort
// c) SelectionSort
// Vetores:
// 1) 15 3 4 19 26 7 9 11
// 2) 20 19 17 15 14 12 11 9 7 4 2 1

#include "stdio.h"
#include "stdlib.h"

void imprimir(int *v, int tam){
    printf("[");
    for(int i = 0; i < tam; i++)
        printf("%d, ", v[i]);
    printf("]\n");
}

void bubble_sort(int *v, int tam){
    int i, continua, aux, fim = tam, cont = 0;
    printf("\nPassos:\n");
    do{
        printf("%d: ", cont++);
        imprimir(v, tam);
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = 1;
            }
        }
    }while(continua != 0);
    printf("%d: ", cont);
    imprimir(v, tam);
}

void insertion_sort(int *v, int tam){
    int i, j, aux, cont = 0;
    printf("\nPassos:\n");
    for(i = 1; i < tam; i++){
        printf("%d: ", cont++);
        imprimir(v, tam);
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j-1]); j--)
            v[j] = v[j-1];
        v[j] = aux;
    }
    printf("%d: ", cont);
    imprimir(v, tam);
}

void selection_sort(int *v, int tam){
    int i, j, menor, troca, cont = 0;
    printf("\nPassos:\n");
    for(i = 0; i < tam-1; i++){
        printf("%d: ", cont++);
        imprimir(v, tam);
        menor = i;
        for(j = i+1; j < tam; j++){
            if(v[j] < v[menor])
                menor = j;
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
    printf("%d: ", cont);
    imprimir(v, tam);
}

int main(){
    printf("\n### ORDENAÇÃO ###\n");

    int vetor_bubble_1[8] = {15, 3, 4, 19, 26, 7, 9, 11};
    int vetor_bubble_2[12] = {20, 19, 17, 15, 14, 12, 11, 9, 7, 4, 2, 1};
    printf("\n a) BubbleSort\n");
    printf("\n\t 1- ");
    imprimir(vetor_bubble_1, 8);
    bubble_sort(vetor_bubble_1, 8);
    printf("\n\t 2- ");
    imprimir(vetor_bubble_2, 12);
    bubble_sort(vetor_bubble_2, 12);

    int vetor_insertion_1[8] = {15, 3, 4, 19, 26, 7, 9, 11};
    int vetor_insertion_2[12] = {20, 19, 17, 15, 14, 12, 11, 9, 7, 4, 2, 1};
    printf("\n b) InsertionSort\n");
    printf("\n\t 1- ");
    imprimir(vetor_insertion_1, 8);
    insertion_sort(vetor_insertion_1, 8);
    printf("\n\t 2- ");
    imprimir(vetor_insertion_2, 12);
    insertion_sort(vetor_insertion_2, 12);

    int vetor_selection_1[8] = {15, 3, 4, 19, 26, 7, 9, 11};
    int vetor_selection_2[12] = {20, 19, 17, 15, 14, 12, 11, 9, 7, 4, 2, 1};
    printf("\n c) SelectionSort\n");
    printf("\n\t 1- ");
    imprimir(vetor_selection_1, 8);
    selection_sort(vetor_selection_1, 8);
    printf("\n\t 2- ");
    imprimir(vetor_selection_2, 12);
    selection_sort(vetor_selection_2, 12);

    return 0;
}