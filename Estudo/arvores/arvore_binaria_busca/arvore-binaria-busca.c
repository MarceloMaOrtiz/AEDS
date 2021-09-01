#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria_busca.h"

int main(){

    ArvBin* raiz;

    int teste;
    
    teste = remove_ArvBin(raiz, 10);
    printf("Teste Remoção Árvore Não Criada: %d\n", teste);

    raiz = cria_ArvBin();

    teste = remove_ArvBin(raiz, 10);
    printf("Teste Remoção Árvore Vazia: %d\n", teste);

    teste = insere_ArvBin(raiz, 10);
    printf("Teste: %d\n", teste);
    teste = insere_ArvBin(raiz, 15);
    printf("Teste: %d\n", teste);
    teste = insere_ArvBin(raiz, 18);
    printf("Teste: %d\n", teste);
    teste = insere_ArvBin(raiz, 11);
    printf("Teste: %d\n", teste);
    teste = insere_ArvBin(raiz, 13);
    printf("Teste: %d\n", teste);
    teste = insere_ArvBin(raiz, 13);
    printf("Teste (valor existente): %d\n", teste);
    teste = insere_ArvBin(raiz, 7);
    printf("Teste: %d\n", teste);
    teste = insere_ArvBin(raiz, 3);
    printf("Teste: %d\n", teste);
    teste = insere_ArvBin(raiz, 4);
    printf("Teste: %d\n", teste);
    teste = insere_ArvBin(raiz, 9);
    printf("Teste: %d\n", teste);

    teste = consulta_ArvBin(raiz, 7);
    printf("Valor encontrado: %d\n", teste);
    teste = consulta_ArvBin(raiz, -15);
    printf("Valor encontrado: %d\n", teste);
    teste = consulta_ArvBin(raiz, 18);
    printf("Valor encontrado: %d\n", teste);

    teste = remove_ArvBin(raiz, 13);
    printf("Teste Remoção: %d\n", teste);
    teste = remove_ArvBin(raiz, 15);
    printf("Teste Remoção: %d\n", teste);
    teste = remove_ArvBin(raiz, 4);
    printf("Teste Remoção: %d\n", teste);
    teste = remove_ArvBin(raiz, 4);
    printf("Teste Remoção: %d\n", teste);
    teste = remove_ArvBin(raiz, -14);
    printf("Teste Remoção: %d\n", teste);

    libera_ArvBin(raiz);

    return 0;
}