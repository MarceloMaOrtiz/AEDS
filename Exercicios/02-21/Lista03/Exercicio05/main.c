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