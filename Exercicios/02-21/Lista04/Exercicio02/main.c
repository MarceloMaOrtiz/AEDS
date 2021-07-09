// Escreva um procedimento na Linguagem C para trocar de posição os elementos de índice i e j de uma lista
// implementada por vetores. Faça um pequeno programa para testar seu procedimento.

#include "stdlib.h"
#include "stdio.h"
#include "Lista.h"

int main(){
    Lista *lista;
    lista = cria_lista();
    struct dado d1, d2, d3;
    d1.num = 1;
    d2.num = 2;
    d3.num = 3;
    insere_lista(lista, d1);
    insere_lista(lista, d2);
    insere_lista(lista, d3);
    imprime_lista(lista);
    troca_elementos(lista, 0, 1);
    imprime_lista(lista);
    libera_lista(lista);
    return 0;
}