// Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório dos números de 1 a
// N.

#include "stdlib.h"
#include "stdio.h"

int somatorio(int n){
    if (n == 1)
        return n;
    else {
        return somatorio(n-1) + n; 
    }
}

int main() {
    int numero = 5;
    int resultado;

    printf("\t## Somatorio ##\n");
    printf("n: %d\n", numero);

    resultado = somatorio(numero);

    printf("resultado: %d\n\n", resultado);

    return 0;
}