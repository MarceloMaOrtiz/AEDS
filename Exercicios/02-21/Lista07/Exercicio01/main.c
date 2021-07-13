// Reescreva os algoritmos BubbleSort, SelectionSort e InsertionSort vistos para que as chaves se ordenem de
// forma decrescente.

#include "stdio.h"
#include "stdlib.h"

void bubble_sort(int *v, int tam){
    int i, continua, aux, fim = tam;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){
            if(v[i] < v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = 1;
            }
        }
    }while(continua != 0);
}

void insertion_sort(int *v, int tam){
    int i, j, aux;
    for(i = 1; i < tam; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux > v[j-1]); j--)
            v[j] = v[j-1];
        v[j] = aux;
    }
}

void selection_sort(int *v, int tam){
    int i, j, menor, troca;
    for(i = 0; i < tam-1; i++){
        menor = i;
        for(j = i+1; j < tam; j++){
            if(v[j] > v[menor])
                menor = j;
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

void imprimir(int *v, int tam){
    printf("\n[");
    for(int i = 0; i < tam; i++)
        printf("%d, ", v[i]);
    printf("]\n");
}


int main(){
    printf("\n### ORDENAÇÃO ###\n");

    int vetor_bubble[10] = {4, 5, 3, 2, 1, 9, 7, 0, 8, 6};
    printf("\n - BubbleSort\n");
    imprimir(vetor_bubble, 10);
    bubble_sort(vetor_bubble, 10);
    imprimir(vetor_bubble, 10);

    int vetor_insertion[10] = {4, 5, 3, 2, 1, 9, 7, 0, 8, 6};
    printf("\n - InsertionSort\n");
    imprimir(vetor_insertion, 10);
    insertion_sort(vetor_insertion, 10);
    imprimir(vetor_insertion, 10);

    int vetor_selection[10] = {4, 5, 3, 2, 1, 9, 7, 0, 8, 6};
    printf("\n - SelectionSort\n");
    imprimir(vetor_selection, 10);
    selection_sort(vetor_selection, 10);
    imprimir(vetor_selection, 10);

    return 0;
}