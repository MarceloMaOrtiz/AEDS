// Escreva um procedimento na Linguagem C para trocar de posição os elementos m e n de uma lista
// implementada por ponteiros – lista encadeada (m e n podem ser chaves ou mesmo ponteiros para os
// elementos, a escolha é sua). Faça um pequeno programa para testar seu procedimento.

#include "stdio.h"
#include "stdlib.h"
#include "Lista.h"

int main(){
    Lista *lista;
    lista = cria_lista();
    struct dado d1, d2, d3, d4, d5, d6;
    d1.num = 1;
    d2.num = 2;
    d3.num = 3;
    d4.num = 4;
    d5.num = 5;
    d6.num = 6;
    insere_lista(lista, d1);
    insere_lista(lista, d2);
    insere_lista(lista, d3);
    insere_lista(lista, d4);
    insere_lista(lista, d5);
    insere_lista(lista, d6);
    imprime_lista(lista);
    troca_elementos(lista, d3, d6);
    imprime_lista(lista);
    libera_lista(lista);
    return 0;
}