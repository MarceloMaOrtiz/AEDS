// Desenvolva um procedimento para inverter a posição dos elementos de uma pilha.

#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

int main(){
    Pilha *pilha = cria_pilha();
    for(int i = 0; i < 20; i++){
        insere_pilha(pilha, (i*2));
    }
    imprime_pilha(pilha);
    pilha = inverte(pilha);
    imprime_pilha(pilha);
    libera_pilha(pilha);
    return 0;
}