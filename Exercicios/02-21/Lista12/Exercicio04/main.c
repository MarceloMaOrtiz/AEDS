// Escreva uma função que retorne o valor máximo em uma árvore binária de busca. Faça também uma função
// que retorne o valor mínimo dessa árvore binária de busca. Por último, faça um pequeno programa em C para
// testar sua função.

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz;
    raiz = criar();

    int max, min;

    inserir(raiz, 770);
    inserir(raiz, 875);
    inserir(raiz, 7);
    inserir(raiz, 59);
    inserir(raiz, 68);
    inserir(raiz, 682);
    inserir(raiz, 588);
    inserir(raiz, 67);
    inserir(raiz, 234);
    inserir(raiz, 411);
    inserir(raiz, 191);
    inserir(raiz, 512);

    max = max_no(raiz);
    min = min_no(raiz);

    printf("\n### Arvore Binaria de Busca ###\n");

    printf("\nMax: %d\n", max);
    printf("\nMax: %d\n\n", min);

    liberar(raiz);
    return 0;
}