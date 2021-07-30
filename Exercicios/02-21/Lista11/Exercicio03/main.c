// Escreva um algoritmo para determina se uma árvore binária é:
// a) Completa
// b) Balanceada
// c) Perfeitamente Balanceada

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz;
    raiz = criar();

    int altura;
    int e_balanceada, p_balanceada;

    inserir(raiz, 6);
    inserir(raiz, 4);
    inserir(raiz, 2);
    inserir(raiz, 3);
    inserir(raiz, 5);
    inserir(raiz, 7);
    inserir(raiz, 9);
    inserir(raiz, 8);
    inserir(raiz, 1);

    altura = 0;
    e_balanceada = balanceada(raiz, &altura);
    altura = 0;
    p_balanceada = perfeitamente_balanceada(raiz, &altura);

    printf("\n### Arvore Binaria ###\n");
    if(e_balanceada == 1)
        printf("  b) Balanceada\n");
    else
        printf("  b) Não Balanceada\n");

    if(p_balanceada == 1)
        printf("  c) Perfeitamente Balanceada\n");
    else
        printf("  b) Não Perfeitamente Balanceada\n");

    liberar(raiz);
    return 0;
}