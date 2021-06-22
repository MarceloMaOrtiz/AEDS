#include "stdlib.h"
#include "stdio.h"

void invert(int n){
    int resto = n%10;
    int novo_numero = (int)(n/10);
    if (novo_numero <= 0)
        printf("%d\n\n", resto);
    else {
        printf("%d", resto);
        invert(novo_numero);
    }
}

int main() {
    int numero = 5367;
    int inverso;

    printf("\n\n\tInverso\n\t");
    printf("n: %d\n\n\t", numero);

    invert(numero);

    return 0;
}