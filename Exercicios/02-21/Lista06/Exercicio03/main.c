// Escreva um algoritmo, usando Pilha, que inverte as letras de cada palavra de um texto terminado por ponto (.)
// preservando a ordem das palavras. Por exemplo, dado o texto:
// ESTE EXERCICIO E MUITO FACIL.
// A saída deve ser:
// ETSE OICICREXE E OTIUM LICAF

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Pilha.h"

int main(){
    Pilha *pilha = cria_pilha(), *pilha_final;
    char frase[50];
    printf("Insira a frase, finalizando com ponto: ");
    fgets(frase, 50, stdin);
    int x, i = 0;
    while(frase[i] != '\0'){
        x = insere_pilha(pilha, frase[i]);
        i++;
    }
    imprime_pilha(pilha);
    pilha_final = inverte_letras(pilha);
    imprime_pilha(pilha_final);
    libera_pilha(pilha);
    return 0;
}