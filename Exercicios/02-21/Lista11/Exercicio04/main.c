// Considere uma árvore binária perfeitamente balanceada, onde cada nó é composto por um inteiro e ponteiros
// para as sub-árvores direita e esquerda. Construa uma função que receba um valor inteiro e o nó raiz da árvore
// binária perfeitamente balanceada e insira um novo nó (representado pelo valor inteiro recebido) na árvore de
// forma que ela continue sendo uma árvore binária perfeitamente balanceada.

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz;
    raiz = criar();

    inserir(raiz, 6);
    inserir(raiz, 4);
    inserir(raiz, 2);
    inserir(raiz, 3);
    inserir(raiz, 5);
    inserir(raiz, 7);
    inserir(raiz, 9);
    inserir(raiz, 8);
    inserir(raiz, 1);

    inserir_balanceada(raiz, 10);

    liberar(raiz);
    return 0;
}