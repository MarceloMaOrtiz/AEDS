// Escreva um procedimento que receba um vetor de números reais ordenado e um número extra e insira esse
// número na sua posição correta no vetor ordenado, deslocando os outros números se necessário. Faça um
// pequeno programa para testar seu procedimento.

#include "stdio.h"
#include "stdlib.h"

void imprimir(float *v, int tam){
    printf("\n[");
    for(int i = 0; i < tam; i++)
        printf("%.2f, ", v[i]);
    printf("]\n");
}

void InserirOrdenado(float *v, int tam, float n){
    
    int i = 0;
    while(v[i] < n && i < tam-1)
        i++;
    float aux = v[i], aux2;
    for(int j = i+1; j < tam; j++){
        aux2 = v[j];
        v[j] = aux;
        aux = aux2;
    }
    v[i] = n;
}

int main(){
    float *vet = (float*)malloc(5*sizeof(float));
    vet[0] = 1;
    vet[1] = 2;
    vet[2] = 3;
    vet[3] = 4;
    imprimir(vet, 4);
    InserirOrdenado(vet, 5, 2.5);
    imprimir(vet, 5);
    return 0;
}