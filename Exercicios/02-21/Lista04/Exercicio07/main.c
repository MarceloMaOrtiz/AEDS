// Considere listas implementadas por ponteiros – lista encadeada. Escreva um procedimento inssub (l1, i1,
// l2, i2, len) para inserir os elementos da lista l2, começando no elemento de índice i2 e continuando por
// len elementos na lista l1, começando na posição i1. Nenhum elemento da lista l1 deverá ser removido ou
// substituído. A lista l2 deve permanecer inalterada. Faça um pequeno programa para testar seu procedimento.

#include "stdio.h"
#include "stdlib.h"
#include "Lista.h"

int main(){
    Lista *lista1, *lista2;
    lista1 = cria_lista();
    lista2 = cria_lista();
    struct dado d1, d2, d3, d4, d5, d6;
    d1.num = 1;
    d2.num = 2;
    d3.num = 3;
    d4.num = 4;
    d5.num = 5;
    d6.num = 6;
    insere_lista(lista1, d1);
    insere_lista(lista1, d2);
    insere_lista(lista1, d3);
    insere_lista(lista2, d4);
    insere_lista(lista2, d5);
    insere_lista(lista2, d6);
    imprime_lista(lista1);
    inssub(lista1, 1, lista2, 0, 2);
    imprime_lista(lista1);
    libera_lista(lista1);
    libera_lista(lista2);
    return 0;
}