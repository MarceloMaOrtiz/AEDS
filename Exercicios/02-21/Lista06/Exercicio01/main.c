// Utilizando as operações de manipulação de pilhas vistas em sala, uma pilha auxiliar e uma variável do tipo
// TipoItem, escreva um procedimento que remove um item com chave c de uma posição qualquer de uma pilha.
// Note que você não tem acesso à estrutura interna da pilha (topo, item, etc.), apenas às operações de
// manipulação.

#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

int main(){
    Pilha *pilha = cria_pilha();
    int x;
    struct TipoItem i1, i2, i3, i4;
    i1.chave = 'a';
    i2.chave = 'b';
    i3.chave = 'c';
    i4.chave = 'd';
    x = insere_pilha(pilha, i1);
    x = insere_pilha(pilha, i2);
    x = insere_pilha(pilha, i3);
    x = insere_pilha(pilha, i4);
    imprime_pilha(pilha);
    x = remove_item_pilha(pilha, i3);
    imprime_pilha(pilha);
    libera_pilha(pilha);
    return 0;
}