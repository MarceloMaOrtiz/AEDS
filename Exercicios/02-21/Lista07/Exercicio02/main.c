// Escreva um procedimento que receba um vetor com registros que contém uma chave e imprima ORDENADO
// se o vetor estiver em ordem crescente. Caso contrário, imprima NAO ORDENADO.

#include "stdio.h"
#include "stdlib.h"
#include "Registro.h"

void verificar_ordenacao(struct registro *regs, int tam){
    int i;
    for(i = 0; i < tam-1; i++){
        if(regs[i].key > regs[i+1].key){
            printf("\nNAO ORDENADO\n");
            return;
        }
    }
    printf("\nORDENADO\n");
}

int main(){
    struct registro regs[4] = {{1}, {5}, {3}, {4}};
    verificar_ordenacao(regs, 4);

    return 0;
}