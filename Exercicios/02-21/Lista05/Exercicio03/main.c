// Implemente uma fila de inteiros em C, usando uma implementação por arranjos (um vetor queue[100]), onde
// queue[0] e queue[1] são usados para representar, respectivamente, a posição inicial e final da fila, e
// queue[2] a queue[99] são usados para armazenar os elementos do vetor. Demonstre como inicializar esse
// vetor de modo a representar a fila vazia e escreva funções Desenfileira, Enfileira e Vazia para tal
// implementação.

#include "stdlib.h"
#include "stdio.h"
#include "Fila.h"

int main() {
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