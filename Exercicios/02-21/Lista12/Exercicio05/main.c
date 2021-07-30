// Escreva uma função que recebe como parâmetro uma árvore binária e que retorna a quantidade (inteiro) de
// nós folha dessa árvore. Faça um pequeno programa em C para testar sua função.

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz;
    raiz = criar();

    int folhas;

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

    folhas = nos_folhas(raiz);

    printf("\n### Arvore Binaria de Busca ###\n");
    printf("\n Nos Folhas: %d\n\n", folhas);

    liberar(raiz);
    return 0;
}