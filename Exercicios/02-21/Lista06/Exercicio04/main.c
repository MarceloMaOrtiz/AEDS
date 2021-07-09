// Dado uma pilha que armazene números, escreva funções que forneçam o maior, o menor e a média aritmética
// dos elementos da pilha.

#include "stdio.h"
#include "stdlib.h"
#include "Pilha.h"

int main(){
    Pilha *pilha = cria_pilha();
    int x;
    float maior, menor, media;
    for(int i = 0; i < 20; i++){
        insere_pilha(pilha, (float)(i*2));
    }
    imprime_pilha(pilha);
    x = maior_menor_media(pilha, &maior, &menor, &media);
    imprime_pilha(pilha);
    printf("\nMaior: %.2f", maior);
    printf("\nMenor: %.2f", menor);
    printf("\nMedia: %.2f\n", media);
    libera_pilha(pilha);
    return 0;
}