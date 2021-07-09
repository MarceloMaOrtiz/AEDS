// Existem partes de sistemas operacionais que cuidam da ordem em que os programas devem ser executados.
// Por exemplo, em um sistema de computação de tempo-compartilhado (“time-shared”) existe a necessidade de
// manter um conjunto de processos em uma fila, esperando para serem executados. Considere que cada
// processo é representado por um registro composto por um número identificador do processo (ID). Escreva um
// programa na Linguagem C que seja capaz de ler uma série de solicitações para:
// a) Incluir novos processos na fila de processos.
// b) Retirar da fila o processo com o maior tempo de espera (o primeiro a entrar na fila).
// c) Imprimir o conteúdo da lista de processo em determinado momento.
// d) Imprimir o comprimento (ou seja, o número de processos) da fila.

#include "stdio.h"
#include "stdlib.h"
#include "Fila.h"

int main(){
    Fila *fila = cria_fila();
    struct processo p1, p2, p3;
    p1.ID = 10;
    p2.ID = 20;
    p3.ID = 30;
    int x;
    x = insere_fila(fila, p1);
    x = insere_fila(fila, p2);
    x = insere_fila(fila, p3);
    imprimir_fila(fila);
    x = remove_fila(fila);
    imprimir_fila(fila);
    tamanho_fila(fila);
    libera_fila(fila);
    return 0;
}