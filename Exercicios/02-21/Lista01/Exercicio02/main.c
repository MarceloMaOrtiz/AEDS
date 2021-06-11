#include <stdlib.h>
#include <stdio.h>
#include "TConjunto.h"

int main() {
    TConjunto *tc1, *tc2, *tc3;

    tc1 = cria_conjunto(5);
    tc2 = cria_conjunto(5);

    ler_dados(tc1);
    ler_dados(tc2);

    imprimir_conjunto(tc1);
    imprimir_conjunto(tc2);

    uniao_conjuntos(tc1, tc2);

    intersecao_conjuntos(tc1, tc2);

    iguais_conjuntos(tc1, tc2);

    libera_conjunto(tc1);
    libera_conjunto(tc2);

    return 0;
}