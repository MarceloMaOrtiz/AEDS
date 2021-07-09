// Desenvolva uma função para testar se duas pilhas P1 e P2 são iguais.

#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

int main(){
    Pilha *pilha1 = cria_pilha();
    Pilha *pilha2 = cria_pilha();
    int x;
    for(int i = 0; i < 20; i++){
        insere_pilha(pilha1, (float)(i*2));
        insere_pilha(pilha2, (float)(i*2));
    }
    x = iguais(pilha1, pilha2);
    printf("\nIguais: %d\n", x);
    libera_pilha(pilha1);
    libera_pilha(pilha2);
    return 0;
}