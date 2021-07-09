// Se uma fila representada por arranjos (vetores) não é considerada circular, sugere-se que cada operação
// Desenfileira deve deslocar para “frente” todo elemento restante de uma fila. Um método alternativo é adiar
// o deslocamento até que “tras” seja igual ao último índice do vetor. Quando essa situação ocorre e faz-se uma
// tentativa de inserir um elemento na fila, a fila inteira é deslocada para “frente”, de modo que o primeiro
// elemento da fila fique na primeira posição do vetor (ou seja, na posição 0, caso a implementação seja em C).
// Quais são as vantagens desse método sobre um deslocamento em cada operação Desenfileira? Quais as
// desvantagens? Reescreva as funções Desenfileira, Enfileira e Vazia vistas em aula usando esse novo
// método.

// Vantagem:
//  - A principal vantagem está no processamento, já que desse forma será poupado diversas operações
//      antes de ser realmente necessário fazer o deslocamento
// Desvantagem:
//  - Cada operação para Desenfileirar terá um custo maior que o necessário.

#include "stdlib.h"
#include "stdio.h"
#include "Fila.h"

int main(){
    Fila *fila = cria_fila();
    int x;
    x = enfileira(fila, 1);
    x = enfileira(fila, 2);
    x = enfileira(fila, 3);
    x = enfileira(fila, 4);
    x = enfileira(fila, 5);
    x = desenfileira(fila);
    x = desenfileira(fila);
    x = desenfileira(fila);
    x = enfileira(fila, 6);
    x = enfileira(fila, 7);
    x = enfileira(fila, 8);
    libera_fila(fila);
    return 0;
}