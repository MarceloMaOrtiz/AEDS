// Implemente uma função recursiva que, dados dois números inteiros x e n, calcula o valor de x n .

#include "stdlib.h"
#include "stdio.h"

int expoente(int b, int e){
    if (e == 1)
        return b;
    else {
        return expoente(b, e-1)*b; 
    }
}

int main() {
    int base = 2;
    int exp = 4;
    int resultado;

    printf("## Exponenciação ##\n");
    printf("base: %d\texpoente: %d\n\n", base, exp);

    resultado = expoente(base, exp);

    printf("resultado: %d\n\n", resultado);

    return 0;
}