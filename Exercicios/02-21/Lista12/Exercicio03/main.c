// Escreva uma função que recebe como parâmetro uma árvore binária e retorna “verdadeiro” se ela for uma
// árvore binária de busca e “falso” caso contrário. Faça um pequeno programa em C para testar sua função.

#include "stdio.h"
#include "stdlib.h"
#include "Arvore.h"

int main(){
    ArvBin *raiz_binaria;
    raiz_binaria = criar();

    int teste;

    inserir(raiz_binaria, 770);
    inserir(raiz_binaria, 875);
    inserir(raiz_binaria, 7);
    inserir(raiz_binaria, 59);
    inserir(raiz_binaria, 68);
    inserir(raiz_binaria, 682);
    inserir(raiz_binaria, 588);
    inserir(raiz_binaria, 67);
    inserir(raiz_binaria, 234);
    inserir(raiz_binaria, 411);
    inserir(raiz_binaria, 191);
    inserir(raiz_binaria, 512);

    teste = eh_binaria_busca(*raiz_binaria, NULL, NULL);

    printf("\n### Arvore Binaria de Busca ###");

    if(teste)
        printf("\n\nEh uma arvore de busca binaria\n\n");
    else
        printf("\n\nNao eh uma arvore de busca binaria\n\n");

    liberar(raiz_binaria);
    return 0;
}