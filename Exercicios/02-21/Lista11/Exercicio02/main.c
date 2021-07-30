// Escreva algoritmos recursivos para determinar:
// a) O número de nós em uma árvore binária.
// b) A soma dos conteúdos de todos os nós em uma árvore binária, considerando que cada nó contém um
// inteiro.
// c) A altura de uma árvore binária.

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz;
    raiz = criar();

    int total_nos, soma, altura_arv;

    inserir(raiz, 6);
    inserir(raiz, 4);
    inserir(raiz, 2);
    inserir(raiz, 3);
    inserir(raiz, 5);
    inserir(raiz, 7);
    inserir(raiz, 9);
    inserir(raiz, 8);
    inserir(raiz, 1);

    total_nos = total_no(raiz);
    soma = soma_nos(raiz);
    altura_arv = altura(raiz);

    printf("\n### Arvore Binaria ###\n");
    printf("  a) Numero de nos: %d\n", total_nos);
    printf("  b) Soma dos nos: %d\n", soma);
    printf("  c) Altura: %d\n", altura_arv);

    liberar(raiz);
    return 0;
}