#include "stdlib.h"
#include "stdio.h"

float soma_elemento_vetor(float vetor[], int tamanho){
    if (tamanho == 1)
        return vetor[tamanho-1];
    else {
        return vetor[tamanho-1] + soma_elemento_vetor(vetor, tamanho-1); 
    }
}

int main() {
    float vetor[] = { 2.0, 3.0, 4.0, 5.0, 6.0, 7.5, 8.5 };
    float resultado;

    resultado = soma_elemento_vetor(vetor, 7);

    printf("\n\tresultado: %.2f\n\n", resultado);

    return 0;
}
