// Implemente um algoritmo para testar se uma árvore binária é simétrica. Uma árvore binária é simétrica de si se
// suas sub-árvores são imagens espelhadas idênticas. Por exemplo, as duas primeiras árvores abaixo são
// simétricas, mas as duas últimas não são.

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz;
    raiz = criar();

    int espelho;

    inserir(raiz, 6);
    inserir(raiz, 4);
    inserir(raiz, 2);
    inserir(raiz, 3);
    inserir(raiz, 5);
    inserir(raiz, 7);
    inserir(raiz, 9);
    inserir(raiz, 8);
    inserir(raiz, 1);

    espelho = simetrica(raiz, raiz);

    printf("\n### Arvore Binaria ###\n");
    if(espelho == 1)
        printf(" E Simetrica\n");
    else
        printf(" Nao e Simetrica\n");
    liberar(raiz);
    return 0;
}