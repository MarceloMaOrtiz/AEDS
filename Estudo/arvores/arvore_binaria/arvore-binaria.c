#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"


int main(){

    ArvBin* raiz = cria_ArvBin();

    int x = estaVazia_ArvBin(raiz);

    if(x)
        printf("A Árvore está vazia\n");
    else
        printf("A Árvore não está vazia\n");

    x = altura_ArvBin(raiz);
    printf("A Altura da Árvore é: %d\n", x);

    x = totalNO_ArvBin(raiz);
    printf("A quantidade de nós é: %d\n", x);

    preOrdem_ArvBin(raiz);

    emOrdem_ArvBin(raiz);

    posOrdem_ArvBin(raiz);

    libera_ArvBin(raiz);

    return 0;
}