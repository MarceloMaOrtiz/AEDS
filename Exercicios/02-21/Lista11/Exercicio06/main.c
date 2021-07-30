// Escreva uma função que conta o número de nós folha de uma árvore binária.

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz;
    raiz = criar();

    int folhas;

    inserir(raiz, 6);
    inserir(raiz, 4);
    inserir(raiz, 2);
    inserir(raiz, 3);
    inserir(raiz, 5);
    inserir(raiz, 7);
    inserir(raiz, 9);
    inserir(raiz, 8);
    inserir(raiz, 1);

    folhas = nos_folhas(raiz);

    printf("\n### Arvore Binaria ###\n");
    printf(" Nos Folhas: %d\n", folhas);
    liberar(raiz);
    return 0;
}