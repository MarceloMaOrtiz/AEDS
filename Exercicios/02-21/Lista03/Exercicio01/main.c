// Escreva uma função recursiva que procure um valor em um vetor e retorne o índice do elemento, caso ele
// exista no vetor, ou -1 caso, caso contrário.

#include "stdlib.h"
#include "stdio.h"

int indice_encontrado(int valor, int vetor[], int tamanho) {
    if (tamanho < 1)
        return -1;
    else {
        if (vetor[tamanho-1] == valor)
            return tamanho-1;
        else
            indice_encontrado(valor, vetor, tamanho-1);
    }
}

int main() {
    int vetor[20];

    int resultado;

    for (int i = 0; i < 20; i++){
        vetor[i] = i*2;
    }

    resultado = indice_encontrado(14, vetor, 20);
    // resultado2 = indice_encontrado(6, vetor, sizeof(vetor));

    printf("\n\tResultado: %d\n\n", resultado);
    return 0;
}