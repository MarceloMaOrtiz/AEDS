#include "stdlib.h"
#include "stdio.h"

int fibonacci(int n){
    if (n == 0)
        return 0;
    else if (n == 1 || n == 2)
        return 1;
    else {
        return fibonacci(n-2) + fibonacci(n-1);
    }
}

int main() {
    int numero, fib;
    printf("## Fibonacci ##");
    printf("\n\tInsira o valor para n: ");
    scanf("%d", &numero);

    fib = fibonacci(numero);

    // printf("\n\n\tn-esimo elemento da série de Fibonacci\n\t");
    printf("resultado: %d\n\n", fib);

    return 0;
}